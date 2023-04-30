const NEWLINE = /\r?\n/;

module.exports = grammar({
  name: "palm",
  extras: ($) => [
    NEWLINE,
    /\s/,
    $.module_comment,
    $.statement_comment,
    $.comment,
  ],
  externals: ($) => [$.quoted_content],
  rules: {
    source_file: ($) =>
      seq($.module, repeat($.import), repeat(choice($.struct, $.enum, $.function, $.const))),

    module: ($) => seq("module", field("module", $.module_name)),

    /* Comments */
    module_comment: ($) => token(seq("////", /.*/)),
    statement_comment: ($) => token(seq("///", /.*/)),
    comment: ($) => token(seq("//", /.*/)),

    /* Import _statement_seq */
    import: ($) =>
      seq(
        "import",
        field("module", $.module_name),
        optional(seq(".", field("imports", $.unqualified_imports))),
        optional(seq("as", field("alias", $.identifier)))
      ),
    module_name: ($) => seq($._name, repeat(seq("/", $._name))),
    unqualified_imports: ($) =>
      seq("{", optional(series_of($.unqualified_import, ",")), "}"),
    unqualified_import: ($) =>
      choice(
        seq(
          field("name", $.identifier),
          optional(seq("as", field("alias", $.identifier)))
        ),
        seq(
          field("name", $.type_identifier),
          optional(seq("as", field("alias", $.type_identifier)))
        )
      ),

    /* Constant _statement_seq */
    // _constant_type_annotation: ($) => seq(":", field("type", $._constant_type)),

    /* Declarations */

    struct: ($) =>
      seq(
        optional($.visibility_modifier),
        "type",
        field("name", $.type_identifier),
        field("generics", optional($.generics)),
        field("fields", seq("(", repeat($.field), ")")),
      ),

    enum: ($) =>
      seq(
        optional($.visibility_modifier),
        "type",
        field("name", $.type_identifier),
        field("generics", optional($.generics)),
        field("fields", seq(
          "{",
          repeat(
            seq(
              field("name", $.type_identifier),
              optional(seq(
                "(",
                choice(
                  series_of($.identifier, ","),
                  series_of($.field, ","),
                ),
                ")"),
              ),
            ),
          ),
          "}"
        ))
      ),

    function: ($) =>
      seq(
        optional($.visibility_modifier),
        "fn",
        field("name", $.identifier),
        field("params", seq("(", optional(series_of($.field, ",")), ")")),
        field("return", optional($.return_type)),
        field("body", seq("{", $._statement_seq, "}"))
      ),

    const: ($) => seq(
      "const",
      $.identifier,
      "=",
      field("value", $._const_expression)
    ),
    _const_expression: ($) => choice($._const_expression_unit, $._const_binary_expression),
    _const_binary_expression: ($) => arithmeticExpression($._const_expression),
    _const_expression_unit: ($) =>
      choice(
        $.string,
        $.integer,
        $.float,
        $.const_record,
        $.const_function_call,
      ),

    const_record: ($) =>
      seq(
        field("name", choice($.constructor_name, $.remote_constructor_name)),
        optional(field("arguments", $.arguments))
      ),

    const_function_call: ($) =>
      seq(
        field("function", choice($.function_name, $.remote_function_identifier)),
        field("arguments", $.const_arguments)
      ),

    const_arguments: ($) => seq("(", optional(series_of($.const_argument, ",")), ")"),
    const_argument: ($) =>
      seq(
        optional(seq(field("label", $.label), ":")),
        field("value", $._const_expression)),

    /* Expressions */

    _name_param: ($) => field("name", $.identifier),
    _statement_seq: ($) => repeat1($._statement),
    _statement: ($) => choice($._expression, $.let),
    _expression: ($) => choice($._expression_unit, $.binary_expression),
    binary_expression: ($) => arithmeticExpression($._expression),
    _expression_unit: ($) =>
      choice(
        $.string,
        $.integer,
        $.float,
        $.record,
        // $.todo,
        // $.panic,
        // $.list,
        $.identifier,
        $.anonymous_function,
        $.expression_group,
        $.if,
        $.when,
        // $.assert,
        $.negation,
        $.record_update,
        // $.field_access,
        // $.function_call
      ),
    record: ($) =>
      seq(
        field("name", $.constructor_name),
        optional(field("arguments", $.arguments))
      ),
    list: ($) =>
      seq(
        "[",
        optional(
          seq(
            $._expression,
            optional(repeat(seq(",", $._expression))),
            optional(","),
            optional(seq("..", field("spread", $._expression)))
          )
        ),
        "]"
      ),
    anonymous_function: ($) =>
      seq(
        "fn",
        field(
          "parameters",
          alias($.anonymous_function_parameters, $.function_parameters)
        ),
        optional(seq("->", field("return_type", $._type))),
        "{",
        field("body", alias($._statement_seq, $.function_body)),
        "}"
      ),
    anonymous_function_parameters: ($) =>
      seq(
        "(",
        optional(
          series_of(
            alias($.anonymous_function_parameter, $.function_parameter),
            ","
          )
        ),
        ")"
      ),

    _discard_param: ($) => field("name", $.discard),
    anonymous_function_parameter: ($) =>
      seq(
        choice($._discard_param, $._name_param),
        optional($._type_annotation)
      ),
    expression_group: ($) => seq("{", $._statement_seq, "}"),

    when: $ => seq(
      "when",
      optional($._expression),
      "{",
      repeat($.when_entry),
      "}"
    ),

    if: $ => seq(
      "if",
      $._expression,
      "{",
      repeat($._expression),
      "}"
    ),

    when_entry: $ => seq(
      choice(
        seq($._expression, repeat(seq(",", $._expression))),
        "_"
      ),
      "->",
      $._expression,
    ),

    _maybe_record_expression: ($) =>
      choice(
        $.record,
        $.identifier,
        $.function_call,
        $.expression_group,
        $.if,
        $.when,
        // $.record_update,
        $.field_access,
      ),


    _maybe_function_expression: ($) =>
      choice(
        $.identifier,
        $.anonymous_function,
        $.expression_group,
        $.if,
        $.when,
        $.field_access,
        $.function_call
      ),

    field_access: ($) =>
      prec.left(
        seq(
          field("record", $._maybe_record_expression),
          ".",
          field("field", $.label)
        )
      ),

    arguments: ($) => seq("(", optional(series_of($.argument, ",")), ")"),
    argument: ($) =>
      seq(
        optional(seq(field("label", $.label), ":")),
        field("value", choice($.hole, $._expression))
      ),
    hole: ($) => $._discard_name,

    function_call: ($) =>
      seq(
        field("function", $._maybe_function_expression),
        field("arguments", $.arguments)
      ),

    negation: ($) => seq("!", $._expression_unit),
    let: ($) => seq("let", $._assignment),
    _assignment: ($) =>
      seq(
        field("pattern", $._pattern_expression),
        "=",
        field("value", $._expression)
      ),

    record_update: ($) =>
      seq(
        field(
          "constructor", $.constructor_name
        ),
        "(",
        "..",
        field("spread", $._expression),
        ",",
        field("arguments", $.record_update_arguments),
        ")"
      ),
    record_update_arguments: ($) => series_of($.record_update_argument, ","),
    record_update_argument: ($) =>
      seq(field("label", $.label), ":", field("value", $._expression)),

    _pattern_expression: ($) =>
      choice(
        $.identifier,
        $.discard,
        $.record_pattern,
        $.string,
        $.integer,
        $.float,
      ),

    record_pattern: ($) =>
      seq(
        field("name", $.constructor_name),
        optional(field("arguments", $.record_pattern_arguments))
      ),
    record_pattern_arguments: ($) =>
      seq(
        "(",
        optional(series_of($.record_pattern_argument, ",")),
        optional($.pattern_spread),
        ")"
      ),
    record_pattern_argument: ($) =>
      seq(
        optional(seq(field("label", $.label), ":")),
        field("pattern", $._pattern_expression)
      ),
    pattern_spread: ($) => seq("..", optional(",")),

    /* Types */
    field: ($) =>
      seq(field("name", $.identifier), ":", field("type", $._type)),

    function_type: ($) =>
      seq(
        "fn",
        optional(field("parameter_types", $.function_parameter_types)),
        optional($.return_type),
      ),
    function_parameter_types: ($) =>
      seq("(", optional(series_of($._type, ",")), ")"),

    type: ($) =>
      seq(
        field("name", $.type_identifier),
        optional(field("arguments", $.type_arguments))
      ),
    type_arguments: ($) =>
      seq("(", optional(series_of($.type_argument, ",")), ")"),
    type_argument: ($) => $._type,

    return_type: ($) => seq("->", field("return_type", $._type)),

    generics: ($) => seq("(", series_of($.generic, ","), ")"),
    generic: ($) => /[a-z][a-z]*/,
    visibility_modifier: ($) => "pub",

    /* Literals */
    float: ($) => /-?[0-9]+\.[0-9]*/,
    integer: ($) =>
      seq(optional("-"), choice($._hex, $._decimal, $._octal, $._binary)),
    string: ($) =>
      seq(
        `"`,
        repeat(choice($.escape_sequence, $.quoted_content)),
        token.immediate(`"`)
      ),
    _hex: ($) => /0[xX][0-9a-fA-F_]+/,
    _decimal: ($) => /[0-9][0-9_]*/,
    _octal: ($) => /0[oO][0-7_]+/,
    _binary: ($) => /0[bB][0-1_]+/,
    _interpolation: ($) => choice(seq("{", $.identifier, "}")),
    escape_sequence: ($) => token.immediate(/\\[efnrt\"\\]/),
    // identifier: ($) => $._name,
    identifier: ($) => /[_a-z][_0-9a-z]*/,
    label: ($) => $._name,
    discard: ($) => $._discard_name,
    type_identifier: ($) => $._upname,
    constructor_name: ($) => $._upname,
    function_name: ($) => $._name,
    remote_function_identifier: ($) =>
      seq(field("module", $.identifier), ".", field("name", $.identifier)),
    remote_constructor_name: ($) =>
      seq(field("module", $.identifier), ".", field("name", $.type_identifier)),
    _type_annotation: ($) => seq(":", field("type", $._type)),
    _type: ($) =>
      choice($.type, $.generic, $.function_type),


    _discard_name: ($) => /_[_0-9a-z]*/,
    _name: ($) => /[_a-z][_0-9a-z]*/,
    _upname: ($) => /[A-Z][0-9a-zA-Z]*/,
  },
});

function series_of(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)), optional(separator));
}

function arithmeticExpression(exprType) {
  return choice(
    binaryExpr(prec.left, 1, "||", exprType),
    binaryExpr(prec.left, 2, "&&", exprType),
    binaryExpr(prec.left, 3, "==", exprType),
    binaryExpr(prec.left, 3, "!=", exprType),
    binaryExpr(prec.left, 4, "<", exprType),
    binaryExpr(prec.left, 4, "<=", exprType),
    binaryExpr(prec.left, 4, ">", exprType),
    binaryExpr(prec.left, 4, ">=", exprType),
    binaryExpr(prec.left, 5, "|>", exprType),
    binaryExpr(prec.left, 6, "+", exprType),
    binaryExpr(prec.left, 6, "-", exprType),
    binaryExpr(prec.left, 7, "*", exprType),
    binaryExpr(prec.left, 7, "/", exprType),
    binaryExpr(prec.left, 7, "%", exprType),
    binaryExpr(prec.left, 7, "<>", exprType)
  )
}

function binaryExpr(assoc, precedence, operator, expr) {
  return assoc(
    precedence,
    seq(field("left", expr), field("operator", operator), field("right", expr))
  );
}
