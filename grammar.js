const DEC_DIGITS = token(sep1(/[0-9]+/, /_+/));
const HEX_DIGITS = token(sep1(/[0-9a-fA-F]+/, /_+/));
const BIN_DIGITS = token(sep1(/[01]/, /_+/));

const PREC = {
  POSTFIX: 16,
  PREFIX: 15,
  TYPE_RHS: 14,
  AS: 13,
  MULTIPLICATIVE: 12,
  ADDITIVE: 11,
  RANGE: 10,
  INFIX: 9,
  ELVIS: 8,
  CHECK: 7,
  COMPARISON: 6,
  EQUALITY: 5,
  CONJUNCTION: 4,
  DISJUNCTION: 3,
  SPREAD: 2,
  SIMPLE_USER_TYPE: 2,
  VAR_DECL: 1,
  ASSIGNMENT: 1,
  BLOCK: 1,
  LAMBDA_LITERAL: 0,
  RETURN_OR_THROW: 0,
  COMMENT: 0
};

module.exports = grammar({
  name: 'pine',
  conflicts: $ => [
    [$.fun_field],
    [$.decorator_name],
  ],
  extras: $ => [
    $.comment,
    /\s+/ // Whitespace
  ],
  rules: {
    source_file: $ => seq(
      seq("package", $.package),
      repeat($.import_statement),
      repeat($.definitions),
    ),

    import_statement: $ => seq('import', $.url),

    // Definitions

    definitions: $ => choice(
      $.class_definition,
      $.trait_definition,
      $.enum_definition,
      $.fun_definition,
    ),

    class_definition: $ => seq(
      field('decorators', optional(repeat($.decorator_name))),
      'class',
      field('name', $.definition_name),
      field('generics', optional($.generic_list)),
      field('traits', optional($.trait_list)),
      field('fields', seq('(', commaSep1($.type_field), ')')),
    ),

    trait_definition: $ => seq(
      'trait',
      field('name', $.definition_name),
      field('generics', optional($.generic_list)),
      field('fields', seq('(', commaSep1($.trait_field), ')')),
    ),

    enum_definition: $ => seq(
      'enum',
      field('name', $.definition_name),
      field('types', seq('(', commaSep1($.type_field), ')')),
      field('fields', seq('{', commaSep1($.enum_field), '}')),
    ),

    fun_definition: $ => seq(
      field('decorators', optional(repeat($.decorator_name))),
      'fun',
      field('name', choice($.identifier, $._extension)),
      field('generics', optional($.generic_list)),
      field('params', seq('(', optional(commaSep1($.param)), ')')),
      '=>',
      field('returns', optional(commaSep1($.type))),
      field('body', $._block)
    ),

    decorator_name: $ => seq("@", $.identifier, '(', optional(commaSep1($._primary_expression)), ')'),

    trait_list: $ => seq(
      ':',
      commaSep1($.definition_name),
    ),

    generic_list: $ => seq(
      '<',
      commaSep1($.identifier),
      '>'
    ),

    type: $ => seq($.definition_name, optional('?')),

    param: $ => seq(
      field('name', $.variable_name),
      ':',
      field('type', $.type)
    ),

    type_field: $ => seq(
      'val',
      field('name', $.variable_name),
      ':',
      field('type', $.type)
    ),

    fun_field: $ => seq(
      'fun',
      field('name', $.identifier),
      field('params', seq('(', optional(commaSep1($.param)), ')')),
      '=>',
      field('returns', optional(commaSep1($.type))),
    ),

    trait_field: $ => choice(
      $.type_field,
      $.fun_field,
    ),

    enum_field: $ => seq($.enum_field_name, '(', commaSep1($._primary_expression), ')'),

    // Expressions

    _block: $ => prec(PREC.BLOCK, seq(
      "{",
      // optional($.statements), 
      "}"
    )),

    // statements: $ => seq(
    //   $._statement,
    // ),

    // _statement: $ => choice(
    //   choice(
    //     $.assignment,
    //     $._loop_statement,
    //     $._expression
    //   )
    // ),

    // _loop_statement: $ => choice(
    //   $.for_statement,
    //   $.while_statement,
    // ),

    // for_statement: $ => prec.right(seq(
    //   "for",
    //   "(",
    //   repeat($.annotation),
    //   choice($.variable_declaration, $.multi_variable_declaration),
    //   "in",
    //   $._expression,
    //   ")",
    //   optional($.control_structure_body)
    // )),

    // while_statement: $ => seq(
    //   "while",
    //   "(",
    //   $._expression,
    //   ")",
    //   choice(";", $.control_structure_body)
    // ),

    // assignment: $ => choice(
    //   prec.left(PREC.ASSIGNMENT, seq($.directly_assignable_expression, $._assignment_and_operator, $._expression)),
    //   prec.left(PREC.ASSIGNMENT, seq($.directly_assignable_expression, "=", $._expression)),
    //   // TODO
    // ),

    // // ==========
    // // Expressions
    // // ==========

    // _expression: $ => choice(
    //   $._unary_expression,
    //   $._binary_expression,
    //   $._primary_expression
    // ),

    // // Unary expressions

    // _unary_expression: $ => choice(
    //   $.postfix_expression,
    //   $.call_expression,
    //   $.indexing_expression,
    //   $.navigation_expression,
    //   $.prefix_expression,
    //   $.as_expression,
    //   $.spread_expression
    // ),

    // postfix_expression: $ => prec.left(PREC.POSTFIX, seq($._expression, $._postfix_unary_operator)),

    // call_expression: $ => prec.left(PREC.POSTFIX, seq($._expression, $.call_suffix)),

    // indexing_expression: $ => prec.left(PREC.POSTFIX, seq($._expression, $.indexing_suffix)),

    // navigation_expression: $ => prec.left(PREC.POSTFIX, seq($._expression, $.navigation_suffix)),

    // prefix_expression: $ => prec.right(seq(choice($.annotation, $.label, $._prefix_unary_operator), $._expression)),

    // as_expression: $ => prec.left(PREC.AS, seq($._expression, $._as_operator, $._type)),

    // spread_expression: $ => prec.left(PREC.SPREAD, seq("*", $._expression)),

    // _binary_expression: $ => choice(
    //   $.multiplicative_expression,
    //   $.additive_expression,
    //   $.range_expression,
    //   $.infix_expression,
    //   $.elvis_expression,
    //   $.check_expression,
    //   $.comparison_expression,
    //   $.equality_expression,
    //   $.comparison_expression,
    //   $.equality_expression,
    //   $.conjunction_expression,
    //   $.disjunction_expression
    // ),

    // multiplicative_expression: $ => prec.left(PREC.MULTIPLICATIVE, seq($._expression, $._multiplicative_operator, $._expression)),

    // additive_expression: $ => prec.left(PREC.ADDITIVE, seq($._expression, $._additive_operator, $._expression)),

    // range_expression: $ => prec.left(PREC.RANGE, seq($._expression, "..", $._expression)),

    // infix_expression: $ => prec.left(PREC.INFIX, seq($._expression, $.simple_identifier, $._expression)),

    // elvis_expression: $ => prec.left(PREC.ELVIS, seq($._expression, "?:", $._expression)),

    // check_expression: $ => prec.left(PREC.CHECK, seq($._expression, choice(
    //   seq($._in_operator, $._expression),
    //   seq($._is_operator, $._type)))),

    // comparison_expression: $ => prec.left(PREC.COMPARISON, seq($._expression, $._comparison_operator, $._expression)),

    // equality_expression: $ => prec.left(PREC.EQUALITY, seq($._expression, $._equality_operator, $._expression)),

    // conjunction_expression: $ => prec.left(PREC.CONJUNCTION, seq($._expression, "&&", $._expression)),

    // disjunction_expression: $ => prec.left(PREC.DISJUNCTION, seq($._expression, "||", $._expression)),

    //  // Suffixes

    // indexing_suffix: $ => seq("[", sep1($._expression, ","), "]"),

    // navigation_suffix: $ => seq(
    //    $._member_access_operator,
    //    choice(
    //      $.simple_identifier,
    //      $.parenthesized_expression,
    //      "class"
    //    )
    // ),

    // call_suffix: $ => prec.left(seq(
    //    // this introduces ambiguities with 'less than' for comparisons
    //    optional($.type_arguments),
    //    choice(
    //      seq(optional($.value_arguments), $.annotated_lambda),
    //      $.value_arguments
    //    )
    // )),

    // variable_declaration: $ => prec.left(PREC.VAR_DECL, seq(
    //   // repeat($.annotation), TODO
    //   $.simple_identifier,
    //   optional(seq(":", $._type))
    // )),

    // function_type: $ => seq(
    //   optional(seq($._simple_user_type, ".")), // TODO: Support "real" types
    //   $.function_type_parameters,
    //   "->",
    //   $._type
    // ),

    // function_type_parameters: $ => prec.left(1, seq(
    //   "(",
    //   optional(sep1(choice($.parameter, $._type), ",")),
    //   ")"
    // )),

    // parenthesized_type: $ => seq("(", $._type, ")"),

    _primary_expression: $ => choice(
      $._literal_constant,
      $._string_literal,
    ),

    _extension: $ => seq($.identifier, '.', $.identifier),

    url: $ => sep1(/[a-zA-Z_][a-zA-Z_0-9]*/, '/'),
    package: $ => $.identifier,
    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    definition_name: $ => /[A-Z](([a-z]+[A-Z]?)*)/, // Pascal Case - no digits allowed
    variable_name: $ => /[a-z][a-z]*(([A-Z][a-z]+)*[A-Z]?|([a-z]+[A-Z])*|[A-Z])/, // Lower Camel Case - no digits allowed
    enum_field_name: $ => /[A-Z_][A-Z_0-9]*/,

    // Literals
    boolean_literal: $ => choice("true", "false"),
    integer_literal: $ => token(seq(optional(/[1-9]/), DEC_DIGITS)),
    hex_literal: $ => token(seq("0", /[xX]/, HEX_DIGITS)),
    bin_literal: $ => token(seq("0", /[bB]/, BIN_DIGITS)),
    float_literal: $ => token(choice(
      seq(
        seq(optional(DEC_DIGITS), ".", DEC_DIGITS),
        optional(/[fF]/)
      ),
      seq(DEC_DIGITS, /[fF]/)
    )),
    character_literal: $ => seq(
      "'",
      choice($.character_escape_seq, /[^\n\r'\\]/),
      "'"
    ),
    character_escape_seq: $ => choice(
      $._uni_character_literal,
      $._escaped_identifier
    ),
    _uni_character_literal: $ => seq(
      "\\u",
      /[0-9a-fA-F]{4}/
    ),
    _escaped_identifier: $ => /\\[tbrn'"\\$]/,

    _string_literal: $ => choice(
      $.line_string_literal,
      $.multi_line_string_literal
    ),

    line_string_literal: $ => seq('"', repeat(choice($._line_string_content, $._interpolation)), '"'),

    multi_line_string_literal: $ => seq(
      '`',
      repeat(choice(
        $._multi_line_string_content,
        $._interpolation
      )),
      '`'
    ),

    _line_string_content: $ => choice(
      $._line_str_text,
      $.character_escape_seq
    ),

    _multi_line_string_content: $ => choice($._multi_line_str_text, '"'),

    _line_str_text: $ => /[^\\"$]+/,

    _multi_line_str_text: $ => /[^"$]+/,

    _interpolation: $ => choice(
      // seq("${", alias($._expression, $.interpolated_expression), "}"),
      seq("$", alias($.identifier, $.interpolated_identifier))
    ),

    _literal_constant: $ => choice(
      $.boolean_literal,
      $.integer_literal,
      $.hex_literal,
      $.bin_literal,
      $.character_literal,
      $.float_literal,
      "null",
    ),

    comment: $ => token(prec(PREC.COMMENT, choice(
      seq("#", /.*/),
    ))),
  }
});

function commaSep1(rule) {
  return sep1(rule, ',')
}

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)))
}
