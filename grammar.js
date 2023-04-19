const DEC_DIGITS = token(sep1(/[0-9]+/, /_+/));
const HEX_DIGITS = token(sep1(/[0-9a-fA-F]+/, /_+/));
const BIN_DIGITS = token(sep1(/[01]/, /_+/));

module.exports = grammar({
  name: 'palm',
  // extras: $ => [
  //   $.comment,
  //   /\s+/ // Whitespace
  // ],
  rules: {
    source_file: $ => seq(
      $.module,
      repeat($.import),
      repeat(choice(
        $.record,
        $.type,
        // $.proc,
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

    // proc: $ => seq(
    //   field('name', $.identifier),
    //   field('params', seq('(', optional(commaSep1($.type_field)), ')')),
    //   optional(
    //     seq(
    //       '->',
    //       field('return', optional($.return_type)),
    //     ),
    //   ),
    //   '=',
    //   // field('body', $._block)
    // ),

    /* Shared AST nodes */
    
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
    identifier: ($) => $._name,
    type_identifier: ($) => $._upname,
    generic_list: $ => seq(
      '(',
      commaSep1($.identifier),
      ')'
    ),

    _discard_name: ($) => /_[_0-9a-z]*/,
    _name: ($) => /[_a-z][_0-9a-z]*/,
    _upname: ($) => /[A-Z][0-9a-zA-Z]*/,

    // param: $ => seq(
    //   field('name', $.variable_name),
    //   ':',
    //   field('type', $.type)
    // ),



    // fun_field: $ => seq(
    //   'fun',
    //   field('name', $.identifier),
    //   field('params', seq('(', optional(commaSep1($.param)), ')')),
    //   '=>',
    //   field('returns', optional(commaSep1($.type))),
    // ),

    // trait_field: $ => choice(
    //   $.type_field,
    //   $.fun_field,
    // ),

    // enum_field: $ => seq($.enum_field_name, '(', commaSep1($._primary_expression), ')'),

    // // Expressions

    // _block: $ => prec(PREC.BLOCK, seq(
    //   "{",
    //   // optional($.statements), 
    //   "}"
    // )),

    // // assignment: $ => choice(
    // //   prec.left(PREC.ASSIGNMENT, seq($.directly_assignable_expression, $._assignment_and_operator, $._expression)),
    // //   prec.left(PREC.ASSIGNMENT, seq($.directly_assignable_expression, "=", $._expression)),
    // //   // TODO
    // // ),

    // // // ==========
    // // // Expressions
    // // // ==========

    // // _expression: $ => choice(
    // //   $._unary_expression,
    // //   $._binary_expression,
    // //   $._primary_expression
    // // ),

    // // // Unary expressions

    // // _unary_expression: $ => choice(
    // //   $.postfix_expression,
    // //   $.call_expression,
    // //   $.indexing_expression,
    // //   $.navigation_expression,
    // //   $.prefix_expression,
    // //   $.as_expression,
    // //   $.spread_expression
    // // ),

    // // postfix_expression: $ => prec.left(PREC.POSTFIX, seq($._expression, $._postfix_unary_operator)),

    // // call_expression: $ => prec.left(PREC.POSTFIX, seq($._expression, $.call_suffix)),

    // // indexing_expression: $ => prec.left(PREC.POSTFIX, seq($._expression, $.indexing_suffix)),

    // // navigation_expression: $ => prec.left(PREC.POSTFIX, seq($._expression, $.navigation_suffix)),

    // // prefix_expression: $ => prec.right(seq(choice($.annotation, $.label, $._prefix_unary_operator), $._expression)),

    // // as_expression: $ => prec.left(PREC.AS, seq($._expression, $._as_operator, $._type)),

    // // spread_expression: $ => prec.left(PREC.SPREAD, seq("*", $._expression)),

    // // _binary_expression: $ => choice(
    // //   $.multiplicative_expression,
    // //   $.additive_expression,
    // //   $.range_expression,
    // //   $.infix_expression,
    // //   $.elvis_expression,
    // //   $.check_expression,
    // //   $.comparison_expression,
    // //   $.equality_expression,
    // //   $.comparison_expression,
    // //   $.equality_expression,
    // //   $.conjunction_expression,
    // //   $.disjunction_expression
    // // ),

    // // multiplicative_expression: $ => prec.left(PREC.MULTIPLICATIVE, seq($._expression, $._multiplicative_operator, $._expression)),

    // // additive_expression: $ => prec.left(PREC.ADDITIVE, seq($._expression, $._additive_operator, $._expression)),

    // // range_expression: $ => prec.left(PREC.RANGE, seq($._expression, "..", $._expression)),

    // // infix_expression: $ => prec.left(PREC.INFIX, seq($._expression, $.simple_identifier, $._expression)),

    // // elvis_expression: $ => prec.left(PREC.ELVIS, seq($._expression, "?:", $._expression)),

    // // check_expression: $ => prec.left(PREC.CHECK, seq($._expression, choice(
    // //   seq($._in_operator, $._expression),
    // //   seq($._is_operator, $._type)))),

    // // comparison_expression: $ => prec.left(PREC.COMPARISON, seq($._expression, $._comparison_operator, $._expression)),

    // // equality_expression: $ => prec.left(PREC.EQUALITY, seq($._expression, $._equality_operator, $._expression)),

    // // conjunction_expression: $ => prec.left(PREC.CONJUNCTION, seq($._expression, "&&", $._expression)),

    // // disjunction_expression: $ => prec.left(PREC.DISJUNCTION, seq($._expression, "||", $._expression)),

    // //  // Suffixes

    // // indexing_suffix: $ => seq("[", sep1($._expression, ","), "]"),

    // // navigation_suffix: $ => seq(
    // //    $._member_access_operator,
    // //    choice(
    // //      $.simple_identifier,
    // //      $.parenthesized_expression,
    // //      "class"
    // //    )
    // // ),

    // // call_suffix: $ => prec.left(seq(
    // //    // this introduces ambiguities with 'less than' for comparisons
    // //    optional($.type_arguments),
    // //    choice(
    // //      seq(optional($.value_arguments), $.annotated_lambda),
    // //      $.value_arguments
    // //    )
    // // )),

    // // variable_declaration: $ => prec.left(PREC.VAR_DECL, seq(
    // //   // repeat($.annotation), TODO
    // //   $.simple_identifier,
    // //   optional(seq(":", $._type))
    // // )),

    // // function_type: $ => seq(
    // //   optional(seq($._simple_user_type, ".")), // TODO: Support "real" types
    // //   $.function_type_parameters,
    // //   "->",
    // //   $._type
    // // ),

    // // function_type_parameters: $ => prec.left(1, seq(
    // //   "(",
    // //   optional(sep1(choice($.parameter, $._type), ",")),
    // //   ")"
    // // )),

    // // parenthesized_type: $ => seq("(", $._type, ")"),

    // _primary_expression: $ => choice(
    //   $._literal_constant,
    //   $._string_literal,
    // ),

    url: $ => sep1(/[a-zA-Z_][a-zA-Z_0-9]*/, '/'),
    // module: $ => $.identifier,
    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    // definition_name: $ => /[A-Z](([a-z]+[A-Z]?)*)/, // Pascal Case - no digits allowed
    // variable_name: $ => /[a-z][a-z]*(([A-Z][a-z]+)*[A-Z]?|([a-z]+[A-Z])*|[A-Z])/, // Lower Camel Case - no digits allowed
    // enum_field_name: $ => /[A-Z_][A-Z_0-9]*/,

    // // Literals
    // boolean_literal: $ => choice("true", "false"),
    // integer_literal: $ => token(seq(optional(/[1-9]/), DEC_DIGITS)),
    // hex_literal: $ => token(seq("0", /[xX]/, HEX_DIGITS)),
    // bin_literal: $ => token(seq("0", /[bB]/, BIN_DIGITS)),
    // float_literal: $ => token(choice(
    //   seq(
    //     seq(optional(DEC_DIGITS), ".", DEC_DIGITS),
    //     optional(/[fF]/)
    //   ),
    //   seq(DEC_DIGITS, /[fF]/)
    // )),
    // character_literal: $ => seq(
    //   "'",
    //   choice($.character_escape_seq, /[^\n\r'\\]/),
    //   "'"
    // ),
    // character_escape_seq: $ => choice(
    //   $._uni_character_literal,
    //   $._escaped_identifier
    // ),
    // _uni_character_literal: $ => seq(
    //   "\\u",
    //   /[0-9a-fA-F]{4}/
    // ),
    // _escaped_identifier: $ => /\\[tbrn'"\\$]/,

    // _string_literal: $ => choice(
    //   $.line_string_literal,
    //   $.multi_line_string_literal
    // ),

    // line_string_literal: $ => seq('"', repeat(choice($._line_string_content, $._interpolation)), '"'),

    // multi_line_string_literal: $ => seq(
    //   '`',
    //   repeat(choice(
    //     $._multi_line_string_content,
    //     $._interpolation
    //   )),
    //   '`'
    // ),

    // _line_string_content: $ => choice(
    //   $._line_str_text,
    //   $.character_escape_seq
    // ),

    // _multi_line_string_content: $ => choice($._multi_line_str_text, '"'),

    // _line_str_text: $ => /[^\\"$]+/,

    // _multi_line_str_text: $ => /[^"$]+/,

    // _interpolation: $ => choice(
    //   // seq("${", alias($._expression, $.interpolated_expression), "}"),
    //   seq("$", alias($.identifier, $.interpolated_identifier))
    // ),

    // _literal_constant: $ => choice(
    //   $.boolean_literal,
    //   $.integer_literal,
    //   $.hex_literal,
    //   $.bin_literal,
    //   $.character_literal,
    //   $.float_literal,
    //   "null",
    // ),

    // comment: $ => token(prec(PREC.COMMENT, choice(
    //   seq("#", /.*/),
    // ))),
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