#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 119
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 74
#define ALIAS_COUNT 1
#define TOKEN_COUNT 40
#define EXTERNAL_TOKEN_COUNT 10
#define FIELD_COUNT 7
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 13

enum {
  anon_sym_package = 1,
  anon_sym_import = 2,
  anon_sym_class = 3,
  anon_sym_COLON = 4,
  anon_sym_enum = 5,
  anon_sym_LPAREN = 6,
  anon_sym_COMMA = 7,
  anon_sym_RPAREN = 8,
  anon_sym_LT = 9,
  anon_sym_GT = 10,
  aux_sym_url_token1 = 11,
  anon_sym_SLASH = 12,
  sym_enum_identifier = 13,
  anon_sym_true = 14,
  anon_sym_false = 15,
  sym_integer_literal = 16,
  sym_hex_literal = 17,
  sym_bin_literal = 18,
  sym_float_literal = 19,
  anon_sym_SQUOTE = 20,
  aux_sym_character_literal_token1 = 21,
  anon_sym_BSLASHu = 22,
  aux_sym__uni_character_literal_token1 = 23,
  sym__escaped_identifier = 24,
  anon_sym_DQUOTE = 25,
  anon_sym_BQUOTE = 26,
  sym__line_str_text = 27,
  sym__multi_line_str_text = 28,
  anon_sym_DOLLAR = 29,
  anon_sym_null = 30,
  anon_sym_RBRACK = 31,
  anon_sym_RBRACE = 32,
  sym__newline = 33,
  sym__indent = 34,
  sym__dedent = 35,
  sym__string_start = 36,
  sym__string_content = 37,
  sym__string_end = 38,
  sym_comment = 39,
  sym_source_file = 40,
  sym_import_statement = 41,
  sym_class_definition = 42,
  sym_enum_definition = 43,
  sym_type_list = 44,
  sym_trait_list = 45,
  sym_generic_list = 46,
  sym_class_field = 47,
  sym_enum_field = 48,
  sym__primary_expression = 49,
  sym_url = 50,
  sym_package = 51,
  sym_identifier = 52,
  sym_boolean_literal = 53,
  sym_character_literal = 54,
  sym_character_escape_seq = 55,
  sym__uni_character_literal = 56,
  sym__string_literal = 57,
  sym_line_string_literal = 58,
  sym_multi_line_string_literal = 59,
  sym__line_string_content = 60,
  sym__multi_line_string_content = 61,
  sym__interpolation = 62,
  sym__literal_constant = 63,
  aux_sym_source_file_repeat1 = 64,
  aux_sym_source_file_repeat2 = 65,
  aux_sym_source_file_repeat3 = 66,
  aux_sym_class_definition_repeat1 = 67,
  aux_sym_enum_definition_repeat1 = 68,
  aux_sym_type_list_repeat1 = 69,
  aux_sym_enum_field_repeat1 = 70,
  aux_sym_url_repeat1 = 71,
  aux_sym_line_string_literal_repeat1 = 72,
  aux_sym_multi_line_string_literal_repeat1 = 73,
  alias_sym_interpolated_identifier = 74,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_package] = "package",
  [anon_sym_import] = "import",
  [anon_sym_class] = "class",
  [anon_sym_COLON] = ":",
  [anon_sym_enum] = "enum",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [aux_sym_url_token1] = "url_token1",
  [anon_sym_SLASH] = "/",
  [sym_enum_identifier] = "enum_identifier",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_integer_literal] = "integer_literal",
  [sym_hex_literal] = "hex_literal",
  [sym_bin_literal] = "bin_literal",
  [sym_float_literal] = "float_literal",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_character_literal_token1] = "character_literal_token1",
  [anon_sym_BSLASHu] = "\\u",
  [aux_sym__uni_character_literal_token1] = "_uni_character_literal_token1",
  [sym__escaped_identifier] = "_escaped_identifier",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_BQUOTE] = "`",
  [sym__line_str_text] = "_line_str_text",
  [sym__multi_line_str_text] = "_multi_line_str_text",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_null] = "null",
  [anon_sym_RBRACK] = "]",
  [anon_sym_RBRACE] = "}",
  [sym__newline] = "_newline",
  [sym__indent] = "_indent",
  [sym__dedent] = "_dedent",
  [sym__string_start] = "_string_start",
  [sym__string_content] = "_string_content",
  [sym__string_end] = "_string_end",
  [sym_comment] = "comment",
  [sym_source_file] = "source_file",
  [sym_import_statement] = "import_statement",
  [sym_class_definition] = "class_definition",
  [sym_enum_definition] = "enum_definition",
  [sym_type_list] = "type_list",
  [sym_trait_list] = "trait_list",
  [sym_generic_list] = "generic_list",
  [sym_class_field] = "class_field",
  [sym_enum_field] = "enum_field",
  [sym__primary_expression] = "_primary_expression",
  [sym_url] = "url",
  [sym_package] = "package",
  [sym_identifier] = "identifier",
  [sym_boolean_literal] = "boolean_literal",
  [sym_character_literal] = "character_literal",
  [sym_character_escape_seq] = "character_escape_seq",
  [sym__uni_character_literal] = "_uni_character_literal",
  [sym__string_literal] = "_string_literal",
  [sym_line_string_literal] = "line_string_literal",
  [sym_multi_line_string_literal] = "multi_line_string_literal",
  [sym__line_string_content] = "_line_string_content",
  [sym__multi_line_string_content] = "_multi_line_string_content",
  [sym__interpolation] = "_interpolation",
  [sym__literal_constant] = "_literal_constant",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_source_file_repeat2] = "source_file_repeat2",
  [aux_sym_source_file_repeat3] = "source_file_repeat3",
  [aux_sym_class_definition_repeat1] = "class_definition_repeat1",
  [aux_sym_enum_definition_repeat1] = "enum_definition_repeat1",
  [aux_sym_type_list_repeat1] = "type_list_repeat1",
  [aux_sym_enum_field_repeat1] = "enum_field_repeat1",
  [aux_sym_url_repeat1] = "url_repeat1",
  [aux_sym_line_string_literal_repeat1] = "line_string_literal_repeat1",
  [aux_sym_multi_line_string_literal_repeat1] = "multi_line_string_literal_repeat1",
  [alias_sym_interpolated_identifier] = "interpolated_identifier",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_package] = anon_sym_package,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_class] = anon_sym_class,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [aux_sym_url_token1] = aux_sym_url_token1,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [sym_enum_identifier] = sym_enum_identifier,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_integer_literal] = sym_integer_literal,
  [sym_hex_literal] = sym_hex_literal,
  [sym_bin_literal] = sym_bin_literal,
  [sym_float_literal] = sym_float_literal,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_character_literal_token1] = aux_sym_character_literal_token1,
  [anon_sym_BSLASHu] = anon_sym_BSLASHu,
  [aux_sym__uni_character_literal_token1] = aux_sym__uni_character_literal_token1,
  [sym__escaped_identifier] = sym__escaped_identifier,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [sym__line_str_text] = sym__line_str_text,
  [sym__multi_line_str_text] = sym__multi_line_str_text,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_null] = anon_sym_null,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym__newline] = sym__newline,
  [sym__indent] = sym__indent,
  [sym__dedent] = sym__dedent,
  [sym__string_start] = sym__string_start,
  [sym__string_content] = sym__string_content,
  [sym__string_end] = sym__string_end,
  [sym_comment] = sym_comment,
  [sym_source_file] = sym_source_file,
  [sym_import_statement] = sym_import_statement,
  [sym_class_definition] = sym_class_definition,
  [sym_enum_definition] = sym_enum_definition,
  [sym_type_list] = sym_type_list,
  [sym_trait_list] = sym_trait_list,
  [sym_generic_list] = sym_generic_list,
  [sym_class_field] = sym_class_field,
  [sym_enum_field] = sym_enum_field,
  [sym__primary_expression] = sym__primary_expression,
  [sym_url] = sym_url,
  [sym_package] = sym_package,
  [sym_identifier] = sym_identifier,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym_character_literal] = sym_character_literal,
  [sym_character_escape_seq] = sym_character_escape_seq,
  [sym__uni_character_literal] = sym__uni_character_literal,
  [sym__string_literal] = sym__string_literal,
  [sym_line_string_literal] = sym_line_string_literal,
  [sym_multi_line_string_literal] = sym_multi_line_string_literal,
  [sym__line_string_content] = sym__line_string_content,
  [sym__multi_line_string_content] = sym__multi_line_string_content,
  [sym__interpolation] = sym__interpolation,
  [sym__literal_constant] = sym__literal_constant,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_source_file_repeat2] = aux_sym_source_file_repeat2,
  [aux_sym_source_file_repeat3] = aux_sym_source_file_repeat3,
  [aux_sym_class_definition_repeat1] = aux_sym_class_definition_repeat1,
  [aux_sym_enum_definition_repeat1] = aux_sym_enum_definition_repeat1,
  [aux_sym_type_list_repeat1] = aux_sym_type_list_repeat1,
  [aux_sym_enum_field_repeat1] = aux_sym_enum_field_repeat1,
  [aux_sym_url_repeat1] = aux_sym_url_repeat1,
  [aux_sym_line_string_literal_repeat1] = aux_sym_line_string_literal_repeat1,
  [aux_sym_multi_line_string_literal_repeat1] = aux_sym_multi_line_string_literal_repeat1,
  [alias_sym_interpolated_identifier] = alias_sym_interpolated_identifier,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_package] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_class] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_url_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [sym_enum_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_integer_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_hex_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_bin_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_float_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_character_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASHu] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__uni_character_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__escaped_identifier] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym__line_str_text] = {
    .visible = false,
    .named = true,
  },
  [sym__multi_line_str_text] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_null] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym__indent] = {
    .visible = false,
    .named = true,
  },
  [sym__dedent] = {
    .visible = false,
    .named = true,
  },
  [sym__string_start] = {
    .visible = false,
    .named = true,
  },
  [sym__string_content] = {
    .visible = false,
    .named = true,
  },
  [sym__string_end] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_import_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_class_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_type_list] = {
    .visible = true,
    .named = true,
  },
  [sym_trait_list] = {
    .visible = true,
    .named = true,
  },
  [sym_generic_list] = {
    .visible = true,
    .named = true,
  },
  [sym_class_field] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_field] = {
    .visible = true,
    .named = true,
  },
  [sym__primary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_url] = {
    .visible = true,
    .named = true,
  },
  [sym_package] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_character_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_character_escape_seq] = {
    .visible = true,
    .named = true,
  },
  [sym__uni_character_literal] = {
    .visible = false,
    .named = true,
  },
  [sym__string_literal] = {
    .visible = false,
    .named = true,
  },
  [sym_line_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_multi_line_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym__line_string_content] = {
    .visible = false,
    .named = true,
  },
  [sym__multi_line_string_content] = {
    .visible = false,
    .named = true,
  },
  [sym__interpolation] = {
    .visible = false,
    .named = true,
  },
  [sym__literal_constant] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_source_file_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_source_file_repeat3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_class_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_field_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_url_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_line_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_multi_line_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_interpolated_identifier] = {
    .visible = true,
    .named = true,
  },
};

