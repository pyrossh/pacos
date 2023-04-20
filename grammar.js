const DEC_DIGITS = token(sep1(/[0-9]+/, /_+/));
const HEX_DIGITS = token(sep1(/[0-9a-fA-F]+/, /_+/));
const BIN_DIGITS = token(sep1(/[01]/, /_+/));
const NEWLINE = /\r?\n/;

module.exports = grammar({
  name: 'palm',
  // extras: $ => [
  //   $.comment,
  //   /\s+/ // Whitespace
  // ],
  externals: ($) => [$.quoted_content],
  conflicts: $ => [
    [$.proc],
    [$.record],
  ],
  rules: {
    source_file: $ => seq(
      $.module,
      repeat($.import),
      repeat(choice(
        $.record,
        $.type,
        $.proc,
      )),
    ),

    module: $ => seq('module', field("module", $.module_name)),

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

    record: $ => seq(
      'record',
      field('name', $.type_identifier),
      field('generics', optional($.generic_list)),
      field('fields', repeat($.type_field)),
    ),

    type: $ => seq(
      'type',
      field('name', $.type_identifier),
      field('generics', optional($.generic_list)),
      "=",
      field('types', pipeSep1($.type_name)),
    ),

    proc: $ => seq(
      // 'proc',
      field('name', $.identifier),
      field('params', seq('(', optional(commaSep1($.type_field)), ')')),
      optional(
        seq(
          '->',
          field('return_type', optional($.return_type)),
        ),
      ),
      '=',
      field('body', $._statement_seq),
    ),

    /* Shared AST nodes */

    // param: $ => seq(
    //   field('name', $.variable_name),
    //   ':',
    //   field('type', $.type)
    // ),

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
        $.record,
        $.identifier,
        $.todo,
        $.panic,
        // $.anonymous_function,
        $.expression_group,
        // $.case,
        $.negation,
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


    todo: ($) =>
      seq("todo", optional(seq("(", field("message", $.string), ")"))),
    panic: (_$) => seq("panic"),

    /* Types */
    return_type: $ => seq(
      field('name', $.type_identifier),
      field("generics", optional(seq(
        "(",
        commaSep1($.identifier),
        ")",
      )))
    ),


    type_name: $ => seq(
      field('name', $.type_identifier),
      optional(seq(
        "(",
        choice(
          $.identifier,
          commaSep1($.type_field),
        ),
        ")",
      ))
    ),

    type_field: $ => seq(
      field('name', $.identifier),
      ':',
      field('type', $.identifier)
    ),

    generic_list: $ => seq(
      '(',
      commaSep1($.identifier),
      ')'
    ),

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
    _interpolation: $ => choice(
      seq("{", $.identifier, "}")
    ),
    escape_sequence: ($) => token.immediate(/\\[efnrt\"\\]/),
    // identifier: ($) => $._name,
    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    type_identifier: ($) => $._upname,
    _type_annotation: ($) => seq(":", field("type", $.identifier)),
    _discard_name: ($) => /_[_0-9a-z]*/,
    _name: ($) => /[_a-z][_0-9a-z]*/,
    _upname: ($) => /[A-Z][0-9a-zA-Z]*/,
  }
});

function commaSep1(rule) {
  return sep1(rule, ',')
}

function pipeSep1(rule) {
  return sep1(rule, '|')
}

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)))
}

function series_of(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)), optional(separator));
}

// A binary expression with a left-hand side, infix operator, and then right-hand-side
// https://github.com/elixir-lang/tree-sitter-elixir/blob/de20391afe5cb03ef1e8a8e43167e7b58cc52869/grammar.js#L850-L859
function binaryExpr(assoc, precedence, operator, expr) {
  return assoc(
    precedence,
    seq(field("left", expr), field("operator", operator), field("right", expr))
  );
}