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
  call: 22,
};

module.exports = grammar({
  name: "kestrel",

  extras: ($) => [
    $.comment,
    /[\s\f\uFEFF\u2060\u200B]|\r?\n/,
    $.line_continuation,
  ],

  conflicts: ($) => [
    [$.primary_expression, $.pattern],
    [$.type_alias_statement, $.primary_expression],
  ],

  supertypes: ($) => [
    $._simple_statement,
    $._compound_statement,
    $.expression,
    $.primary_expression,
    $.pattern,
  ],

  externals: ($) => [
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
    "]",
    ")",
    "}",
    "except",
  ],

  inline: ($) => [
    $._simple_statement,
    $._compound_statement,
    $._suite,
    $._expressions,
  ],

  rules: {
    source: ($) =>
      seq(
        optional(seq("module", $.module)),
        repeat($.import),
        repeat($.const),
        repeat(choice($.record, $.trait, $.enum, $.fn, $.test))
      ),

    module: ($) => $.identifier,

    import: ($) => seq("import", $.url),
    url: ($) => sep1(/[a-zA-Z_][a-zA-Z_0-9]*/, "/"),

    const: ($) =>
      seq(
        "const",
        field("name", $.constname),
        "=",
        field("value", $.primary_expression)
      ),

    generics: ($) => seq("[", commaSep1($.generic_type), "]"),
    generic_type: ($) =>
      seq(
        $.genericname,
        optional(seq(":", sep1($.typename, choice("&", "|"))))
      ),
    type: ($) => seq($.typename, field("generics", optional($.generics))),

    record: ($) =>
      seq(
        optional(repeat($.doc_comment)),
        "record",
        field("name", $.typename),
        field("generics", optional($.generics)),
        field("fields", seq("(", commaSep1($.record_field), ")"))
      ),

    record_field: ($) =>
      seq(field("name", $.identifier), ":", field("type", $.type)),

    trait: ($) =>
      seq(
        optional(repeat($.doc_comment)),
        "trait",
        field("name", $.typename),
        field("generics", optional($.generics)),
        field("fields", seq("(", repeat($.trait_field), ")"))
      ),

    trait_field: ($) =>
      seq(
        "fn",
        field("name", $.identifier),
        field("params", seq("(", optional(commaSep1($.param)), ")")),
        ":",
        field("returns", optional($.return_type))
      ),

    param: ($) =>
      seq(
        field("name", $.identifier),
        ":",
        field("type", $.type),
        optional(seq("=", field("value", $.expression)))
      ),

    return_type: ($) =>
      seq(
        $.typename,
        field("generics", optional($.generics)),
        field("nilable", optional($.nilable)),
        field("throwable", optional($.throwable))
      ),

    enum: ($) =>
      seq(
        optional(repeat($.doc_comment)),
        "enum",
        field("name", $.typename),
        "=",
        field("fields", repeat($.enum_field))
      ),

    enum_field: ($) =>
      seq("|", field("name", $.identifier), "(", commaSep1($.identifier), ")"),

    fn: ($) =>
      seq(
        optional($.decorator),
        "fn",
        field("name", choice($.fnname, $._extension)),
        field("generics", optional($.generics)),
        field("params", seq("(", optional(commaSep1($.param)), ")")),
        ":",
        field("returns", optional($.return_type)),
        "=",
        $.body
      ),

    decorator: ($) => seq("#", "[", $.expression, "]", $._newline),

    body: ($) =>
      seq($._indent, optional($.doc_comment), repeat($._statement), $._dedent),

    test: ($) => seq("test", "(", $.string, ")", $.lambda),

    _statement: ($) => choice($._simple_statement, $._compound_statement),

    _simple_statement: ($) =>
      choice(
        $.pass_statement,
        $.assignment_statement,
        $.break_statement,
        $.continue_statement,
        $.assert_statement
        // $.expression_statement,
        // $.return_statement,
        // $.raise_statement,
      ),

    assignment_statement: ($) =>
      seq(
        field("left", commaSep1($.identifier)),
        seq(
          field(
            "operator",
            choice(
              ":=",
              "+=",
              "-=",
              "*=",
              "/=",
              "%=",
              ">>=",
              "<<=",
              "&=",
              "^=",
              "|="
            )
          ),
          field("right", commaSep1($.primary_expression))
        )
      ),

    assert_statement: ($) => seq("assert", commaSep1($.expression)),

    expression_statement: ($) =>
      choice($.expression, seq(commaSep1($.expression), optional(","))),

    return_statement: ($) => seq("return", optional($._expressions)),

    _expressions: ($) => choice($.expression, $.expression_list),

    raise_statement: ($) =>
      seq(
        "raise",
        optional($._expressions),
        optional(seq("from", field("cause", $.expression)))
      ),

    pass_statement: (_) => prec.left("pass"),
    break_statement: (_) => prec.left("break"),
    continue_statement: (_) => prec.left("continue"),

    // Compound statements
    _compound_statement: ($) =>
      choice(
        $.for_statement,
        $.while_statement,
        $.if_statement
        // $.match_statement
      ),

    if_statement: ($) =>
      seq(
        "if",
        field("condition", $.expression),
        field("consequence", $._suite),
        repeat(field("alternative", $.else_if_clause)),
        optional(field("alternative", $.else_clause))
      ),

    else_if_clause: ($) =>
      seq(
        "else if",
        field("condition", $.expression),
        field("consequence", $._suite)
      ),

    else_clause: ($) => seq("else", field("body", $._suite)),

    match_statement: ($) =>
      seq(
        "match",
        commaSep1(field("subject", $.expression)),
        field("body", alias($._match_block, $.block))
      ),

    _match_block: ($) =>
      choice(
        seq($._indent, repeat(field("alternative", $.case_clause)), $._dedent),
        $._newline
      ),

    case_clause: ($) =>
      seq(
        "case",
        commaSep1($.case_pattern),
        optional(","),
        optional(field("guard", $.if_clause)),
        ":",
        field("consequence", $._suite)
      ),

    reference: ($) =>
      prec(PREC.call, seq($.identifier, optional(seq(".", $.identifier)))),

    for_statement: ($) =>
      seq(
        "for",
        field("left", commaSep1($.identifier)),
        ":=",
        "range",
        field("right", $.primary_expression),
        field("body", $.body)
      ),

    while_statement: ($) =>
      seq("while", field("condition", $.expression), field("body", $._suite)),

    type_alias_statement: ($) =>
      prec.dynamic(1, seq("type", $.type, "=", $.type)),

    _suite: ($) => choice(seq($._indent, $.block), alias($._newline, $.block)),

    block: ($) => seq(repeat($._statement), $._dedent),

    expression_list: ($) =>
      prec.right(
        seq(
          $.expression,
          choice(",", seq(repeat1(seq(",", $.expression)), optional(",")))
        )
      ),

    dotted_name: ($) => prec(1, sep1($.identifier, ".")),

    // Match cases

    case_pattern: ($) => prec(1, choice($._simple_pattern)),

    _simple_pattern: ($) =>
      prec(
        1,
        choice(
          $.class_pattern,
          $.string,
          $.true,
          $.false,
          $.nil,
          seq(optional("-"), choice($.integer, $.float)),
          $.complex_pattern,
          $.dotted_name,
          "_"
        )
      ),

    class_pattern: ($) =>
      seq(
        $.dotted_name,
        "(",
        optional(seq(commaSep1($.case_pattern), optional(","))),
        ")"
      ),

    complex_pattern: ($) =>
      prec(
        1,
        seq(
          optional("-"),
          choice($.integer, $.float),
          choice("+", "-"),
          choice($.integer, $.float)
        )
      ),

    // Patterns
    pattern: ($) => choice($.identifier, $.attribute),

    // Extended patterns (patterns allowed in match statement are far more flexible than simple patterns though still a subset of "expression")

    expression: ($) =>
      choice(
        $.comparison_operator,
        $.not_operator,
        $.boolean_operator,
        $.lambda,
        $.primary_expression,
        $.ternary_expression
      ),

    primary_expression: ($) =>
      choice(
        $.binary_operator,
        $.identifier,
        $.string,
        $.integer,
        $.float,
        $.true,
        $.false,
        $.nil,
        $.unary_operator,
        $.attribute,
        $.call,
        $.parenthesized_expression
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
            field("right", $.expression)
          )
        ),
        prec.left(
          PREC.or,
          seq(
            field("left", $.expression),
            field("operator", "||"),
            field("right", $.expression)
          )
        )
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
        ...table.map(([fn, operator, precedence]) =>
          fn(
            precedence,
            seq(
              field("left", $.primary_expression),
              // @ts-ignore
              field("operator", operator),
              field("right", $.primary_expression)
            )
          )
        )
      );
    },

    unary_operator: ($) =>
      prec(
        PREC.unary,
        seq(
          field("operator", choice("+", "-")),
          field("argument", $.primary_expression)
        )
      ),

    comparison_operator: ($) =>
      prec.left(
        PREC.compare,
        seq(
          $.primary_expression,
          repeat1(
            seq(
              field(
                "operators",
                choice("<", "<=", "==", "!=", ">=", ">", "<>")
              ),
              $.primary_expression
            )
          )
        )
      ),

    lambda: ($) =>
      seq(
        "|",
        field("parameters", optional(commaSep1($.identifier))),
        "|",
        field("body", $.body)
      ),

    attribute: ($) =>
      prec(
        PREC.call,
        seq(
          field("object", $.primary_expression),
          ".",
          field("attribute", $.identifier)
        )
      ),

    call: ($) =>
      prec(
        PREC.call,
        seq(field("function", $.reference), field("arguments", $.argument_list))
      ),

    argument_list: ($) =>
      seq(
        "(",
        optional(
          commaSep1(choice($.expression, $.keyword_argument, $.pair_argument))
        ),
        optional(","),
        ")"
      ),

    keyword_argument: ($) =>
      seq(field("name", $.identifier), ":", field("value", $.expression)),

    pair_argument: ($) =>
      seq(field("name", $.string), "=>", field("value", $.expression)),

    if_clause: ($) => seq("if", $.expression),

    ternary_expression: ($) =>
      prec.right(
        PREC.conditional,
        seq($.expression, "?", $.expression, ":", $.expression)
      ),

    string: ($) => seq($.string_start, repeat($._string_content), $.string_end),

    string_content: ($) =>
      prec.right(
        repeat1(
          choice(
            $.escape_interpolation,
            $.escape_sequence,
            $._not_escape_sequence,
            $._string_content
          )
        )
      ),

    interpolation: ($) =>
      seq(
        "{",
        field("expression", $._f_expression),
        optional("="),
        optional(field("type_conversion", $.type_conversion)),
        optional(field("format_specifier", $.format_specifier)),
        "}"
      ),

    _f_expression: ($) => choice($.expression, $.expression_list),

    escape_sequence: (_) =>
      token.immediate(
        prec(
          1,
          seq(
            "\\",
            choice(
              /u[a-fA-F\d]{4}/,
              /U[a-fA-F\d]{8}/,
              /x[a-fA-F\d]{2}/,
              /\d{3}/,
              /\r?\n/,
              /['"abfrntv\\]/,
              /N\{[^}]+\}/
            )
          )
        )
      ),

    _not_escape_sequence: (_) => token.immediate("\\"),

    format_specifier: ($) =>
      seq(
        ":",
        repeat(
          choice(
            token(prec(1, /[^{}\n]+/)),
            alias($.interpolation, $.format_expression)
          )
        )
      ),

    type_conversion: (_) => /![a-z]/,

    float: ($) => /-?[0-9_]+\.[0-9_]*(e-?[0-9_]+)?(f)?/,
    integer: ($) => choice($._hex, $._decimal, $._binary),
    _hex: ($) => /0x[0-9a-fA-F_]+/,
    _decimal: ($) => /[0-9][0-9_]*(i)?/,
    _binary: ($) => /0b[0-1_]+/,

    identifier: (_) => /[_a-z][_0-9a-z]*/, // snake_case
    fnname: (_) =>
      /[a-z][a-z]*(([A-Z][a-z]+)*[A-Z]?|([a-z]+[A-Z])*|[A-Z])/, // lowerCamelCase no digits
    constname: (_) => /[_A-Z0-9]+/, // screaming camel case
    genericname: (_) => /[A-Z]/, // single letter
    typename: (_) => /[_a-zA-Z][_a-zA-Z]*/, // upperCamelCase no digits

    _interpolation: ($) => choice(seq("{", $.identifier, "}")),
    _extension: ($) => seq($.typename, ".", $.fnname),

    true: (_) => "true",
    false: (_) => "false",
    nil: (_) => "nil",
    nilable: () => "?",
    throwable: () => "!",

    comment: (_) => token(seq("//", /.*/)),
    doc_comment: (_) => token(seq("`", /.*/)),

    line_continuation: (_) =>
      token(seq("\\", choice(seq(optional("\r"), "\n"), "\0"))),
  },
});

module.exports.PREC = PREC;

function commaSep1(rule) {
  return sep1(rule, ",");
}

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}
