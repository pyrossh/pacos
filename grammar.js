const NEWLINE = /\r?\n/;

module.exports = grammar({
  name: "palm",
  // extras: $ => [
  //   $.comment,
  //   /\s+/ // Whitespace
  // ],
  externals: ($) => [$.quoted_content],
  rules: {
    source_file: ($) =>
      seq($.module, repeat($.import), repeat(choice($.struct, $.enum, $.function))),

    module: ($) => seq("module", field("module", $.module_name)),

    /* Import statements */
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

    /* Constant statements */
    // _constant_type_annotation: ($) => seq(":", field("type", $._constant_type)),

    /* Declarations */

    struct: ($) =>
      seq(
        "type",
        field("name", $.type_identifier),
        field("generics", optional($.generics)),
        field("fields", seq("(", repeat($.field), ")")),
      ),

    enum: ($) =>
      seq(
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
        "fn",
        field("name", $.identifier),
        field("params", seq("(", optional(series_of($.field, ",")), ")")),
        field("return", $.return_type),
        field("body", seq("{", $._statement_seq, "}"))
      ),

    /* Expressions */

    _statement_seq: ($) => repeat1($._statement),
    _statement: ($) => choice($._expression, $.let),
    _expression: ($) => choice($._expression_unit, $.binary_expression),
    binary_expression: ($) =>
      choice(
        binaryExpr(prec.left, 1, "||", $._expression),
        binaryExpr(prec.left, 2, "&&", $._expression),
        binaryExpr(prec.left, 3, "==", $._expression),
        binaryExpr(prec.left, 3, "!=", $._expression),
        binaryExpr(prec.left, 4, "<", $._expression),
        binaryExpr(prec.left, 4, "<=", $._expression),
        binaryExpr(prec.left, 4, ">", $._expression),
        binaryExpr(prec.left, 4, ">=", $._expression),
        binaryExpr(prec.left, 5, "|>", $._expression),
        binaryExpr(prec.left, 6, "+", $._expression),
        binaryExpr(prec.left, 6, "-", $._expression),
        binaryExpr(prec.left, 7, "*", $._expression),
        binaryExpr(prec.left, 7, "/", $._expression),
        binaryExpr(prec.left, 7, "%", $._expression),
        binaryExpr(prec.left, 7, "<>", $._expression)
      ),
    _expression_unit: ($) =>
      choice(
        $.string,
        $.integer,
        $.float,
        $.identifier,
        // $.anonymous_function,
        $.expression_group,
        // $.case,
        $.negation
        // $.record_update,
        // $.field_access,
        // $.function_call
      ),
    expression_group: ($) => seq("{", $._statement_seq, "}"),
    negation: ($) => seq("!", $._expression_unit),
    let: ($) => seq("let", $._assignment),
    _assignment: ($) =>
      seq(
        field("pattern", $._pattern),
        optional($._type_annotation),
        "=",
        field("value", $._expression)
      ),
    _pattern: ($) =>
      seq(
        $._pattern_expression,
        optional(field("assign", seq("as", $.identifier)))
      ),
    _pattern_expression: ($) =>
      choice(
        $.identifier,
        // $.discard,
        // $.record_pattern,
        // $.string,
        $.integer,
        $.float,
        alias($._pattern_binary_expression, $.binary_expression)
      ),
    _pattern_binary_expression: ($) =>
      binaryExpr(prec.left, 1, "<>", $._pattern_expression),

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

    /* Literals */
    float: ($) => /-?[0-9_]+\.[0-9_]*(e-?[0-9_]+)?/,
    integer: ($) =>
      seq(optional("-"), choice($._hex, $._decimal, $._octal, $._binary)),
    string: ($) =>
      seq(
        '"',
        repeat(choice($.escape_sequence, $.quoted_content)),
        token.immediate('"')
      ),
    _hex: ($) => /0[xX][0-9a-fA-F_]+/,
    _decimal: ($) => /[0-9][0-9_]*/,
    _octal: ($) => /0[oO][0-7_]+/,
    _binary: ($) => /0[bB][0-1_]+/,
    _interpolation: ($) => choice(seq("{", $.identifier, "}")),
    escape_sequence: ($) => token.immediate(/\\[efnrt\"\\]/),
    // identifier: ($) => $._name,
    identifier: ($) => /[a-zA-Z_][a-zA-Z_0-9]*/,
    type_identifier: ($) => $._upname,
    remote_type_identifier: ($) =>
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

function binaryExpr(assoc, precedence, operator, expr) {
  return assoc(
    precedence,
    seq(field("left", expr), field("operator", operator), field("right", expr))
  );
}
