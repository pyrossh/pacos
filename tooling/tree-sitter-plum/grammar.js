const PREC = {
  conditional: -1,
  parenthesized_expression: 1,
  range: 9,
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

// a == 2 ? b : c
// a ?: b


const DEC_DIGITS = token(sep1(/[0-9]+/, /_+/));
const HEX_DIGITS = token(sep1(/[0-9a-fA-F]+/, /_+/));
const BIN_DIGITS = token(sep1(/[01]/, /_+/));
const REAL_EXPONENT = token(seq(/[eE]/, optional(/[+-]/), DEC_DIGITS));

module.exports = grammar({
  name: "plum",
  extras: $ => [
    $.comment,
    /[\s\f\uFEFF\u2060\u200B]|\r?\n/,
    // $.line_continuation,
  ],
  externals: $ => [
    $._newline,
    $._indent,
    $._dedent,
    $.string_start,
    $._string_content,
    $.escape_interpolation,
    $.string_end,

    // Mark comments as external tokens so that the external scanner is always
    // invoked, even if no external token is expected. This allows for better
    // error recovery, because the external scanner can maintain the overall
    // structure by returning dedent tokens whenever a dedent occurs, even
    // if no dedent is expected.
    $.comment,

    // Allow the external scanner to check for the validity of closing brackets
    // so that it can avoid returning dedent tokens between brackets.
    ']',
    ')',
    '}',
    'except',
  ],
  conflicts: ($) => [
  ],
  inline: ($) => [$.generic_type, $.generic],
  rules: {
    source: ($) =>
      seq(
        optional(seq("module", $.module)),
        repeat($.import),
        repeat(choice($.record, $.trait, $.enum, $.fn)),
      ),

    module: ($) => $.var_identier,

    import: ($) => seq("import", $.url),
    url: () => sep1(/[a-zA-Z_][a-zA-Z_0-9]*/, "/"),

    generics: ($) => seq("(", commaSep1($.generic_type), ")"),
    generic_type: ($) =>
      seq($.generic, optional(seq(":", sep1($.type_identifier, "+")))),
    type: ($) =>
      choice(
        seq(
          $.type_identifier,
          field("generics", optional(seq("[", commaSep1($.type), "]"))),
        ),
        $.generic,
      ),
    variadic_type: ($) => seq("...", $.type),

    record: ($) =>
      seq(
        "type",
        field("name", $.type_identifier),
        field("implements", optional(seq(":", sep1($.type_identifier, "+")))),
        field("generics", optional($.generics)),
        "=",
        $._indent,
        optional(repeat($.record_field)),
        optional(repeat($.method)),
        $._dedent,
      ),

    record_field: ($) => seq(field("name", $.identifier), ":", field("type", $.type)),
    method: ($) => alias($.fn, "method"),
    trait: ($) =>
      seq(
        "trait",
        field("name", $.type_identifier),
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
        field("name", $.var_identier),
        ":",
        field("type", choice($.type, $.variadic_type)),
        optional(seq("=", field("value", $.expression))),
      ),

    return_type: ($) =>
      seq($.type_identifier, field("generics", optional($.generics))),

    enum: ($) =>
      seq(
        "enum",
        field("name", $.type_identifier),
        "=",
        $._indent,
        optional(repeat($.enum_field)),
        optional(repeat($.method)),
        $._dedent,
      ),

    enum_field: ($) =>
      seq(
        "|",
        field("name", $.type_identifier),
        field("parameters", optional(seq("(", commaSep1($.type_identifier), ")"))),
      ),

    fn: ($) =>
      seq(
        field("name", choice($.identifier, $.static_identifier)),
        field("params", seq("(", optional(commaSep1($.param)), ")")),
        field("returns", optional(seq("->", $.return_type))),
        field("body", seq("=", choice($.expression, $.body))),
      ),

    body: ($) => seq($._indent, repeat($._statement), $._dedent),

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
        $.todo,
        $.primary_expression
      ),

    assign: ($) =>
      prec.right(
        seq(
          field("left", commaSep1($.var_identier)),
          "=",
          field("right", $.expression),
        ),
      ),

    assert: ($) => seq("assert", $.expression),
    return: ($) => prec.left(seq("return", optional($.expression))),
    break: (_) => prec.left("break"),
    continue: (_) => prec.left("continue"),
    todo: (_) => prec.left("todo"),

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
        seq(choice($.var_identier, $.type_identifier), optional(seq(".", $.identifier))),
      ),

    static_identifier: ($) =>
      seq($.type_identifier, "::", $.fn_identifier),

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
      prec.left(
        seq(
          "match",
          commaSep1(field("subject", $.expression)), // remove comma use tuples (a, b) and match against tuples
          "is",
          repeat(field("case", $.case)),
        ),
      ),

    case: ($) => seq(commaSep1($.case_pattern), "=>", field("body", $.body)),

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
        // $.closure,
        $.primary_expression,
        $.ternary_expression,
      ),

    primary_expression: ($) =>
      choice(
        $.binary_operator,
        $.this,
        $.identifier,
        $.type_identifier,
        $.string,
        $.integer,
        $.float,
        $.unary_operator,
        $.attribute,
        $.fn_call,
        $.type_call,
        $.parenthesized_expression,
      ),

    parenthesized_expression: ($) =>
      prec(PREC.parenthesized_expression, seq("{", $.expression, "}")),

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
        // [prec.left, "..", PREC.range],
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
        "|",
        field("parameters", optional(commaSep1($.identifier))),
        "|",
        field("body", $.body),
      ),

    attribute: ($) =>
      prec(
        PREC.call,
        seq(
          field("object", $.primary_expression),
          ".",
          choice(
            $.identifier,
            $.fn_call,
          )
        ),
      ),

    fn_call: ($) =>
      prec(PREC.call, seq(
        field("function", $.identifier),
        field(
          "arguments",
          $.argument_list,
        ),
      )),

    type_call: ($) =>
      prec(PREC.call, seq(
        field("type", $.type_identifier),
        field(
          "arguments",
          $.argument_list,
        ),
      )),

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

    string: $ => seq(
      $.string_start,
      repeat(choice($.interpolation, $.string_content)),
      $.string_end,
    ),
    string_content: $ => prec.right(repeat1(
      choice(
        $.escape_interpolation,
        $.escape_sequence,
        $._not_escape_sequence,
        $._string_content,
      ))),

    interpolation: $ => seq(
      '{',
      field('expression', "abc"),
      '}',
    ),

    // _f_expression: $ => choice(
    //   $.expression,
    //   $.expression_list,
    //   $.pattern_list,
    //   $.yield,
    // ),

    escape_sequence: _ => token.immediate(prec(1, seq(
      '\\',
      choice(
        /u[a-fA-F\d]{4}/,
        /U[a-fA-F\d]{8}/,
        /x[a-fA-F\d]{2}/,
        /\d{1,3}/,
        /\r?\n/,
        /['"abfrntv\\]/,
        /N\{[^}]+\}/,
      ),
    ))),

    _not_escape_sequence: _ => token.immediate('\\'),

    float: ($) =>
      token(
        choice(
          seq(
            choice(
              seq(DEC_DIGITS, REAL_EXPONENT),
              seq(
                optional(DEC_DIGITS),
                ".",
                DEC_DIGITS,
                optional(REAL_EXPONENT),
              ),
            ),
            optional(/[fF]/),
          ),
          seq(DEC_DIGITS, /[fF]/),
        ),
      ),

    integer: ($) =>
      choice(
        token(seq(optional(/[1-9]/), DEC_DIGITS)),
        token(seq("0", /[xX]/, HEX_DIGITS)),
        token(seq("0", /[bB]/, BIN_DIGITS)),
      ),

    this: (_) => /this/,
    identifier: (_) => /[_a-z][_a-zA-Z0-9]*/,
    generic: ($) => choice($.a, $.b, $.c, $.d), // single letter
    a: (_) => token("a"),
    b: (_) => token("b"),
    c: (_) => token("c"),
    d: (_) => token("d"),
    var_identier: (_) => /[a-z]+(_[a-z0-9]+)*/, // lower snake case
    fn_identifier: (_) => /[a-z][a-zA-Z0-9]*/, // camel case
    type_identifier: (_) => /[A-Z][a-zA-Z0-9]*/, // capital case
  },
});

function commaSep1(rule) {
  return sep1(rule, ",");
}

function newlineSep1(rule) {
  return sep1(rule, $._newline);
}

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}