enum {
  field_fields = 1,
  field_generics = 2,
  field_key = 3,
  field_name = 4,
  field_traits = 5,
  field_types = 6,
  field_value = 7,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_fields] = "fields",
  [field_generics] = "generics",
  [field_key] = "key",
  [field_name] = "name",
  [field_traits] = "traits",
  [field_types] = "types",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 3},
  [2] = {.index = 3, .length = 4},
  [3] = {.index = 7, .length = 4},
  [4] = {.index = 11, .length = 4},
  [5] = {.index = 15, .length = 4},
  [6] = {.index = 19, .length = 2},
  [7] = {.index = 21, .length = 5},
  [8] = {.index = 26, .length = 5},
  [9] = {.index = 31, .length = 5},
  [10] = {.index = 36, .length = 5},
  [11] = {.index = 41, .length = 6},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_fields, 3},
    {field_fields, 4},
    {field_name, 1},
  [3] =
    {field_fields, 3},
    {field_fields, 4},
    {field_fields, 5},
    {field_name, 1},
  [7] =
    {field_fields, 4},
    {field_fields, 5},
    {field_name, 1},
    {field_traits, 2},
  [11] =
    {field_fields, 4},
    {field_fields, 5},
    {field_generics, 2},
    {field_name, 1},
  [15] =
    {field_fields, 4},
    {field_fields, 5},
    {field_name, 1},
    {field_types, 2},
  [19] =
    {field_key, 0},
    {field_value, 2},
  [21] =
    {field_fields, 4},
    {field_fields, 5},
    {field_fields, 6},
    {field_name, 1},
    {field_traits, 2},
  [26] =
    {field_fields, 4},
    {field_fields, 5},
    {field_fields, 6},
    {field_generics, 2},
    {field_name, 1},
  [31] =
    {field_fields, 5},
    {field_fields, 6},
    {field_generics, 2},
    {field_name, 1},
    {field_traits, 3},
  [36] =
    {field_fields, 4},
    {field_fields, 5},
    {field_fields, 6},
    {field_name, 1},
    {field_types, 2},
  [41] =
    {field_fields, 5},
    {field_fields, 6},
    {field_fields, 7},
    {field_generics, 2},
    {field_name, 1},
    {field_traits, 3},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [12] = {
    [1] = alias_sym_interpolated_identifier,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym_identifier, 2,
    sym_identifier,
    alias_sym_interpolated_identifier,
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(50);
      if (lookahead == '"') ADVANCE(87);
      if (lookahead == '$') ADVANCE(94);
      if (lookahead == '\'') ADVANCE(81);
      if (lookahead == '(') ADVANCE(56);
      if (lookahead == ')') ADVANCE(58);
      if (lookahead == ',') ADVANCE(57);
      if (lookahead == '/') ADVANCE(62);
      if (lookahead == '0') ADVANCE(71);
      if (lookahead == ':') ADVANCE(54);
      if (lookahead == '<') ADVANCE(59);
      if (lookahead == '>') ADVANCE(60);
      if (lookahead == '\\') ADVANCE(37);
      if (lookahead == ']') ADVANCE(96);
      if (lookahead == '`') ADVANCE(88);
      if (lookahead == 'c') ADVANCE(22);
      if (lookahead == 'e') ADVANCE(28);
      if (lookahead == 'f') ADVANCE(13);
      if (lookahead == 'i') ADVANCE(26);
      if (lookahead == 'n') ADVANCE(38);
      if (lookahead == 'p') ADVANCE(10);
      if (lookahead == 't') ADVANCE(32);
      if (lookahead == '}') ADVANCE(97);
      if (('a' <= lookahead && lookahead <= 'd')) ADVANCE(49);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'F')) ADVANCE(65);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(74);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(87);
      if (lookahead == '$') ADVANCE(94);
      if (lookahead == '\\') ADVANCE(37);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(90);
      if (lookahead != 0) ADVANCE(91);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(87);
      if (lookahead == '$') ADVANCE(94);
      if (lookahead == '`') ADVANCE(89);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(92);
      if (lookahead != 0) ADVANCE(93);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(87);
      if (lookahead == '\'') ADVANCE(81);
      if (lookahead == '.') ADVANCE(45);
      if (lookahead == '0') ADVANCE(69);
      if (lookahead == '`') ADVANCE(88);
      if (lookahead == 'f') ADVANCE(14);
      if (lookahead == 'n') ADVANCE(38);
      if (lookahead == 't') ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(70);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 4:
      if (lookahead == '\\') ADVANCE(37);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(83);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(4)
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(82);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(6);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(77);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);
      END_STATE();
    case 9:
      if (lookahead == '_') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(15);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(35);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(19);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(24);
      END_STATE();
    case 15:
      if (lookahead == 'c') ADVANCE(20);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(68);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(51);
      END_STATE();
    case 19:
      if (lookahead == 'g') ADVANCE(18);
      END_STATE();
    case 20:
      if (lookahead == 'k') ADVANCE(12);
      END_STATE();
    case 21:
      if (lookahead == 'l') ADVANCE(95);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 23:
      if (lookahead == 'l') ADVANCE(21);
      END_STATE();
    case 24:
      if (lookahead == 'l') ADVANCE(34);
      END_STATE();
    case 25:
      if (lookahead == 'l') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 26:
      if (lookahead == 'm') ADVANCE(30);
      END_STATE();
    case 27:
      if (lookahead == 'm') ADVANCE(55);
      END_STATE();
    case 28:
      if (lookahead == 'n') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 29:
      if (lookahead == 'o') ADVANCE(31);
      END_STATE();
    case 30:
      if (lookahead == 'p') ADVANCE(29);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(39);
      END_STATE();
    case 33:
      if (lookahead == 's') ADVANCE(53);
      END_STATE();
    case 34:
      if (lookahead == 's') ADVANCE(17);
      END_STATE();
    case 35:
      if (lookahead == 's') ADVANCE(33);
      END_STATE();
    case 36:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 37:
      if (lookahead == 'u') ADVANCE(84);
      if (lookahead == '"' ||
          lookahead == '$' ||
          lookahead == '\'' ||
          lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't') ADVANCE(86);
      END_STATE();
    case 38:
      if (lookahead == 'u') ADVANCE(23);
      END_STATE();
    case 39:
      if (lookahead == 'u') ADVANCE(16);
      END_STATE();
    case 40:
      if (lookahead == 'u') ADVANCE(27);
      END_STATE();
    case 41:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(78);
      if (('2' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 42:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(77);
      END_STATE();
    case 43:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(43)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(61);
      END_STATE();
    case 44:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(44)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_class);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_url_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_enum_identifier);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(66);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_enum_identifier);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(63);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_enum_identifier);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(64);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_enum_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(45);
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(42);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(79);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(45);
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(5);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(41);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(46);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_bin_literal);
      if (lookahead == '_') ADVANCE(6);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_bin_literal);
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_float_literal);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(9);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(82);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_BSLASHu);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym__uni_character_literal_token1);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym__escaped_identifier);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$') ADVANCE(93);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym__line_str_text);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(91);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym__line_str_text);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(91);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym__multi_line_str_text);
      if (lookahead == '`') ADVANCE(89);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$') ADVANCE(93);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym__multi_line_str_text);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$') ADVANCE(93);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 3},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 43, .external_lex_state = 2},
  [20] = {.lex_state = 43, .external_lex_state = 2},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 43, .external_lex_state = 2},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 43, .external_lex_state = 2},
  [25] = {.lex_state = 43, .external_lex_state = 2},
  [26] = {.lex_state = 43, .external_lex_state = 2},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 43, .external_lex_state = 2},
  [29] = {.lex_state = 43, .external_lex_state = 2},
  [30] = {.lex_state = 43, .external_lex_state = 2},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 3, .external_lex_state = 2},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 3, .external_lex_state = 2},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 3, .external_lex_state = 2},
  [42] = {.lex_state = 2},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0, .external_lex_state = 3},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0, .external_lex_state = 3},
  [53] = {.lex_state = 0, .external_lex_state = 3},
  [54] = {.lex_state = 0, .external_lex_state = 3},
  [55] = {.lex_state = 43},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0, .external_lex_state = 3},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0, .external_lex_state = 3},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0, .external_lex_state = 3},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0, .external_lex_state = 3},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 43},
  [69] = {.lex_state = 3, .external_lex_state = 2},
  [70] = {.lex_state = 43},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 43, .external_lex_state = 2},
  [73] = {.lex_state = 43},
  [74] = {.lex_state = 43},
  [75] = {.lex_state = 43, .external_lex_state = 2},
  [76] = {.lex_state = 0, .external_lex_state = 3},
  [77] = {.lex_state = 43},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 43},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0, .external_lex_state = 3},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 43},
  [85] = {.lex_state = 43},
  [86] = {.lex_state = 0, .external_lex_state = 3},
  [87] = {.lex_state = 43},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0, .external_lex_state = 3},
  [90] = {.lex_state = 43},
  [91] = {.lex_state = 0, .external_lex_state = 3},
  [92] = {.lex_state = 0, .external_lex_state = 3},
  [93] = {.lex_state = 43},
  [94] = {.lex_state = 0, .external_lex_state = 3},
  [95] = {.lex_state = 3, .external_lex_state = 2},
  [96] = {.lex_state = 0, .external_lex_state = 3},
  [97] = {.lex_state = 0, .external_lex_state = 3},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0, .external_lex_state = 4},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0, .external_lex_state = 4},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0, .external_lex_state = 4},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 44},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0, .external_lex_state = 4},
  [111] = {.lex_state = 43},
  [112] = {.lex_state = 0, .external_lex_state = 4},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 44},
  [118] = {.lex_state = 0},
};

