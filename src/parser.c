#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 120
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 78
#define ALIAS_COUNT 1
#define TOKEN_COUNT 43
#define EXTERNAL_TOKEN_COUNT 10
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 13

enum {
  anon_sym_package = 1,
  anon_sym_import = 2,
  anon_sym_class = 3,
  anon_sym_COLON = 4,
  anon_sym_enum = 5,
  anon_sym_QMARK = 6,
  anon_sym_LPAREN = 7,
  anon_sym_COMMA = 8,
  anon_sym_RPAREN = 9,
  anon_sym_LT = 10,
  anon_sym_GT = 11,
  aux_sym_url_token1 = 12,
  anon_sym_SLASH = 13,
  sym_definition_name = 14,
  sym_variable_name = 15,
  sym_enum_field_name = 16,
  anon_sym_true = 17,
  anon_sym_false = 18,
  sym_integer_literal = 19,
  sym_hex_literal = 20,
  sym_bin_literal = 21,
  sym_float_literal = 22,
  anon_sym_SQUOTE = 23,
  aux_sym_character_literal_token1 = 24,
  anon_sym_BSLASHu = 25,
  aux_sym__uni_character_literal_token1 = 26,
  sym__escaped_identifier = 27,
  anon_sym_DQUOTE = 28,
  anon_sym_BQUOTE = 29,
  sym__line_str_text = 30,
  sym__multi_line_str_text = 31,
  anon_sym_DOLLAR = 32,
  anon_sym_null = 33,
  anon_sym_RBRACK = 34,
  anon_sym_RBRACE = 35,
  sym__newline = 36,
  sym__indent = 37,
  sym__dedent = 38,
  sym__string_start = 39,
  sym__string_content = 40,
  sym__string_end = 41,
  sym_comment = 42,
  sym_source_file = 43,
  sym_import_statement = 44,
  sym_class_definition = 45,
  sym_enum_definition = 46,
  sym_type = 47,
  sym_type_list = 48,
  sym_trait_list = 49,
  sym_generic_list = 50,
  sym_class_field = 51,
  sym_enum_field = 52,
  sym__primary_expression = 53,
  sym_url = 54,
  sym_package = 55,
  sym_identifier = 56,
  sym_boolean_literal = 57,
  sym_character_literal = 58,
  sym_character_escape_seq = 59,
  sym__uni_character_literal = 60,
  sym__string_literal = 61,
  sym_line_string_literal = 62,
  sym_multi_line_string_literal = 63,
  sym__line_string_content = 64,
  sym__multi_line_string_content = 65,
  sym__interpolation = 66,
  sym__literal_constant = 67,
  aux_sym_source_file_repeat1 = 68,
  aux_sym_source_file_repeat2 = 69,
  aux_sym_source_file_repeat3 = 70,
  aux_sym_class_definition_repeat1 = 71,
  aux_sym_enum_definition_repeat1 = 72,
  aux_sym_type_list_repeat1 = 73,
  aux_sym_enum_field_repeat1 = 74,
  aux_sym_url_repeat1 = 75,
  aux_sym_line_string_literal_repeat1 = 76,
  aux_sym_multi_line_string_literal_repeat1 = 77,
  alias_sym_interpolated_identifier = 78,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_package] = "package",
  [anon_sym_import] = "import",
  [anon_sym_class] = "class",
  [anon_sym_COLON] = ":",
  [anon_sym_enum] = "enum",
  [anon_sym_QMARK] = "\?",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [aux_sym_url_token1] = "url_token1",
  [anon_sym_SLASH] = "/",
  [sym_definition_name] = "definition_name",
  [sym_variable_name] = "variable_name",
  [sym_enum_field_name] = "enum_field_name",
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
  [sym_type] = "type",
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
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [aux_sym_url_token1] = aux_sym_url_token1,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [sym_definition_name] = sym_definition_name,
  [sym_variable_name] = sym_variable_name,
  [sym_enum_field_name] = sym_enum_field_name,
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
  [sym_type] = sym_type,
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
  [anon_sym_QMARK] = {
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
  [sym_definition_name] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_name] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_field_name] = {
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
  [sym_type] = {
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
  field_name = 3,
  field_traits = 4,
  field_type = 5,
  field_types = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_fields] = "fields",
  [field_generics] = "generics",
  [field_name] = "name",
  [field_traits] = "traits",
  [field_type] = "type",
  [field_types] = "types",
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
    {field_name, 0},
    {field_type, 2},
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
      if (eof) ADVANCE(51);
      if (lookahead == '"') ADVANCE(97);
      if (lookahead == '$') ADVANCE(104);
      if (lookahead == '\'') ADVANCE(91);
      if (lookahead == '(') ADVANCE(58);
      if (lookahead == ')') ADVANCE(60);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == '0') ADVANCE(81);
      if (lookahead == ':') ADVANCE(55);
      if (lookahead == '<') ADVANCE(61);
      if (lookahead == '>') ADVANCE(62);
      if (lookahead == '?') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(38);
      if (lookahead == ']') ADVANCE(106);
      if (lookahead == '_') ADVANCE(76);
      if (lookahead == '`') ADVANCE(98);
      if (lookahead == 'c') ADVANCE(23);
      if (lookahead == 'e') ADVANCE(29);
      if (lookahead == 'f') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(27);
      if (lookahead == 'n') ADVANCE(39);
      if (lookahead == 'p') ADVANCE(11);
      if (lookahead == 't') ADVANCE(33);
      if (lookahead == '}') ADVANCE(107);
      if (('a' <= lookahead && lookahead <= 'd')) ADVANCE(50);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'F')) ADVANCE(67);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(84);
      if (('G' <= lookahead && lookahead <= 'Z')) ADVANCE(71);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(97);
      if (lookahead == '$') ADVANCE(104);
      if (lookahead == '\\') ADVANCE(38);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(100);
      if (lookahead != 0) ADVANCE(101);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(97);
      if (lookahead == '$') ADVANCE(104);
      if (lookahead == '`') ADVANCE(99);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(102);
      if (lookahead != 0) ADVANCE(103);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(97);
      if (lookahead == '\'') ADVANCE(91);
      if (lookahead == '.') ADVANCE(46);
      if (lookahead == '0') ADVANCE(79);
      if (lookahead == '`') ADVANCE(98);
      if (lookahead == 'f') ADVANCE(15);
      if (lookahead == 'n') ADVANCE(39);
      if (lookahead == 't') ADVANCE(33);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(80);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(76);
      END_STATE();
    case 4:
      if (lookahead == '?') ADVANCE(57);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(70);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 5:
      if (lookahead == '\\') ADVANCE(38);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(93);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(5)
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(92);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(82);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(7);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(87);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(86);
      END_STATE();
    case 9:
      if (lookahead == '_') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 10:
      if (lookahead == '_') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(90);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(16);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(20);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(25);
      END_STATE();
    case 16:
      if (lookahead == 'c') ADVANCE(21);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(77);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 20:
      if (lookahead == 'g') ADVANCE(19);
      END_STATE();
    case 21:
      if (lookahead == 'k') ADVANCE(13);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(105);
      END_STATE();
    case 23:
      if (lookahead == 'l') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 24:
      if (lookahead == 'l') ADVANCE(22);
      END_STATE();
    case 25:
      if (lookahead == 'l') ADVANCE(35);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 27:
      if (lookahead == 'm') ADVANCE(31);
      END_STATE();
    case 28:
      if (lookahead == 'm') ADVANCE(56);
      END_STATE();
    case 29:
      if (lookahead == 'n') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 30:
      if (lookahead == 'o') ADVANCE(32);
      END_STATE();
    case 31:
      if (lookahead == 'p') ADVANCE(30);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 33:
      if (lookahead == 'r') ADVANCE(40);
      END_STATE();
    case 34:
      if (lookahead == 's') ADVANCE(54);
      END_STATE();
    case 35:
      if (lookahead == 's') ADVANCE(18);
      END_STATE();
    case 36:
      if (lookahead == 's') ADVANCE(34);
      END_STATE();
    case 37:
      if (lookahead == 't') ADVANCE(53);
      END_STATE();
    case 38:
      if (lookahead == 'u') ADVANCE(94);
      if (lookahead == '"' ||
          lookahead == '$' ||
          lookahead == '\'' ||
          lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't') ADVANCE(96);
      END_STATE();
    case 39:
      if (lookahead == 'u') ADVANCE(24);
      END_STATE();
    case 40:
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 41:
      if (lookahead == 'u') ADVANCE(28);
      END_STATE();
    case 42:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(88);
      if (('2' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 43:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(87);
      END_STATE();
    case 44:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(44)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 45:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(45)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(90);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(86);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(95);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 50:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_class);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_url_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_definition_name);
      if (('A' <= lookahead && lookahead <= 'F')) ADVANCE(68);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(48);
      if (('G' <= lookahead && lookahead <= 'Z')) ADVANCE(70);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_definition_name);
      if (('A' <= lookahead && lookahead <= 'F')) ADVANCE(70);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('G' <= lookahead && lookahead <= 'Z')) ADVANCE(70);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_definition_name);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(75);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(76);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_definition_name);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(95);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_definition_name);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(70);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_definition_name);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_definition_name);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(76);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_variable_name);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(73);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_variable_name);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_enum_field_name);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(76);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(76);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_enum_field_name);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(74);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(76);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_enum_field_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(46);
      if (lookahead == '_') ADVANCE(9);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(43);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(89);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(46);
      if (lookahead == '_') ADVANCE(9);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(6);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(42);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(47);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(85);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(82);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(82);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(95);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(85);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(83);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_bin_literal);
      if (lookahead == '_') ADVANCE(7);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_bin_literal);
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(95);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_float_literal);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(10);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(90);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(93);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(92);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_BSLASHu);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym__uni_character_literal_token1);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym__escaped_identifier);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$') ADVANCE(103);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym__line_str_text);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(100);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(101);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym__line_str_text);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(101);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym__multi_line_str_text);
      if (lookahead == '`') ADVANCE(99);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(102);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$') ADVANCE(103);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym__multi_line_str_text);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$') ADVANCE(103);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 107:
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
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 5},
  [27] = {.lex_state = 4, .external_lex_state = 2},
  [28] = {.lex_state = 3, .external_lex_state = 2},
  [29] = {.lex_state = 3, .external_lex_state = 2},
  [30] = {.lex_state = 4, .external_lex_state = 2},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 4, .external_lex_state = 2},
  [33] = {.lex_state = 4, .external_lex_state = 2},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 4, .external_lex_state = 2},
  [36] = {.lex_state = 3, .external_lex_state = 2},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 4, .external_lex_state = 2},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 4, .external_lex_state = 2},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 4, .external_lex_state = 2},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 4, .external_lex_state = 2},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0, .external_lex_state = 3},
  [49] = {.lex_state = 0, .external_lex_state = 3},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0, .external_lex_state = 3},
  [53] = {.lex_state = 0, .external_lex_state = 3},
  [54] = {.lex_state = 0, .external_lex_state = 3},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0, .external_lex_state = 3},
  [59] = {.lex_state = 4, .external_lex_state = 2},
  [60] = {.lex_state = 0, .external_lex_state = 3},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 44},
  [65] = {.lex_state = 0, .external_lex_state = 3},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0, .external_lex_state = 3},
  [70] = {.lex_state = 0, .external_lex_state = 3},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 44},
  [73] = {.lex_state = 4, .external_lex_state = 2},
  [74] = {.lex_state = 44},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 4},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 44},
  [81] = {.lex_state = 4, .external_lex_state = 2},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0, .external_lex_state = 3},
  [84] = {.lex_state = 0, .external_lex_state = 3},
  [85] = {.lex_state = 44},
  [86] = {.lex_state = 44},
  [87] = {.lex_state = 3, .external_lex_state = 2},
  [88] = {.lex_state = 44},
  [89] = {.lex_state = 0, .external_lex_state = 3},
  [90] = {.lex_state = 0, .external_lex_state = 3},
  [91] = {.lex_state = 0, .external_lex_state = 3},
  [92] = {.lex_state = 44},
  [93] = {.lex_state = 44},
  [94] = {.lex_state = 0, .external_lex_state = 3},
  [95] = {.lex_state = 0, .external_lex_state = 3},
  [96] = {.lex_state = 3, .external_lex_state = 2},
  [97] = {.lex_state = 0, .external_lex_state = 4},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0, .external_lex_state = 4},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 45},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0, .external_lex_state = 4},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0, .external_lex_state = 4},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0, .external_lex_state = 4},
  [113] = {.lex_state = 44},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 4},
  [116] = {.lex_state = 4},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 45},
  [119] = {.lex_state = 0},
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
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [sym_definition_name] = ACTIONS(1),
    [sym_enum_field_name] = ACTIONS(1),
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
    STATE(53), 7,
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
    STATE(70), 7,
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
    STATE(22), 1,
      sym__uni_character_literal,
    STATE(5), 4,
      sym_character_escape_seq,
      sym__line_string_content,
      sym__interpolation,
      aux_sym_line_string_literal_repeat1,
  [89] = 7,
    ACTIONS(31), 1,
      anon_sym_BSLASHu,
    ACTIONS(34), 1,
      sym__escaped_identifier,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(39), 1,
      sym__line_str_text,
    ACTIONS(42), 1,
      anon_sym_DOLLAR,
    STATE(22), 1,
      sym__uni_character_literal,
    STATE(5), 4,
      sym_character_escape_seq,
      sym__line_string_content,
      sym__interpolation,
      aux_sym_line_string_literal_repeat1,
  [114] = 7,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
    ACTIONS(47), 1,
      anon_sym_import,
    ACTIONS(49), 1,
      anon_sym_class,
    ACTIONS(51), 1,
      anon_sym_enum,
    STATE(7), 2,
      sym_import_statement,
      aux_sym_source_file_repeat1,
    STATE(10), 2,
      sym_class_definition,
      aux_sym_source_file_repeat2,
    STATE(43), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [139] = 7,
    ACTIONS(47), 1,
      anon_sym_import,
    ACTIONS(49), 1,
      anon_sym_class,
    ACTIONS(51), 1,
      anon_sym_enum,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    STATE(9), 2,
      sym_class_definition,
      aux_sym_source_file_repeat2,
    STATE(15), 2,
      sym_import_statement,
      aux_sym_source_file_repeat1,
    STATE(38), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [164] = 7,
    ACTIONS(21), 1,
      anon_sym_BSLASHu,
    ACTIONS(23), 1,
      sym__escaped_identifier,
    ACTIONS(29), 1,
      anon_sym_DOLLAR,
    ACTIONS(55), 1,
      anon_sym_DQUOTE,
    ACTIONS(57), 1,
      sym__line_str_text,
    STATE(22), 1,
      sym__uni_character_literal,
    STATE(4), 4,
      sym_character_escape_seq,
      sym__line_string_content,
      sym__interpolation,
      aux_sym_line_string_literal_repeat1,
  [189] = 5,
    ACTIONS(49), 1,
      anon_sym_class,
    ACTIONS(51), 1,
      anon_sym_enum,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
    STATE(24), 2,
      sym_class_definition,
      aux_sym_source_file_repeat2,
    STATE(31), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [207] = 5,
    ACTIONS(49), 1,
      anon_sym_class,
    ACTIONS(51), 1,
      anon_sym_enum,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    STATE(24), 2,
      sym_class_definition,
      aux_sym_source_file_repeat2,
    STATE(38), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [225] = 4,
    ACTIONS(63), 1,
      anon_sym_BQUOTE,
    ACTIONS(65), 1,
      anon_sym_DOLLAR,
    ACTIONS(61), 2,
      anon_sym_DQUOTE,
      sym__multi_line_str_text,
    STATE(12), 3,
      sym__multi_line_string_content,
      sym__interpolation,
      aux_sym_multi_line_string_literal_repeat1,
  [241] = 4,
    ACTIONS(65), 1,
      anon_sym_DOLLAR,
    ACTIONS(69), 1,
      anon_sym_BQUOTE,
    ACTIONS(67), 2,
      anon_sym_DQUOTE,
      sym__multi_line_str_text,
    STATE(13), 3,
      sym__multi_line_string_content,
      sym__interpolation,
      aux_sym_multi_line_string_literal_repeat1,
  [257] = 4,
    ACTIONS(74), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      anon_sym_DOLLAR,
    ACTIONS(71), 2,
      anon_sym_DQUOTE,
      sym__multi_line_str_text,
    STATE(13), 3,
      sym__multi_line_string_content,
      sym__interpolation,
      aux_sym_multi_line_string_literal_repeat1,
  [273] = 3,
    ACTIONS(81), 1,
      anon_sym_SLASH,
    STATE(17), 1,
      aux_sym_url_repeat1,
    ACTIONS(79), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
  [286] = 3,
    ACTIONS(85), 1,
      anon_sym_import,
    STATE(15), 2,
      sym_import_statement,
      aux_sym_source_file_repeat1,
    ACTIONS(83), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [299] = 3,
    ACTIONS(90), 1,
      anon_sym_SLASH,
    STATE(16), 1,
      aux_sym_url_repeat1,
    ACTIONS(88), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
  [312] = 3,
    ACTIONS(81), 1,
      anon_sym_SLASH,
    STATE(16), 1,
      aux_sym_url_repeat1,
    ACTIONS(93), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
  [325] = 1,
    ACTIONS(95), 6,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
      anon_sym_COMMA,
      anon_sym_GT,
  [334] = 2,
    ACTIONS(95), 1,
      sym__line_str_text,
    ACTIONS(97), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [344] = 2,
    ACTIONS(101), 1,
      sym__line_str_text,
    ACTIONS(99), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [354] = 5,
    ACTIONS(103), 1,
      anon_sym_COLON,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(107), 1,
      anon_sym_LT,
    STATE(66), 1,
      sym_generic_list,
    STATE(103), 1,
      sym_trait_list,
  [370] = 2,
    ACTIONS(111), 1,
      sym__line_str_text,
    ACTIONS(109), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [380] = 2,
    ACTIONS(115), 1,
      sym__line_str_text,
    ACTIONS(113), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [390] = 3,
    ACTIONS(119), 1,
      anon_sym_class,
    ACTIONS(117), 2,
      ts_builtin_sym_end,
      anon_sym_enum,
    STATE(24), 2,
      sym_class_definition,
      aux_sym_source_file_repeat2,
  [402] = 1,
    ACTIONS(88), 5,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
      anon_sym_SLASH,
  [410] = 5,
    ACTIONS(122), 1,
      aux_sym_character_literal_token1,
    ACTIONS(124), 1,
      anon_sym_BSLASHu,
    ACTIONS(126), 1,
      sym__escaped_identifier,
    STATE(102), 1,
      sym__uni_character_literal,
    STATE(105), 1,
      sym_character_escape_seq,
  [426] = 3,
    ACTIONS(128), 1,
      sym_variable_name,
    ACTIONS(130), 1,
      sym__dedent,
    STATE(44), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [437] = 3,
    ACTIONS(132), 1,
      sym_enum_field_name,
    ACTIONS(135), 1,
      sym__dedent,
    STATE(28), 2,
      sym_enum_field,
      aux_sym_enum_definition_repeat1,
  [448] = 3,
    ACTIONS(137), 1,
      sym_enum_field_name,
    ACTIONS(139), 1,
      sym__dedent,
    STATE(28), 2,
      sym_enum_field,
      aux_sym_enum_definition_repeat1,
  [459] = 3,
    ACTIONS(128), 1,
      sym_variable_name,
    ACTIONS(141), 1,
      sym__dedent,
    STATE(39), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [470] = 3,
    ACTIONS(51), 1,
      anon_sym_enum,
    ACTIONS(143), 1,
      ts_builtin_sym_end,
    STATE(37), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [481] = 3,
    ACTIONS(128), 1,
      sym_variable_name,
    ACTIONS(145), 1,
      sym__dedent,
    STATE(35), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [492] = 3,
    ACTIONS(128), 1,
      sym_variable_name,
    ACTIONS(147), 1,
      sym__dedent,
    STATE(35), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [503] = 1,
    ACTIONS(97), 4,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym__multi_line_str_text,
      anon_sym_DOLLAR,
  [510] = 3,
    ACTIONS(149), 1,
      sym_variable_name,
    ACTIONS(152), 1,
      sym__dedent,
    STATE(35), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [521] = 3,
    ACTIONS(137), 1,
      sym_enum_field_name,
    ACTIONS(154), 1,
      sym__dedent,
    STATE(29), 2,
      sym_enum_field,
      aux_sym_enum_definition_repeat1,
  [532] = 3,
    ACTIONS(156), 1,
      ts_builtin_sym_end,
    ACTIONS(158), 1,
      anon_sym_enum,
    STATE(37), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [543] = 3,
    ACTIONS(51), 1,
      anon_sym_enum,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
    STATE(37), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [554] = 3,
    ACTIONS(128), 1,
      sym_variable_name,
    ACTIONS(161), 1,
      sym__dedent,
    STATE(35), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [565] = 1,
    ACTIONS(163), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
  [572] = 1,
    ACTIONS(165), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_enum,
  [579] = 3,
    ACTIONS(128), 1,
      sym_variable_name,
    ACTIONS(167), 1,
      sym__dedent,
    STATE(32), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [590] = 3,
    ACTIONS(51), 1,
      anon_sym_enum,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    STATE(37), 2,
      sym_enum_definition,
      aux_sym_source_file_repeat3,
  [601] = 3,
    ACTIONS(128), 1,
      sym_variable_name,
    ACTIONS(169), 1,
      sym__dedent,
    STATE(35), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [612] = 1,
    ACTIONS(113), 4,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym__multi_line_str_text,
      anon_sym_DOLLAR,
  [619] = 3,
    ACTIONS(128), 1,
      sym_variable_name,
    ACTIONS(171), 1,
      sym__dedent,
    STATE(33), 2,
      sym_class_field,
      aux_sym_class_definition_repeat1,
  [630] = 1,
    ACTIONS(173), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [636] = 3,
    ACTIONS(175), 1,
      anon_sym_COMMA,
    ACTIONS(177), 1,
      anon_sym_RPAREN,
    STATE(54), 1,
      aux_sym_type_list_repeat1,
  [646] = 3,
    ACTIONS(175), 1,
      anon_sym_COMMA,
    ACTIONS(179), 1,
      anon_sym_RPAREN,
    STATE(60), 1,
      aux_sym_type_list_repeat1,
  [656] = 1,
    ACTIONS(181), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [662] = 1,
    ACTIONS(183), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [668] = 3,
    ACTIONS(175), 1,
      anon_sym_COMMA,
    ACTIONS(185), 1,
      anon_sym_RPAREN,
    STATE(49), 1,
      aux_sym_type_list_repeat1,
  [678] = 3,
    ACTIONS(187), 1,
      anon_sym_COMMA,
    ACTIONS(189), 1,
      anon_sym_RPAREN,
    STATE(65), 1,
      aux_sym_enum_field_repeat1,
  [688] = 3,
    ACTIONS(175), 1,
      anon_sym_COMMA,
    ACTIONS(191), 1,
      anon_sym_RPAREN,
    STATE(60), 1,
      aux_sym_type_list_repeat1,
  [698] = 3,
    ACTIONS(193), 1,
      anon_sym_COMMA,
    ACTIONS(195), 1,
      anon_sym_GT,
    STATE(57), 1,
      aux_sym_type_list_repeat1,
  [708] = 1,
    ACTIONS(197), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [714] = 3,
    ACTIONS(193), 1,
      anon_sym_COMMA,
    ACTIONS(199), 1,
      anon_sym_GT,
    STATE(62), 1,
      aux_sym_type_list_repeat1,
  [724] = 3,
    ACTIONS(201), 1,
      anon_sym_COMMA,
    ACTIONS(204), 1,
      anon_sym_RPAREN,
    STATE(58), 1,
      aux_sym_enum_field_repeat1,
  [734] = 2,
    ACTIONS(206), 1,
      anon_sym_QMARK,
    ACTIONS(208), 2,
      sym__dedent,
      sym_variable_name,
  [742] = 3,
    ACTIONS(210), 1,
      anon_sym_COMMA,
    ACTIONS(213), 1,
      anon_sym_RPAREN,
    STATE(60), 1,
      aux_sym_type_list_repeat1,
  [752] = 1,
    ACTIONS(215), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [758] = 3,
    ACTIONS(213), 1,
      anon_sym_GT,
    ACTIONS(217), 1,
      anon_sym_COMMA,
    STATE(62), 1,
      aux_sym_type_list_repeat1,
  [768] = 1,
    ACTIONS(220), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [774] = 3,
    ACTIONS(222), 1,
      aux_sym_url_token1,
    STATE(6), 1,
      sym_package,
    STATE(40), 1,
      sym_identifier,
  [784] = 3,
    ACTIONS(187), 1,
      anon_sym_COMMA,
    ACTIONS(224), 1,
      anon_sym_RPAREN,
    STATE(58), 1,
      aux_sym_enum_field_repeat1,
  [794] = 3,
    ACTIONS(105), 1,
      anon_sym_LPAREN,
    ACTIONS(226), 1,
      anon_sym_COLON,
    STATE(101), 1,
      sym_trait_list,
  [804] = 1,
    ACTIONS(228), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [810] = 1,
    ACTIONS(230), 3,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_enum,
  [816] = 1,
    ACTIONS(213), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [821] = 1,
    ACTIONS(204), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [826] = 1,
    ACTIONS(232), 2,
      anon_sym_COLON,
      anon_sym_LPAREN,
  [831] = 2,
    ACTIONS(234), 1,
      aux_sym_url_token1,
    STATE(45), 1,
      sym_identifier,
  [838] = 1,
    ACTIONS(236), 2,
      sym__dedent,
      sym_variable_name,
  [843] = 2,
    ACTIONS(238), 1,
      aux_sym_url_token1,
    STATE(41), 1,
      sym_url,
  [850] = 1,
    ACTIONS(240), 2,
      ts_builtin_sym_end,
      anon_sym_enum,
  [855] = 2,
    ACTIONS(242), 1,
      anon_sym_LPAREN,
    STATE(98), 1,
      sym_type_list,
  [862] = 2,
    ACTIONS(244), 1,
      sym_definition_name,
    STATE(73), 1,
      sym_type,
  [869] = 1,
    ACTIONS(213), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [874] = 1,
    ACTIONS(246), 2,
      ts_builtin_sym_end,
      anon_sym_enum,
  [879] = 2,
    ACTIONS(222), 1,
      aux_sym_url_token1,
    STATE(78), 1,
      sym_identifier,
  [886] = 1,
    ACTIONS(248), 2,
      sym__dedent,
      sym_variable_name,
  [891] = 1,
    ACTIONS(250), 2,
      anon_sym_COLON,
      anon_sym_LPAREN,
  [896] = 1,
    ACTIONS(252), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [901] = 1,
    ACTIONS(95), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [906] = 2,
    ACTIONS(254), 1,
      aux_sym_url_token1,
    STATE(69), 1,
      sym_identifier,
  [913] = 2,
    ACTIONS(254), 1,
      aux_sym_url_token1,
    STATE(52), 1,
      sym_identifier,
  [920] = 1,
    ACTIONS(256), 2,
      sym__dedent,
      sym_enum_field_name,
  [925] = 2,
    ACTIONS(222), 1,
      aux_sym_url_token1,
    STATE(55), 1,
      sym_identifier,
  [932] = 1,
    ACTIONS(258), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [937] = 1,
    ACTIONS(260), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [942] = 1,
    ACTIONS(262), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [947] = 2,
    ACTIONS(264), 1,
      aux_sym_url_token1,
    STATE(23), 1,
      sym_identifier,
  [954] = 2,
    ACTIONS(254), 1,
      aux_sym_url_token1,
    STATE(48), 1,
      sym_identifier,
  [961] = 1,
    ACTIONS(266), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [966] = 1,
    ACTIONS(268), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [971] = 1,
    ACTIONS(270), 2,
      sym__dedent,
      sym_enum_field_name,
  [976] = 1,
    ACTIONS(272), 1,
      sym__indent,
  [980] = 1,
    ACTIONS(274), 1,
      anon_sym_COLON,
  [984] = 1,
    ACTIONS(276), 1,
      sym__indent,
  [988] = 1,
    ACTIONS(101), 1,
      anon_sym_SQUOTE,
  [992] = 1,
    ACTIONS(278), 1,
      anon_sym_COLON,
  [996] = 1,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
  [1000] = 1,
    ACTIONS(280), 1,
      anon_sym_COLON,
  [1004] = 1,
    ACTIONS(282), 1,
      aux_sym__uni_character_literal_token1,
  [1008] = 1,
    ACTIONS(284), 1,
      anon_sym_SQUOTE,
  [1012] = 1,
    ACTIONS(286), 1,
      anon_sym_LPAREN,
  [1016] = 1,
    ACTIONS(288), 1,
      sym__indent,
  [1020] = 1,
    ACTIONS(290), 1,
      anon_sym_COLON,
  [1024] = 1,
    ACTIONS(292), 1,
      anon_sym_COLON,
  [1028] = 1,
    ACTIONS(294), 1,
      sym__indent,
  [1032] = 1,
    ACTIONS(296), 1,
      anon_sym_COLON,
  [1036] = 1,
    ACTIONS(298), 1,
      sym__indent,
  [1040] = 1,
    ACTIONS(300), 1,
      aux_sym_url_token1,
  [1044] = 1,
    ACTIONS(302), 1,
      ts_builtin_sym_end,
  [1048] = 1,
    ACTIONS(304), 1,
      sym_definition_name,
  [1052] = 1,
    ACTIONS(306), 1,
      sym_definition_name,
  [1056] = 1,
    ACTIONS(308), 1,
      anon_sym_COLON,
  [1060] = 1,
    ACTIONS(310), 1,
      aux_sym__uni_character_literal_token1,
  [1064] = 1,
    ACTIONS(312), 1,
      anon_sym_COLON,
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
  [SMALL_STATE(10)] = 207,
  [SMALL_STATE(11)] = 225,
  [SMALL_STATE(12)] = 241,
  [SMALL_STATE(13)] = 257,
  [SMALL_STATE(14)] = 273,
  [SMALL_STATE(15)] = 286,
  [SMALL_STATE(16)] = 299,
  [SMALL_STATE(17)] = 312,
  [SMALL_STATE(18)] = 325,
  [SMALL_STATE(19)] = 334,
  [SMALL_STATE(20)] = 344,
  [SMALL_STATE(21)] = 354,
  [SMALL_STATE(22)] = 370,
  [SMALL_STATE(23)] = 380,
  [SMALL_STATE(24)] = 390,
  [SMALL_STATE(25)] = 402,
  [SMALL_STATE(26)] = 410,
  [SMALL_STATE(27)] = 426,
  [SMALL_STATE(28)] = 437,
  [SMALL_STATE(29)] = 448,
  [SMALL_STATE(30)] = 459,
  [SMALL_STATE(31)] = 470,
  [SMALL_STATE(32)] = 481,
  [SMALL_STATE(33)] = 492,
  [SMALL_STATE(34)] = 503,
  [SMALL_STATE(35)] = 510,
  [SMALL_STATE(36)] = 521,
  [SMALL_STATE(37)] = 532,
  [SMALL_STATE(38)] = 543,
  [SMALL_STATE(39)] = 554,
  [SMALL_STATE(40)] = 565,
  [SMALL_STATE(41)] = 572,
  [SMALL_STATE(42)] = 579,
  [SMALL_STATE(43)] = 590,
  [SMALL_STATE(44)] = 601,
  [SMALL_STATE(45)] = 612,
  [SMALL_STATE(46)] = 619,
  [SMALL_STATE(47)] = 630,
  [SMALL_STATE(48)] = 636,
  [SMALL_STATE(49)] = 646,
  [SMALL_STATE(50)] = 656,
  [SMALL_STATE(51)] = 662,
  [SMALL_STATE(52)] = 668,
  [SMALL_STATE(53)] = 678,
  [SMALL_STATE(54)] = 688,
  [SMALL_STATE(55)] = 698,
  [SMALL_STATE(56)] = 708,
  [SMALL_STATE(57)] = 714,
  [SMALL_STATE(58)] = 724,
  [SMALL_STATE(59)] = 734,
  [SMALL_STATE(60)] = 742,
  [SMALL_STATE(61)] = 752,
  [SMALL_STATE(62)] = 758,
  [SMALL_STATE(63)] = 768,
  [SMALL_STATE(64)] = 774,
  [SMALL_STATE(65)] = 784,
  [SMALL_STATE(66)] = 794,
  [SMALL_STATE(67)] = 804,
  [SMALL_STATE(68)] = 810,
  [SMALL_STATE(69)] = 816,
  [SMALL_STATE(70)] = 821,
  [SMALL_STATE(71)] = 826,
  [SMALL_STATE(72)] = 831,
  [SMALL_STATE(73)] = 838,
  [SMALL_STATE(74)] = 843,
  [SMALL_STATE(75)] = 850,
  [SMALL_STATE(76)] = 855,
  [SMALL_STATE(77)] = 862,
  [SMALL_STATE(78)] = 869,
  [SMALL_STATE(79)] = 874,
  [SMALL_STATE(80)] = 879,
  [SMALL_STATE(81)] = 886,
  [SMALL_STATE(82)] = 891,
  [SMALL_STATE(83)] = 896,
  [SMALL_STATE(84)] = 901,
  [SMALL_STATE(85)] = 906,
  [SMALL_STATE(86)] = 913,
  [SMALL_STATE(87)] = 920,
  [SMALL_STATE(88)] = 925,
  [SMALL_STATE(89)] = 932,
  [SMALL_STATE(90)] = 937,
  [SMALL_STATE(91)] = 942,
  [SMALL_STATE(92)] = 947,
  [SMALL_STATE(93)] = 954,
  [SMALL_STATE(94)] = 961,
  [SMALL_STATE(95)] = 966,
  [SMALL_STATE(96)] = 971,
  [SMALL_STATE(97)] = 976,
  [SMALL_STATE(98)] = 980,
  [SMALL_STATE(99)] = 984,
  [SMALL_STATE(100)] = 988,
  [SMALL_STATE(101)] = 992,
  [SMALL_STATE(102)] = 996,
  [SMALL_STATE(103)] = 1000,
  [SMALL_STATE(104)] = 1004,
  [SMALL_STATE(105)] = 1008,
  [SMALL_STATE(106)] = 1012,
  [SMALL_STATE(107)] = 1016,
  [SMALL_STATE(108)] = 1020,
  [SMALL_STATE(109)] = 1024,
  [SMALL_STATE(110)] = 1028,
  [SMALL_STATE(111)] = 1032,
  [SMALL_STATE(112)] = 1036,
  [SMALL_STATE(113)] = 1040,
  [SMALL_STATE(114)] = 1044,
  [SMALL_STATE(115)] = 1048,
  [SMALL_STATE(116)] = 1052,
  [SMALL_STATE(117)] = 1056,
  [SMALL_STATE(118)] = 1060,
  [SMALL_STATE(119)] = 1064,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(118),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(22),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(5),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(92),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 4),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_multi_line_string_literal_repeat1, 2), SHIFT_REPEAT(13),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_multi_line_string_literal_repeat1, 2),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_multi_line_string_literal_repeat1, 2), SHIFT_REPEAT(72),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_url, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(74),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_url_repeat1, 2),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_url_repeat1, 2), SHIFT_REPEAT(113),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_url, 2),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__uni_character_literal, 2),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__uni_character_literal, 2),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character_escape_seq, 1),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_escape_seq, 1),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__interpolation, 2, .production_id = 12),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__interpolation, 2, .production_id = 12),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat2, 2),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat2, 2), SHIFT_REPEAT(116),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [132] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_definition_repeat1, 2), SHIFT_REPEAT(106),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_definition_repeat1, 2),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 5),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [149] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_class_definition_repeat1, 2), SHIFT_REPEAT(108),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_class_definition_repeat1, 2),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat3, 2),
  [158] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat3, 2), SHIFT_REPEAT(115),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package, 1),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 2),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 6, .production_id = 2),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 8, .production_id = 11),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 5, .production_id = 1),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 7, .production_id = 9),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [201] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_field_repeat1, 2), SHIFT_REPEAT(3),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_field_repeat1, 2),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [210] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_list_repeat1, 2), SHIFT_REPEAT(85),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_list_repeat1, 2),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 6, .production_id = 3),
  [217] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_list_repeat1, 2), SHIFT_REPEAT(80),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 6, .production_id = 4),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 7, .production_id = 8),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 7, .production_id = 7),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_list, 4),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_field, 3, .production_id = 6),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 6, .production_id = 5),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 7, .production_id = 10),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 2),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_list, 3),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_field, 5),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_line_string_literal, 3),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line_string_literal, 3),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line_string_literal, 2),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_line_string_literal, 2),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_literal, 3),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_field, 4),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trait_list, 3),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_list, 3),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [302] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_list, 4),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trait_list, 4),
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
