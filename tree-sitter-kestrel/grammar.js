const PREC = {
  conditional: -1,
  parenthesized_expression: 1,
  or: 10,
  and: 11,
  not: 12,
  compare: 13,
  bitwise_or: 14,
  bitwise_and: 15,
  xor: 16,
  shift: 17,
  plus: 18,
  times: 19,
  unary: 20,
  power: 21,
  constructor: 22,
  call: 23,
};

const DEC_DIGITS = token(sep1(/[0-9]+/, /_+/));
const HEX_DIGITS = token(sep1(/[0-9a-fA-F]+/, /_+/));
const BIN_DIGITS = token(sep1(/[01]/, /_+/));
const REAL_EXPONENT = token(seq(/[eE]/, optional(/[+-]/), DEC_DIGITS));

module.exports = grammar({
  name: "kestrel",
  extras: ($) => [$.comment, /\s+/],
  externals: ($) => [$.quoted_content],
  conflicts: ($) => [[$.closure, $.primary_expression]],
  // inline: ($) => [$.expression],
  rules: {
    source: ($) =>
      seq(
        optional(seq("module", $.module)),
        repeat($.import),
        repeat(choice($.assign, $.record, $.object, $.trait, $.enum, $.fn)),
      ),

    module: ($) => $.identifier,

    import: ($) => seq("import", $.url),
    url: ($) => sep1(/[a-zA-Z_][a-zA-Z_0-9]*/, "/"),

    generics: ($) => seq("<", commaSep1($.generic_type), ">"),
    generic_type: ($) =>
      seq($.genericname, optional(seq(":", sep1($.typename, "+")))),
    type: ($) =>
      seq(
        $.typename,
        field("generics", optional(seq("<", commaSep1($.typename), ">"))),
      ),

    record: ($) =>
      seq(
        optional(repeat($.doc_comment)),
        "record",
        field("name", $.typename),
        field("generics", optional($.generics)),
        field("fields", seq("(", commaSep1($.record_field), ")")),
        field("implements", optional(seq(":", commaSep1($.typename)))),
        field("body", optional(seq("{", repeat($.fn), "}"))),
      ),

    record_field: ($) =>
      seq(field("name", $.identifier), ":", field("type", $.type)),

    object: $ => seq(
      "object",
      field("name", $.typename),
      field("implements", optional(seq(":", commaSep1($.typename)))),
      field("body", optional(seq("{", repeat($.fn), "}"))),
    ),

    trait: ($) =>
      seq(
        optional(repeat($.doc_comment)),
        "trait",
        field("name", $.typename),
        field("generics", optional($.generics)),
        field("fields", seq("{", repeat($.trait_field), "}")),
      ),

    trait_field: ($) =>
      seq(
        "fn",
        field("name", $.identifier),
        field("params", seq("(", optional(commaSep1($.param)), ")")),
        ":",
        field("returns", optional($.return_type)),
      ),

    param: ($) =>
      seq(
        field("name", $.identifier),
        ":",
        field("type", $.type),
        optional(seq("=", field("value", $.expression))),
      ),

    return_type: ($) =>
      seq($.typename, field("generics", optional($.generics))),

    enum: ($) =>
      seq(
        optional(repeat($.doc_comment)),
        "enum",
        field("name", $.typename),
        "{",
        field("fields", repeat($.enum_field)),
        "}",
      ),

    enum_field: ($) =>
      seq(field("name", $.typename), "(", commaSep1($.typename), ")"),

    fn: ($) =>
      seq(
        optional($.doc_comment),
        optional($.decorator),
        field("modifier", optional($.fn_modifier)),
        "fn",
        field("name", $.fnname),
        field("generics", optional($.generics)),
        field("params", seq("(", optional(commaSep1($.param)), ")")),
        field("returns", optional(seq(":", $.return_type))),
        field("body", choice($.body, seq("=", $.expression))),
      ),

    decorator: ($) =>
      seq(
        "@",
        field("function", $.reference),
        field("arguments", $.argument_list),
      ),

    fn_modifier: ($) => choice("operator", "static", "override"),

    body: ($) => seq("{", repeat($._statement), "}"),

    _statement: ($) =>
      choice(
        $.assign,
        $.break,
        $.continue,
        $.assert,
        $.for,
        $.while,
        $.if,
        $.match,
        $.return,
      ),

    assign: ($) =>
      seq(
        choice("val", "var"),
        field("left", commaSep1($.identifier)),
        "=",
        field("right", $.expression),
      ),

    assert: ($) => seq("assert", commaSep1($.expression)),
    return: ($) => seq("return", optional($.expression)),
    break: (_) => prec.left("break"),
    continue: (_) => prec.left("continue"),

    if: ($) =>
      seq(
        "if",
        field("condition", $.expression),
        field("body", $.body),
        repeat(field("alternative", $.else_if)),
        optional(field("alternative", $.else)),
      ),

    else_if: ($) =>
      seq("else if", field("condition", $.expression), field("body", $.body)),

    else: ($) => seq("else", field("body", $.body)),

    reference: ($) =>
      prec(
        PREC.call,
        seq(choice($.identifier, $.typename), optional(seq(".", $.identifier))),
      ),

    for: ($) =>
      seq(
        "for",
        field("left", commaSep1($.identifier)),
        "in",
        field("right", $.primary_expression),
        field("body", $.body),
      ),

    while: ($) =>
      seq("while", field("condition", $.expression), field("body", $.body)),

    dotted_name: ($) => prec(1, sep1($.identifier, ".")),

    // Match cases
    match: ($) =>
      seq(
        "match",
        commaSep1(field("subject", $.expression)), // remove comma use tuples (a, b) and match against tuples
        "{",
        repeat(field("case", $.case)),
        "}",
      ),

    case: ($) => seq(commaSep1($.case_pattern), "->", field("body", $.body)),

    case_pattern: ($) =>
      prec(
        1,
        choice(
          $.class_pattern,
          $.string,
          $.integer,
          $.float,
          $.dotted_name,
          "_",
        ),
      ),

    class_pattern: ($) =>
      seq(
        $.dotted_name,
        "(",
        optional(seq(commaSep1($.case_pattern), optional(","))),
        ")",
      ),

    expression: ($) =>
      choice(
        $.comparison_operator,
        $.not_operator,
        $.boolean_operator,
        $.closure,
        $.primary_expression,
        $.ternary_expression,
      ),

      // a == 2 ? b : c
      // a ?: b 

    primary_expression: ($) =>
      choice(
        $.binary_operator,
        $.self,
        $.identifier,
        $.typename,
        $.string,
        $.integer,
        $.float,
        $.unary_operator,
        // $.reference,
        $.attribute,
        $.call,
        $.parenthesized_expression,
      ),

    parenthesized_expression: ($) =>
      prec(PREC.parenthesized_expression, seq("(", $.expression, ")")),

    not_operator: ($) =>
      prec(PREC.not, seq("!", field("argument", $.expression))),

    boolean_operator: ($) =>
      choice(
        prec.left(
          PREC.and,
          seq(
            field("left", $.expression),
            field("operator", "&&"),
            field("right", $.expression),
          ),
        ),
        prec.left(
          PREC.or,
          seq(
            field("left", $.expression),
            field("operator", "||"),
            field("right", $.expression),
          ),
        ),
      ),

    binary_operator: ($) => {
      const table = [
        [prec.left, "+", PREC.plus],
        [prec.left, "-", PREC.plus],
        [prec.left, "*", PREC.times],
        [prec.left, "/", PREC.times],
        [prec.left, "%", PREC.times],
        [prec.left, "|", PREC.bitwise_or],
        [prec.left, "&", PREC.bitwise_and],
        [prec.left, "^", PREC.xor],
        [prec.left, "<<", PREC.shift],
        [prec.left, ">>", PREC.shift],
      ];

      // @ts-ignore
      return choice(
        ...table.map(([cb, operator, precedence]) =>
          cb(
            precedence,
            seq(
              field("left", $.primary_expression),
              field("operator", operator),
              field("right", $.primary_expression),
            ),
          ),
        ),
      );
    },

    unary_operator: ($) =>
      prec(
        PREC.unary,
        seq(
          field("operator", choice("+", "-")),
          field("argument", $.primary_expression),
        ),
      ),

    comparison_operator: ($) =>
      prec.left(
        PREC.compare,
        seq(
          $.primary_expression,
          field("operator", choice("<", "<=", "==", "!=", ">=", ">", "<>")),
          $.primary_expression,
        ),
      ),

    closure: ($) =>
      seq(
        field("parameters", optional(commaSep1($.identifier))),
        "->",
        field("body", $.body),
      ),

    attribute: ($) =>
      prec(
        PREC.call,
        seq(
          field("object", $.primary_expression),
          ".",
          field("attribute", $.identifier),
        ),
      ),

    call: ($) =>
      prec(
        PREC.call,
        seq(
          field("function", $.reference),
          field("arguments", $.argument_list),
        ),
      ),

    argument_list: ($) =>
      seq(
        "(",
        optional(
          commaSep1(choice($.expression, $.keyword_argument, $.pair_argument)),
        ),
        optional(","),
        ")",
      ),

    keyword_argument: ($) =>
      seq(field("name", $.identifier), "=", field("value", $.expression)),

    pair_argument: ($) =>
      seq(field("name", $.string), "=>", field("value", $.expression)),

    ternary_expression: ($) =>
      prec.right(
        PREC.conditional,
        seq($.expression, "?", $.expression, ":", $.expression),
      ),

    // ==========
    // Literals
    // ==========
    integer_literal: $ => token(seq(optional(/[1-9]/), DEC_DIGITS)),
    hex_literal: $ => token(seq("0", /[xX]/, HEX_DIGITS)),
    bin_literal: $ => token(seq("0", /[bB]/, BIN_DIGITS)),

    _interpolation: $ => choice(
      seq("${", $.expression, "}"),
    ),

    string: ($) =>
      seq(
        '"',
        repeat(choice($.escape_sequence, $.quoted_content)),
        token.immediate('"'),
      ),
    escape_sequence: ($) =>
      choice(
        token.immediate(/\\[efnrt\"\\]/),
        token.immediate(/\\u\{[0-9a-fA-F]{1,6}\}/),
      ),
    float: ($) => /-?[0-9_]+\.[0-9_]*(e-?[0-9_]+)?(f)?/,
    integer: ($) => choice($._hex, $._decimal, $._binary),
    _hex: ($) => /0x[0-9a-fA-F_]+/,
    _decimal: ($) => /[0-9][0-9_-]*(i)?/,
    _binary: ($) => /0b[0-1_]+/,

    self: (_) => /self/,
    identifier: (_) => /[_a-z][_a-zA-Z0-9]*/,
    fnname: (_) => /[a-z][a-z]*(([A-Z][a-z]+)*[A-Z]?|([a-z]+[A-Z])*|[A-Z])/, // lowerCamelCase no digits
    genericname: (_) => /[A-Z]/, // single letter
    typename: (_) => /[_a-zA-Z][_a-zA-Z]*/, // upperCamelCase no digits

    comment: (_) => token(seq("//", /.*/)),
    // whitespace: (_) => /\s+/,
    doc_comment: (_) => token(seq("`", /.*/)),
  },
});

function commaSep1(rule) {
  return sep1(rule, ",");
}

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}
