const DEC_DIGITS = token(sep1(/[0-9]+/, /_+/));
const HEX_DIGITS = token(sep1(/[0-9a-fA-F]+/, /_+/));
const BIN_DIGITS = token(sep1(/[01]/, /_+/));

module.exports = grammar({
  name: 'pine',
  externals: $ => [
    $._newline,
    $._indent,
    $._dedent,
    $._string_start,
    $._string_content,
    $._string_end,

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
  ],
  rules: {
    source_file: $ => seq(
      seq("package", $.package),
      repeat($.import_statement),
      repeat($.class_definition),
      repeat($.enum_definition),
    ),

    import_statement: $ => seq('import', $.url),

    definitions: $ => choice(
      $.class_definition,
      $.enum_definition,
    ),

    class_definition: $ => seq(
      'class',
      field('name', $.identifier),
      field('generics', optional($.generic_list)),
      field('traits', optional($.trait_list)),
      ':',
      field('fields', seq($._indent, seq(
        repeat($.class_field),
        $._dedent
      ))),
    ),

    enum_definition: $ => seq(
      'enum',
      field('name', $.identifier),
      field('types', $.type_list),
      ':',
      field('fields', seq($._indent, seq(
        repeat($.enum_field),
        $._dedent
      ))),
    ),

    type_list: $ => seq(
      '(',
      commaSep1($.identifier),
      ')'
    ),

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

    class_field: $ => seq(
      field('key', $.identifier),
      ':',
      field('value', $.identifier)
    ),

    enum_field: $ => seq($.enum_identifier, '(', commaSep1($._primary_expression), ')'),

    _primary_expression: $ => choice(
      $._literal_constant,
      $._string_literal,
    ),

    url: $ => sep1(/[a-zA-Z_][a-zA-Z_0-9]*/, '/'),
    package: $ => $.identifier,
    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    enum_identifier: $ => /[A-Z_][A-Z_0-9]*/,

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