enum {
  ts_external_token__newline = 0,
  ts_external_token__indent = 1,
  ts_external_token__dedent = 2,
  ts_external_token__string_start = 3,
  ts_external_token__string_content = 4,
  ts_external_token__string_end = 5,
  ts_external_token_comment = 6,
  ts_external_token_RBRACK = 7,
  ts_external_token_RPAREN = 8,
  ts_external_token_RBRACE = 9,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__newline] = sym__newline,
  [ts_external_token__indent] = sym__indent,
  [ts_external_token__dedent] = sym__dedent,
  [ts_external_token__string_start] = sym__string_start,
  [ts_external_token__string_content] = sym__string_content,
  [ts_external_token__string_end] = sym__string_end,
  [ts_external_token_comment] = sym_comment,
  [ts_external_token_RBRACK] = anon_sym_RBRACK,
  [ts_external_token_RPAREN] = anon_sym_RPAREN,
  [ts_external_token_RBRACE] = anon_sym_RBRACE,
};

static const bool ts_external_scanner_states[5][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__newline] = true,
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
    [ts_external_token__string_start] = true,
    [ts_external_token__string_content] = true,
    [ts_external_token__string_end] = true,
    [ts_external_token_comment] = true,
    [ts_external_token_RBRACK] = true,
    [ts_external_token_RPAREN] = true,
    [ts_external_token_RBRACE] = true,
  },
  [2] = {
    [ts_external_token__dedent] = true,
  },
  [3] = {
    [ts_external_token_RPAREN] = true,
  },
  [4] = {
    [ts_external_token__indent] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_package] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_class] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [sym_enum_identifier] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_integer_literal] = ACTIONS(1),
    [sym_hex_literal] = ACTIONS(1),
    [sym_bin_literal] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_BSLASHu] = ACTIONS(1),
    [aux_sym__uni_character_literal_token1] = ACTIONS(1),
    [sym__escaped_identifier] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [sym__indent] = ACTIONS(1),
    [sym__dedent] = ACTIONS(1),
    [sym__string_start] = ACTIONS(1),
    [sym__string_content] = ACTIONS(1),
    [sym__string_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(114),
    [anon_sym_package] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(7), 1,
      sym_integer_literal,
    ACTIONS(11), 1,
      anon_sym_SQUOTE,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(5), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(9), 4,
      sym_hex_literal,
      sym_bin_literal,
      sym_float_literal,
      anon_sym_null,
    STATE(64), 7,
      sym__primary_expression,
      sym_boolean_literal,
      sym_character_literal,
      sym__string_literal,
      sym_line_string_literal,
      sym_multi_line_string_literal,
      sym__literal_constant,
  [32] = 7,
    ACTIONS(11), 1,
      anon_sym_SQUOTE,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(17), 1,
      sym_integer_literal,
    ACTIONS(5), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(19), 4,
      sym_hex_literal,
      sym_bin_literal,
      sym_float_literal,
      anon_sym_null,
    STATE(91), 7,
      sym__primary_expression,
      sym_boolean_literal,
      sym_character_literal,
      sym__string_literal,
      sym_line_string_literal,
      sym_multi_line_string_literal,
      sym__literal_constant,
  [64] = 7,
    ACTIONS(21), 1,
      anon_sym_BSLASHu,
    ACTIONS(23), 1,
      sym__escaped_identifier,
    ACTIONS(25), 1,
      anon_sym_DQUOTE,
    ACTIONS(27), 1,
      sym__line_str_text,
    ACTIONS(29), 1,
      anon_sym_DOLLAR,
    STATE(21), 1,
      sym__uni_character_literal,
    STATE(6), 4,
      sym_character_escape_seq,
      sym__line_string_content,
      sym__interpolation,
      aux_sym_line_string_literal_repeat1,
  [89] = 7,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      anon_sym_import,
    ACTIONS(35), 1,
      anon_sym_class,
    ACTIONS(37), 1,
      anon_sym_enum,
    STATE(7), 2,
      sym_import_statement,
      aux_sym_source_file_repeat1,
    STATE(13), 2,
      sym_class_definition,
      aux_sym_source_file_repeat2,
    STATE(37), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [114] = 7,
    ACTIONS(21), 1,
      anon_sym_BSLASHu,
    ACTIONS(23), 1,
      sym__escaped_identifier,
    ACTIONS(29), 1,
      anon_sym_DOLLAR,
    ACTIONS(39), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym__line_str_text,
    STATE(21), 1,
      sym__uni_character_literal,
    STATE(8), 4,
      sym_character_escape_seq,
      sym__line_string_content,
      sym__interpolation,
      aux_sym_line_string_literal_repeat1,
  [139] = 7,
    ACTIONS(33), 1,
      anon_sym_import,
    ACTIONS(35), 1,
      anon_sym_class,
    ACTIONS(37), 1,
      anon_sym_enum,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    STATE(14), 2,
      sym_class_definition,
      aux_sym_source_file_repeat2,
    STATE(18), 2,
      sym_import_statement,
      aux_sym_source_file_repeat1,
    STATE(43), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [164] = 7,
    ACTIONS(45), 1,
      anon_sym_BSLASHu,
    ACTIONS(48), 1,
      sym__escaped_identifier,
    ACTIONS(51), 1,
      anon_sym_DQUOTE,
    ACTIONS(53), 1,
      sym__line_str_text,
    ACTIONS(56), 1,
      anon_sym_DOLLAR,
    STATE(21), 1,
      sym__uni_character_literal,
    STATE(8), 4,
      sym_character_escape_seq,
      sym__line_string_content,
      sym__interpolation,
      aux_sym_line_string_literal_repeat1,
  [189] = 1,
    ACTIONS(59), 9,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_COLON,
      anon_sym_enum,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_LT,
      anon_sym_GT,
  [201] = 4,
    ACTIONS(64), 1,
      anon_sym_BQUOTE,
    ACTIONS(66), 1,
      anon_sym_DOLLAR,
    ACTIONS(61), 2,
      anon_sym_DQUOTE,
      sym__multi_line_str_text,
    STATE(10), 3,
      sym__multi_line_string_content,
      sym__interpolation,
      aux_sym_multi_line_string_literal_repeat1,
  [217] = 4,
    ACTIONS(71), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(69), 2,
      anon_sym_DQUOTE,
      sym__multi_line_str_text,
    STATE(12), 3,
      sym__multi_line_string_content,
      sym__interpolation,
      aux_sym_multi_line_string_literal_repeat1,
  [233] = 4,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(77), 1,
      anon_sym_BQUOTE,
    ACTIONS(75), 2,
      anon_sym_DQUOTE,
      sym__multi_line_str_text,
    STATE(10), 3,
      sym__multi_line_string_content,
      sym__interpolation,
      aux_sym_multi_line_string_literal_repeat1,
  [249] = 5,
    ACTIONS(35), 1,
      anon_sym_class,
    ACTIONS(37), 1,
      anon_sym_enum,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    STATE(23), 2,
      sym_class_definition,
      aux_sym_source_file_repeat2,
    STATE(43), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [267] = 5,
    ACTIONS(35), 1,
      anon_sym_class,
    ACTIONS(37), 1,
      anon_sym_enum,
    ACTIONS(79), 1,
      ts_builtin_sym_end,
    STATE(23), 2,
      sym_class_definition,
      aux_sym_source_file_repeat2,
    STATE(46), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [285] = 3,
    ACTIONS(83), 1,
      anon_sym_SLASH,
    STATE(15), 1,
      aux_sym_url_repeat1,
    ACTIONS(81), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
  [298] = 3,
    ACTIONS(88), 1,
      anon_sym_SLASH,
    STATE(17), 1,
      aux_sym_url_repeat1,
    ACTIONS(86), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
  [311] = 3,
    ACTIONS(88), 1,
      anon_sym_SLASH,
    STATE(15), 1,
      aux_sym_url_repeat1,
    ACTIONS(90), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
  [324] = 3,
    ACTIONS(94), 1,
      anon_sym_import,
    STATE(18), 2,
      sym_import_statement,
      aux_sym_source_file_repeat1,
    ACTIONS(92), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [337] = 4,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    ACTIONS(99), 1,
      sym__dedent,
    STATE(108), 1,
      sym_identifier,
    STATE(20), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [351] = 4,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    ACTIONS(101), 1,
      sym__dedent,
    STATE(108), 1,
      sym_identifier,
    STATE(26), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [365] = 2,
    ACTIONS(105), 1,
      sym__line_str_text,
    ACTIONS(103), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [375] = 4,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    ACTIONS(107), 1,
      sym__dedent,
    STATE(108), 1,
      sym_identifier,
    STATE(28), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [389] = 3,
    ACTIONS(111), 1,
      anon_sym_class,
    ACTIONS(109), 2,
      ts_builtin_sym_end,
      anon_sym_enum,
    STATE(23), 2,
      sym_class_definition,
      aux_sym_source_file_repeat2,
  [401] = 4,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    ACTIONS(114), 1,
      sym__dedent,
    STATE(108), 1,
      sym_identifier,
    STATE(26), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [415] = 4,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    ACTIONS(116), 1,
      sym__dedent,
    STATE(108), 1,
      sym_identifier,
    STATE(26), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [429] = 4,
    ACTIONS(118), 1,
      aux_sym_url_token1,
    ACTIONS(121), 1,
      sym__dedent,
    STATE(108), 1,
      sym_identifier,
    STATE(26), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [443] = 2,
    ACTIONS(125), 1,
      sym__line_str_text,
    ACTIONS(123), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [453] = 4,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    ACTIONS(127), 1,
      sym__dedent,
    STATE(108), 1,
      sym_identifier,
    STATE(26), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [467] = 4,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    ACTIONS(129), 1,
      sym__dedent,
    STATE(108), 1,
      sym_identifier,
    STATE(24), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [481] = 4,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    ACTIONS(131), 1,
      sym__dedent,
    STATE(108), 1,
      sym_identifier,
    STATE(25), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [495] = 5,
    ACTIONS(133), 1,
      aux_sym_character_literal_token1,
    ACTIONS(135), 1,
      anon_sym_BSLASHu,
    ACTIONS(137), 1,
      sym__escaped_identifier,
    STATE(105), 1,
      sym__uni_character_literal,
    STATE(107), 1,
      sym_character_escape_seq,
  [511] = 1,
    ACTIONS(81), 5,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
      anon_sym_SLASH,
  [519] = 5,
    ACTIONS(139), 1,
      anon_sym_COLON,
    ACTIONS(141), 1,
      anon_sym_LPAREN,
    ACTIONS(143), 1,
      anon_sym_LT,
    STATE(56), 1,
      sym_generic_list,
    STATE(101), 1,
      sym_trait_list,
  [535] = 2,
    ACTIONS(59), 1,
      sym__line_str_text,
    ACTIONS(145), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [545] = 2,
    ACTIONS(149), 1,
      sym__line_str_text,
    ACTIONS(147), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [555] = 3,
    ACTIONS(151), 1,
      sym_enum_identifier,
    ACTIONS(154), 1,
      sym__dedent,
    STATE(36), 2,
      sym_enum_field,
      aux_sym_enum_definition_repeat1,
  [566] = 3,
    ACTIONS(37), 1,
      anon_sym_enum,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    STATE(40), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [577] = 3,
    ACTIONS(156), 1,
      sym_enum_identifier,
    ACTIONS(158), 1,
      sym__dedent,
    STATE(36), 2,
      sym_enum_field,
      aux_sym_enum_definition_repeat1,
  [588] = 1,
    ACTIONS(123), 4,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym__multi_line_str_text,
      anon_sym_DOLLAR,
  [595] = 3,
    ACTIONS(160), 1,
      ts_builtin_sym_end,
    ACTIONS(162), 1,
      anon_sym_enum,
    STATE(40), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [606] = 3,
    ACTIONS(156), 1,
      sym_enum_identifier,
    ACTIONS(165), 1,
      sym__dedent,
    STATE(38), 2,
      sym_enum_field,
      aux_sym_enum_definition_repeat1,
  [617] = 1,
    ACTIONS(145), 4,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym__multi_line_str_text,
      anon_sym_DOLLAR,
  [624] = 3,
    ACTIONS(37), 1,
      anon_sym_enum,
    ACTIONS(79), 1,
      ts_builtin_sym_end,
    STATE(40), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [635] = 1,
    ACTIONS(167), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
  [642] = 1,
    ACTIONS(169), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
  [649] = 3,
    ACTIONS(37), 1,
      anon_sym_enum,
    ACTIONS(171), 1,
      ts_builtin_sym_end,
    STATE(40), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [660] = 1,
    ACTIONS(173), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [666] = 1,
    ACTIONS(175), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [672] = 3,
    ACTIONS(177), 1,
      anon_sym_COMMA,
    ACTIONS(179), 1,
      anon_sym_RPAREN,
    STATE(60), 1,
      aux_sym_type_list_repeat1,
  [682] = 1,
    ACTIONS(181), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [688] = 3,
    ACTIONS(183), 1,
      anon_sym_COMMA,
    ACTIONS(185), 1,
      anon_sym_GT,
    STATE(62), 1,
      aux_sym_type_list_repeat1,
  [698] = 3,
    ACTIONS(187), 1,
      anon_sym_COMMA,
    ACTIONS(189), 1,
      anon_sym_RPAREN,
    STATE(58), 1,
      aux_sym_enum_field_repeat1,
  [708] = 3,
    ACTIONS(177), 1,
      anon_sym_COMMA,
    ACTIONS(191), 1,
      anon_sym_RPAREN,
    STATE(49), 1,
      aux_sym_type_list_repeat1,
  [718] = 3,
    ACTIONS(177), 1,
      anon_sym_COMMA,
    ACTIONS(193), 1,
      anon_sym_RPAREN,
    STATE(60), 1,
      aux_sym_type_list_repeat1,
  [728] = 3,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    STATE(5), 1,
      sym_package,
    STATE(45), 1,
      sym_identifier,
  [738] = 3,
    ACTIONS(141), 1,
      anon_sym_LPAREN,
    ACTIONS(195), 1,
      anon_sym_COLON,
    STATE(103), 1,
      sym_trait_list,
  [748] = 1,
    ACTIONS(197), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [754] = 3,
    ACTIONS(199), 1,
      anon_sym_COMMA,
    ACTIONS(202), 1,
      anon_sym_RPAREN,
    STATE(58), 1,
      aux_sym_enum_field_repeat1,
  [764] = 1,
    ACTIONS(204), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [770] = 3,
    ACTIONS(206), 1,
      anon_sym_COMMA,
    ACTIONS(209), 1,
      anon_sym_RPAREN,
    STATE(60), 1,
      aux_sym_type_list_repeat1,
  [780] = 1,
    ACTIONS(211), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [786] = 3,
    ACTIONS(209), 1,
      anon_sym_GT,
    ACTIONS(213), 1,
      anon_sym_COMMA,
    STATE(62), 1,
      aux_sym_type_list_repeat1,
  [796] = 1,
    ACTIONS(216), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [802] = 3,
    ACTIONS(187), 1,
      anon_sym_COMMA,
    ACTIONS(218), 1,
      anon_sym_RPAREN,
    STATE(52), 1,
      aux_sym_enum_field_repeat1,
  [812] = 3,
    ACTIONS(183), 1,
      anon_sym_COMMA,
    ACTIONS(220), 1,
      anon_sym_GT,
    STATE(51), 1,
      aux_sym_type_list_repeat1,
  [822] = 3,
    ACTIONS(177), 1,
      anon_sym_COMMA,
    ACTIONS(222), 1,
      anon_sym_RPAREN,
    STATE(54), 1,
      aux_sym_type_list_repeat1,
  [832] = 1,
    ACTIONS(224), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [838] = 2,
    ACTIONS(226), 1,
      aux_sym_url_token1,
    STATE(66), 1,
      sym_identifier,
  [845] = 1,
    ACTIONS(228), 2,
      sym__dedent,
      sym_enum_identifier,
  [850] = 2,
    ACTIONS(230), 1,
      aux_sym_url_token1,
    STATE(39), 1,
      sym_identifier,
  [857] = 1,
    ACTIONS(232), 2,
      anon_sym_COLON,
      anon_sym_LPAREN,
  [862] = 1,
    ACTIONS(234), 2,
      sym__dedent,
      aux_sym_url_token1,
  [867] = 2,
    ACTIONS(236), 1,
      aux_sym_url_token1,
    STATE(44), 1,
      sym_url,
  [874] = 2,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    STATE(33), 1,
      sym_identifier,
  [881] = 1,
    ACTIONS(59), 2,
      sym__dedent,
      aux_sym_url_token1,
  [886] = 1,
    ACTIONS(209), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [891] = 2,
    ACTIONS(238), 1,
      aux_sym_url_token1,
    STATE(72), 1,
      sym_identifier,
  [898] = 1,
    ACTIONS(240), 2,
      ts_builtin_sym_end,
      anon_sym_enum,
  [903] = 2,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    STATE(80), 1,
      sym_identifier,
  [910] = 2,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    STATE(99), 1,
      sym_type_list,
  [917] = 1,
    ACTIONS(244), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [922] = 1,
    ACTIONS(246), 2,
      anon_sym_COLON,
      anon_sym_LPAREN,
  [927] = 1,
    ACTIONS(209), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [932] = 2,
    ACTIONS(226), 1,
      aux_sym_url_token1,
    STATE(76), 1,
      sym_identifier,
  [939] = 2,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    STATE(83), 1,
      sym_identifier,
  [946] = 1,
    ACTIONS(59), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [951] = 2,
    ACTIONS(226), 1,
      aux_sym_url_token1,
    STATE(53), 1,
      sym_identifier,
  [958] = 1,
    ACTIONS(248), 2,
      ts_builtin_sym_end,
      anon_sym_enum,
  [963] = 1,
    ACTIONS(250), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [968] = 2,
    ACTIONS(252), 1,
      aux_sym_url_token1,
    STATE(27), 1,
      sym_identifier,
  [975] = 1,
    ACTIONS(202), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [980] = 1,
    ACTIONS(254), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [985] = 2,
    ACTIONS(97), 1,
      aux_sym_url_token1,
    STATE(65), 1,
      sym_identifier,
  [992] = 1,
    ACTIONS(256), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [997] = 1,
    ACTIONS(258), 2,
      sym__dedent,
      sym_enum_identifier,
  [1002] = 1,
    ACTIONS(260), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1007] = 1,
    ACTIONS(262), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1012] = 1,
    ACTIONS(149), 1,
      anon_sym_SQUOTE,
  [1016] = 1,
    ACTIONS(264), 1,
      anon_sym_COLON,
  [1020] = 1,
    ACTIONS(266), 1,
      sym__indent,
  [1024] = 1,
    ACTIONS(268), 1,
      anon_sym_COLON,
  [1028] = 1,
    ACTIONS(270), 1,
      sym__indent,
  [1032] = 1,
    ACTIONS(272), 1,
      anon_sym_COLON,
  [1036] = 1,
    ACTIONS(274), 1,
      sym__indent,
  [1040] = 1,
    ACTIONS(105), 1,
      anon_sym_SQUOTE,
  [1044] = 1,
    ACTIONS(276), 1,
      aux_sym__uni_character_literal_token1,
  [1048] = 1,
    ACTIONS(278), 1,
      anon_sym_SQUOTE,
  [1052] = 1,
    ACTIONS(280), 1,
      anon_sym_COLON,
  [1056] = 1,
    ACTIONS(282), 1,
      anon_sym_COLON,
  [1060] = 1,
    ACTIONS(284), 1,
      sym__indent,
  [1064] = 1,
    ACTIONS(286), 1,
      aux_sym_url_token1,
  [1068] = 1,
    ACTIONS(288), 1,
      sym__indent,
  [1072] = 1,
    ACTIONS(290), 1,
      anon_sym_COLON,
  [1076] = 1,
    ACTIONS(292), 1,
      ts_builtin_sym_end,
  [1080] = 1,
    ACTIONS(294), 1,
      anon_sym_COLON,
  [1084] = 1,
    ACTIONS(296), 1,
      anon_sym_COLON,
  [1088] = 1,
    ACTIONS(298), 1,
      aux_sym__uni_character_literal_token1,
  [1092] = 1,
    ACTIONS(300), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 32,
  [SMALL_STATE(4)] = 64,
  [SMALL_STATE(5)] = 89,
  [SMALL_STATE(6)] = 114,
  [SMALL_STATE(7)] = 139,
  [SMALL_STATE(8)] = 164,
  [SMALL_STATE(9)] = 189,
  [SMALL_STATE(10)] = 201,
  [SMALL_STATE(11)] = 217,
  [SMALL_STATE(12)] = 233,
  [SMALL_STATE(13)] = 249,
  [SMALL_STATE(14)] = 267,
  [SMALL_STATE(15)] = 285,
  [SMALL_STATE(16)] = 298,
  [SMALL_STATE(17)] = 311,
  [SMALL_STATE(18)] = 324,
  [SMALL_STATE(19)] = 337,
  [SMALL_STATE(20)] = 351,
  [SMALL_STATE(21)] = 365,
  [SMALL_STATE(22)] = 375,
  [SMALL_STATE(23)] = 389,
  [SMALL_STATE(24)] = 401,
  [SMALL_STATE(25)] = 415,
  [SMALL_STATE(26)] = 429,
  [SMALL_STATE(27)] = 443,
  [SMALL_STATE(28)] = 453,
  [SMALL_STATE(29)] = 467,
  [SMALL_STATE(30)] = 481,
  [SMALL_STATE(31)] = 495,
  [SMALL_STATE(32)] = 511,
  [SMALL_STATE(33)] = 519,
  [SMALL_STATE(34)] = 535,
  [SMALL_STATE(35)] = 545,
  [SMALL_STATE(36)] = 555,
  [SMALL_STATE(37)] = 566,
  [SMALL_STATE(38)] = 577,
  [SMALL_STATE(39)] = 588,
  [SMALL_STATE(40)] = 595,
  [SMALL_STATE(41)] = 606,
  [SMALL_STATE(42)] = 617,
  [SMALL_STATE(43)] = 624,
  [SMALL_STATE(44)] = 635,
  [SMALL_STATE(45)] = 642,
  [SMALL_STATE(46)] = 649,
  [SMALL_STATE(47)] = 660,
  [SMALL_STATE(48)] = 666,
  [SMALL_STATE(49)] = 672,
  [SMALL_STATE(50)] = 682,
  [SMALL_STATE(51)] = 688,
  [SMALL_STATE(52)] = 698,
  [SMALL_STATE(53)] = 708,
  [SMALL_STATE(54)] = 718,
  [SMALL_STATE(55)] = 728,
  [SMALL_STATE(56)] = 738,
  [SMALL_STATE(57)] = 748,
  [SMALL_STATE(58)] = 754,
  [SMALL_STATE(59)] = 764,
  [SMALL_STATE(60)] = 770,
  [SMALL_STATE(61)] = 780,
  [SMALL_STATE(62)] = 786,
  [SMALL_STATE(63)] = 796,
  [SMALL_STATE(64)] = 802,
  [SMALL_STATE(65)] = 812,
  [SMALL_STATE(66)] = 822,
  [SMALL_STATE(67)] = 832,
  [SMALL_STATE(68)] = 838,
  [SMALL_STATE(69)] = 845,
  [SMALL_STATE(70)] = 850,
  [SMALL_STATE(71)] = 857,
  [SMALL_STATE(72)] = 862,
  [SMALL_STATE(73)] = 867,
  [SMALL_STATE(74)] = 874,
  [SMALL_STATE(75)] = 881,
  [SMALL_STATE(76)] = 886,
  [SMALL_STATE(77)] = 891,
  [SMALL_STATE(78)] = 898,
  [SMALL_STATE(79)] = 903,
  [SMALL_STATE(80)] = 910,
  [SMALL_STATE(81)] = 917,
  [SMALL_STATE(82)] = 922,
  [SMALL_STATE(83)] = 927,
  [SMALL_STATE(84)] = 932,
  [SMALL_STATE(85)] = 939,
  [SMALL_STATE(86)] = 946,
  [SMALL_STATE(87)] = 951,
  [SMALL_STATE(88)] = 958,
  [SMALL_STATE(89)] = 963,
  [SMALL_STATE(90)] = 968,
  [SMALL_STATE(91)] = 975,
  [SMALL_STATE(92)] = 980,
  [SMALL_STATE(93)] = 985,
  [SMALL_STATE(94)] = 992,
  [SMALL_STATE(95)] = 997,
  [SMALL_STATE(96)] = 1002,
  [SMALL_STATE(97)] = 1007,
  [SMALL_STATE(98)] = 1012,
  [SMALL_STATE(99)] = 1016,
  [SMALL_STATE(100)] = 1020,
  [SMALL_STATE(101)] = 1024,
  [SMALL_STATE(102)] = 1028,
  [SMALL_STATE(103)] = 1032,
  [SMALL_STATE(104)] = 1036,
  [SMALL_STATE(105)] = 1040,
  [SMALL_STATE(106)] = 1044,
  [SMALL_STATE(107)] = 1048,
  [SMALL_STATE(108)] = 1052,
  [SMALL_STATE(109)] = 1056,
  [SMALL_STATE(110)] = 1060,
  [SMALL_STATE(111)] = 1064,
  [SMALL_STATE(112)] = 1068,
  [SMALL_STATE(113)] = 1072,
  [SMALL_STATE(114)] = 1076,
  [SMALL_STATE(115)] = 1080,
  [SMALL_STATE(116)] = 1084,
  [SMALL_STATE(117)] = 1088,
  [SMALL_STATE(118)] = 1092,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(117),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(21),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(8),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(90),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_multi_line_string_literal_repeat1, 2), SHIFT_REPEAT(10),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_multi_line_string_literal_repeat1, 2),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_multi_line_string_literal_repeat1, 2), SHIFT_REPEAT(70),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 4),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_url_repeat1, 2),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_url_repeat1, 2), SHIFT_REPEAT(111),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_url, 1),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_url, 2),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(73),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character_escape_seq, 1),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_escape_seq, 1),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat2, 2),
  [111] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat2, 2), SHIFT_REPEAT(74),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [118] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_class_definition_repeat1, 2), SHIFT_REPEAT(9),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_class_definition_repeat1, 2),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__interpolation, 2, .production_id = 12),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__interpolation, 2, .production_id = 12),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__uni_character_literal, 2),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__uni_character_literal, 2),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_definition_repeat1, 2), SHIFT_REPEAT(118),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_definition_repeat1, 2),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat3, 2),
  [162] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat3, 2), SHIFT_REPEAT(79),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 2),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package, 1),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 5),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 5, .production_id = 1),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 7, .production_id = 8),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 8, .production_id = 11),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 6, .production_id = 2),
  [199] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_field_repeat1, 2), SHIFT_REPEAT(3),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_field_repeat1, 2),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 7, .production_id = 9),
  [206] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_list_repeat1, 2), SHIFT_REPEAT(84),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_list_repeat1, 2),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 6, .production_id = 3),
  [213] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_list_repeat1, 2), SHIFT_REPEAT(85),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 6, .production_id = 4),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 7, .production_id = 7),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_field, 5),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_list, 4),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_field, 3, .production_id = 6),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 7, .production_id = 10),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_list, 3),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 6, .production_id = 5),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line_string_literal, 2),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_line_string_literal, 2),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_line_string_literal, 3),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_field, 4),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line_string_literal, 3),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_literal, 3),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trait_list, 3),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_list, 3),
  [292] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_list, 4),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trait_list, 4),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_pine_external_scanner_create(void);
void tree_sitter_pine_external_scanner_destroy(void *);
bool tree_sitter_pine_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_pine_external_scanner_serialize(void *, char *);
void tree_sitter_pine_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_pine(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_pine_external_scanner_create,
      tree_sitter_pine_external_scanner_destroy,
      tree_sitter_pine_external_scanner_scan,
      tree_sitter_pine_external_scanner_serialize,
      tree_sitter_pine_external_scanner_deserialize,
    },
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
