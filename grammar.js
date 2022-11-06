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
    module: $ => repeat($._definitions),

    _definitions: $ => choice(
      $.import_statement,
      $.class_definition,
    ),

    import_statement: $ => seq(
      'import',
      commaSep1(field('name', sep1($.identifier, '/')))
    ),

    class_definition: $ => seq(
      'class',
      field('name', $.identifier),
      field('generics', optional($.generic_list)),
      field('traits', optional($.trait_list)),
      ':',
      field('fields', seq($._indent, seq(
        repeat($.type_pair),
        $._dedent
      ))),
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

    type_pair: $ => seq(
      field('key', $.identifier),
      ':',
      field('value', $.identifier)
    ),

    identifier: $ => /[_\p{XID_Start}][_\p{XID_Continue}]*/,
  }
});

function commaSep1(rule) {
  return sep1(rule, ',')
}

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)))
}
