const DEC_DIGITS = token(sep1(/[0-9]+/, /_+/));
const HEX_DIGITS = token(sep1(/[0-9a-fA-F]+/, /_+/));
const BIN_DIGITS = token(sep1(/[01]/, /_+/));

module.exports = grammar({
  name: 'pine',
  conflicts: $ => [
    [$.fun_field],
  ],
  rules: {
    source_file: $ => seq(
      seq("package", $.package),
      repeat($.import_statement),
      repeat($.definitions),
    ),

    import_statement: $ => seq('import', $.url),

    definitions: $ => choice(
      $.class_definition,
      $.trait_definition,
      $.enum_definition,
      $.fun_definition,
    ),

    class_definition: $ => seq(
      field('traits', optional(repeat($.trait_name))),
      'class',
      field('name', $.definition_name),
      field('generics', optional($.generic_list)),
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
      'fun',
      field('name', choice($.identifier, $._extension)),
      field('params', seq('(', optional(commaSep1($.param)), ')')),
      '=>',
      field('returns', optional(commaSep1($.type))),
      '{', '}',
    ),

    trait_name: $ => seq("@", $.definition_name),

    trait_list: $ => seq(
      '(',
      commaSep1($.identifier),
      ')'
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
  }
});

function commaSep1(rule) {
  return sep1(rule, ',')
}

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)))
}
