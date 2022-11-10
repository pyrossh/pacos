#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 203
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 86
#define ALIAS_COUNT 1
#define TOKEN_COUNT 42
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 8
#define MAX_ALIAS_SEQUENCE_LENGTH 11
#define PRODUCTION_ID_COUNT 25

enum {
  anon_sym_package = 1,
  anon_sym_import = 2,
  anon_sym_class = 3,
  anon_sym_LPAREN = 4,
  anon_sym_COMMA = 5,
  anon_sym_RPAREN = 6,
  anon_sym_trait = 7,
  anon_sym_enum = 8,
  anon_sym_LBRACE = 9,
  anon_sym_RBRACE = 10,
  anon_sym_fun = 11,
  anon_sym_EQ_GT = 12,
  anon_sym_AT = 13,
  anon_sym_LT = 14,
  anon_sym_GT = 15,
  anon_sym_QMARK = 16,
  anon_sym_COLON = 17,
  anon_sym_val = 18,
  anon_sym_DOT = 19,
  aux_sym_url_token1 = 20,
  anon_sym_SLASH = 21,
  sym_definition_name = 22,
  sym_variable_name = 23,
  sym_enum_field_name = 24,
  anon_sym_true = 25,
  anon_sym_false = 26,
  sym_integer_literal = 27,
  sym_hex_literal = 28,
  sym_bin_literal = 29,
  sym_float_literal = 30,
  anon_sym_SQUOTE = 31,
  aux_sym_character_literal_token1 = 32,
  anon_sym_BSLASHu = 33,
  aux_sym__uni_character_literal_token1 = 34,
  sym__escaped_identifier = 35,
  anon_sym_DQUOTE = 36,
  anon_sym_BQUOTE = 37,
  sym__line_str_text = 38,
  sym__multi_line_str_text = 39,
  anon_sym_DOLLAR = 40,
  anon_sym_null = 41,
  sym_source_file = 42,
  sym_import_statement = 43,
  sym_definitions = 44,
  sym_class_definition = 45,
  sym_trait_definition = 46,
  sym_enum_definition = 47,
  sym_fun_definition = 48,
  sym_trait_name = 49,
  sym_generic_list = 50,
  sym_type = 51,
  sym_param = 52,
  sym_type_field = 53,
  sym_fun_field = 54,
  sym_trait_field = 55,
  sym_enum_field = 56,
  sym__primary_expression = 57,
  sym__extension = 58,
  sym_url = 59,
  sym_package = 60,
  sym_identifier = 61,
  sym_boolean_literal = 62,
  sym_character_literal = 63,
  sym_character_escape_seq = 64,
  sym__uni_character_literal = 65,
  sym__string_literal = 66,
  sym_line_string_literal = 67,
  sym_multi_line_string_literal = 68,
  sym__line_string_content = 69,
  sym__multi_line_string_content = 70,
  sym__interpolation = 71,
  sym__literal_constant = 72,
  aux_sym_source_file_repeat1 = 73,
  aux_sym_source_file_repeat2 = 74,
  aux_sym_class_definition_repeat1 = 75,
  aux_sym_class_definition_repeat2 = 76,
  aux_sym_trait_definition_repeat1 = 77,
  aux_sym_enum_definition_repeat1 = 78,
  aux_sym_fun_definition_repeat1 = 79,
  aux_sym_fun_definition_repeat2 = 80,
  aux_sym_trait_list_repeat1 = 81,
  aux_sym_enum_field_repeat1 = 82,
  aux_sym_url_repeat1 = 83,
  aux_sym_line_string_literal_repeat1 = 84,
  aux_sym_multi_line_string_literal_repeat1 = 85,
  alias_sym_interpolated_identifier = 86,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_package] = "package",
  [anon_sym_import] = "import",
  [anon_sym_class] = "class",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_trait] = "trait",
  [anon_sym_enum] = "enum",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_fun] = "fun",
  [anon_sym_EQ_GT] = "=>",
  [anon_sym_AT] = "@",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_QMARK] = "\?",
  [anon_sym_COLON] = ":",
  [anon_sym_val] = "val",
  [anon_sym_DOT] = ".",
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
  [sym_source_file] = "source_file",
  [sym_import_statement] = "import_statement",
  [sym_definitions] = "definitions",
  [sym_class_definition] = "class_definition",
  [sym_trait_definition] = "trait_definition",
  [sym_enum_definition] = "enum_definition",
  [sym_fun_definition] = "fun_definition",
  [sym_trait_name] = "trait_name",
  [sym_generic_list] = "generic_list",
  [sym_type] = "type",
  [sym_param] = "param",
  [sym_type_field] = "type_field",
  [sym_fun_field] = "fun_field",
  [sym_trait_field] = "trait_field",
  [sym_enum_field] = "enum_field",
  [sym__primary_expression] = "_primary_expression",
  [sym__extension] = "_extension",
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
  [aux_sym_class_definition_repeat1] = "class_definition_repeat1",
  [aux_sym_class_definition_repeat2] = "class_definition_repeat2",
  [aux_sym_trait_definition_repeat1] = "trait_definition_repeat1",
  [aux_sym_enum_definition_repeat1] = "enum_definition_repeat1",
  [aux_sym_fun_definition_repeat1] = "fun_definition_repeat1",
  [aux_sym_fun_definition_repeat2] = "fun_definition_repeat2",
  [aux_sym_trait_list_repeat1] = "trait_list_repeat1",
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
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_trait] = anon_sym_trait,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_fun] = anon_sym_fun,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_val] = anon_sym_val,
  [anon_sym_DOT] = anon_sym_DOT,
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
  [sym_source_file] = sym_source_file,
  [sym_import_statement] = sym_import_statement,
  [sym_definitions] = sym_definitions,
  [sym_class_definition] = sym_class_definition,
  [sym_trait_definition] = sym_trait_definition,
  [sym_enum_definition] = sym_enum_definition,
  [sym_fun_definition] = sym_fun_definition,
  [sym_trait_name] = sym_trait_name,
  [sym_generic_list] = sym_generic_list,
  [sym_type] = sym_type,
  [sym_param] = sym_param,
  [sym_type_field] = sym_type_field,
  [sym_fun_field] = sym_fun_field,
  [sym_trait_field] = sym_trait_field,
  [sym_enum_field] = sym_enum_field,
  [sym__primary_expression] = sym__primary_expression,
  [sym__extension] = sym__extension,
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
  [aux_sym_class_definition_repeat1] = aux_sym_class_definition_repeat1,
  [aux_sym_class_definition_repeat2] = aux_sym_class_definition_repeat2,
  [aux_sym_trait_definition_repeat1] = aux_sym_trait_definition_repeat1,
  [aux_sym_enum_definition_repeat1] = aux_sym_enum_definition_repeat1,
  [aux_sym_fun_definition_repeat1] = aux_sym_fun_definition_repeat1,
  [aux_sym_fun_definition_repeat2] = aux_sym_fun_definition_repeat2,
  [aux_sym_trait_list_repeat1] = aux_sym_trait_list_repeat1,
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
  [anon_sym_trait] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fun] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
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
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_val] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
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
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_import_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_definitions] = {
    .visible = true,
    .named = true,
  },
  [sym_class_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_trait_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_fun_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_trait_name] = {
    .visible = true,
    .named = true,
  },
  [sym_generic_list] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_param] = {
    .visible = true,
    .named = true,
  },
  [sym_type_field] = {
    .visible = true,
    .named = true,
  },
  [sym_fun_field] = {
    .visible = true,
    .named = true,
  },
  [sym_trait_field] = {
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
  [sym__extension] = {
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
  [aux_sym_class_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_class_definition_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_trait_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_fun_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_fun_definition_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_trait_list_repeat1] = {
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
  field_params = 4,
  field_returns = 5,
  field_traits = 6,
  field_type = 7,
  field_types = 8,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_fields] = "fields",
  [field_generics] = "generics",
  [field_name] = "name",
  [field_params] = "params",
  [field_returns] = "returns",
  [field_traits] = "traits",
  [field_type] = "type",
  [field_types] = "types",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 4},
  [2] = {.index = 4, .length = 5},
  [3] = {.index = 9, .length = 5},
  [4] = {.index = 14, .length = 2},
  [5] = {.index = 16, .length = 5},
  [6] = {.index = 21, .length = 2},
  [7] = {.index = 23, .length = 6},
  [8] = {.index = 29, .length = 3},
  [9] = {.index = 32, .length = 6},
  [10] = {.index = 38, .length = 6},
  [11] = {.index = 44, .length = 7},
  [12] = {.index = 51, .length = 4},
  [13] = {.index = 55, .length = 4},
  [14] = {.index = 59, .length = 7},
  [15] = {.index = 66, .length = 8},
  [16] = {.index = 74, .length = 8},
  [17] = {.index = 82, .length = 5},
  [18] = {.index = 87, .length = 5},
  [19] = {.index = 92, .length = 5},
  [20] = {.index = 97, .length = 9},
  [21] = {.index = 106, .length = 6},
  [22] = {.index = 112, .length = 6},
  [24] = {.index = 118, .length = 7},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_fields, 2},
    {field_fields, 3},
    {field_fields, 4},
    {field_name, 1},
  [4] =
    {field_fields, 2},
    {field_fields, 3},
    {field_fields, 4},
    {field_fields, 5},
    {field_name, 1},
  [9] =
    {field_fields, 3},
    {field_fields, 4},
    {field_fields, 5},
    {field_generics, 2},
    {field_name, 1},
  [14] =
    {field_name, 0},
    {field_type, 2},
  [16] =
    {field_fields, 3},
    {field_fields, 4},
    {field_fields, 5},
    {field_name, 2},
    {field_traits, 0},
  [21] =
    {field_name, 1},
    {field_type, 3},
  [23] =
    {field_fields, 3},
    {field_fields, 4},
    {field_fields, 5},
    {field_fields, 6},
    {field_generics, 2},
    {field_name, 1},
  [29] =
    {field_name, 1},
    {field_params, 2},
    {field_params, 3},
  [32] =
    {field_fields, 3},
    {field_fields, 4},
    {field_fields, 5},
    {field_fields, 6},
    {field_name, 2},
    {field_traits, 0},
  [38] =
    {field_fields, 4},
    {field_fields, 5},
    {field_fields, 6},
    {field_generics, 3},
    {field_name, 2},
    {field_traits, 0},
  [44] =
    {field_fields, 5},
    {field_fields, 6},
    {field_fields, 7},
    {field_name, 1},
    {field_types, 2},
    {field_types, 3},
    {field_types, 4},
  [51] =
    {field_name, 1},
    {field_params, 2},
    {field_params, 3},
    {field_returns, 5},
  [55] =
    {field_name, 1},
    {field_params, 2},
    {field_params, 3},
    {field_params, 4},
  [59] =
    {field_fields, 4},
    {field_fields, 5},
    {field_fields, 6},
    {field_fields, 7},
    {field_generics, 3},
    {field_name, 2},
    {field_traits, 0},
  [66] =
    {field_fields, 5},
    {field_fields, 6},
    {field_fields, 7},
    {field_fields, 8},
    {field_name, 1},
    {field_types, 2},
    {field_types, 3},
    {field_types, 4},
  [74] =
    {field_fields, 6},
    {field_fields, 7},
    {field_fields, 8},
    {field_name, 1},
    {field_types, 2},
    {field_types, 3},
    {field_types, 4},
    {field_types, 5},
  [82] =
    {field_name, 1},
    {field_params, 2},
    {field_params, 3},
    {field_returns, 5},
    {field_returns, 6},
  [87] =
    {field_name, 1},
    {field_params, 2},
    {field_params, 3},
    {field_params, 4},
    {field_returns, 6},
  [92] =
    {field_name, 1},
    {field_params, 2},
    {field_params, 3},
    {field_params, 4},
    {field_params, 5},
  [97] =
    {field_fields, 6},
    {field_fields, 7},
    {field_fields, 8},
    {field_fields, 9},
    {field_name, 1},
    {field_types, 2},
    {field_types, 3},
    {field_types, 4},
    {field_types, 5},
  [106] =
    {field_name, 1},
    {field_params, 2},
    {field_params, 3},
    {field_params, 4},
    {field_returns, 6},
    {field_returns, 7},
  [112] =
    {field_name, 1},
    {field_params, 2},
    {field_params, 3},
    {field_params, 4},
    {field_params, 5},
    {field_returns, 7},
  [118] =
    {field_name, 1},
    {field_params, 2},
    {field_params, 3},
    {field_params, 4},
    {field_params, 5},
    {field_returns, 7},
    {field_returns, 8},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [23] = {
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
      if (eof) ADVANCE(59);
      if (lookahead == '"') ADVANCE(113);
      if (lookahead == '$') ADVANCE(120);
      if (lookahead == '\'') ADVANCE(107);
      if (lookahead == '(') ADVANCE(63);
      if (lookahead == ')') ADVANCE(65);
      if (lookahead == ',') ADVANCE(64);
      if (lookahead == '.') ADVANCE(78);
      if (lookahead == '/') ADVANCE(80);
      if (lookahead == '0') ADVANCE(97);
      if (lookahead == ':') ADVANCE(76);
      if (lookahead == '<') ADVANCE(73);
      if (lookahead == '=') ADVANCE(5);
      if (lookahead == '>') ADVANCE(74);
      if (lookahead == '?') ADVANCE(75);
      if (lookahead == '@') ADVANCE(72);
      if (lookahead == '\\') ADVANCE(46);
      if (lookahead == '_') ADVANCE(92);
      if (lookahead == '`') ADVANCE(114);
      if (lookahead == 'c') ADVANCE(30);
      if (lookahead == 'e') ADVANCE(35);
      if (lookahead == 'f') ADVANCE(16);
      if (lookahead == 'i') ADVANCE(32);
      if (lookahead == 'n') ADVANCE(47);
      if (lookahead == 'p') ADVANCE(12);
      if (lookahead == 't') ADVANCE(38);
      if (lookahead == 'v') ADVANCE(17);
      if (lookahead == '{') ADVANCE(68);
      if (lookahead == '}') ADVANCE(69);
      if (('a' <= lookahead && lookahead <= 'd')) ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'F')) ADVANCE(83);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(100);
      if (('G' <= lookahead && lookahead <= 'Z')) ADVANCE(87);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(113);
      if (lookahead == '$') ADVANCE(120);
      if (lookahead == '\\') ADVANCE(46);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(116);
      if (lookahead != 0) ADVANCE(117);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(113);
      if (lookahead == '$') ADVANCE(120);
      if (lookahead == '`') ADVANCE(115);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(118);
      if (lookahead != 0) ADVANCE(119);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(113);
      if (lookahead == '\'') ADVANCE(107);
      if (lookahead == ')') ADVANCE(65);
      if (lookahead == ',') ADVANCE(64);
      if (lookahead == '.') ADVANCE(54);
      if (lookahead == '0') ADVANCE(95);
      if (lookahead == '`') ADVANCE(114);
      if (lookahead == 'f') ADVANCE(18);
      if (lookahead == 'n') ADVANCE(47);
      if (lookahead == 't') ADVANCE(40);
      if (lookahead == '{') ADVANCE(68);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(96);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(86);
      END_STATE();
    case 4:
      if (lookahead == ')') ADVANCE(65);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(92);
      END_STATE();
    case 5:
      if (lookahead == '>') ADVANCE(71);
      END_STATE();
    case 6:
      if (lookahead == '\\') ADVANCE(46);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(109);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(6)
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(108);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(98);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(103);
      END_STATE();
    case 9:
      if (lookahead == '_') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(102);
      END_STATE();
    case 10:
      if (lookahead == '_') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 11:
      if (lookahead == '_') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(106);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(19);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(43);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(24);
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(23);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(29);
      if (lookahead == 'u') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(26);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(28);
      END_STATE();
    case 19:
      if (lookahead == 'c') ADVANCE(25);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(93);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(94);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(60);
      END_STATE();
    case 23:
      if (lookahead == 'g') ADVANCE(22);
      END_STATE();
    case 24:
      if (lookahead == 'i') ADVANCE(44);
      END_STATE();
    case 25:
      if (lookahead == 'k') ADVANCE(15);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(77);
      END_STATE();
    case 27:
      if (lookahead == 'l') ADVANCE(121);
      END_STATE();
    case 28:
      if (lookahead == 'l') ADVANCE(42);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      END_STATE();
    case 31:
      if (lookahead == 'l') ADVANCE(27);
      END_STATE();
    case 32:
      if (lookahead == 'm') ADVANCE(37);
      END_STATE();
    case 33:
      if (lookahead == 'm') ADVANCE(67);
      END_STATE();
    case 34:
      if (lookahead == 'n') ADVANCE(70);
      END_STATE();
    case 35:
      if (lookahead == 'n') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      END_STATE();
    case 36:
      if (lookahead == 'o') ADVANCE(39);
      END_STATE();
    case 37:
      if (lookahead == 'p') ADVANCE(36);
      END_STATE();
    case 38:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 39:
      if (lookahead == 'r') ADVANCE(45);
      END_STATE();
    case 40:
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 41:
      if (lookahead == 's') ADVANCE(62);
      END_STATE();
    case 42:
      if (lookahead == 's') ADVANCE(21);
      END_STATE();
    case 43:
      if (lookahead == 's') ADVANCE(41);
      END_STATE();
    case 44:
      if (lookahead == 't') ADVANCE(66);
      END_STATE();
    case 45:
      if (lookahead == 't') ADVANCE(61);
      END_STATE();
    case 46:
      if (lookahead == 'u') ADVANCE(110);
      if (lookahead == '"' ||
          lookahead == '$' ||
          lookahead == '\'' ||
          lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't') ADVANCE(112);
      END_STATE();
    case 47:
      if (lookahead == 'u') ADVANCE(31);
      END_STATE();
    case 48:
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 49:
      if (lookahead == 'u') ADVANCE(33);
      END_STATE();
    case 50:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(104);
      if (('2' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 51:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(103);
      END_STATE();
    case 52:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(52)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(79);
      END_STATE();
    case 53:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(53)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(58);
      END_STATE();
    case 54:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(106);
      END_STATE();
    case 55:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(102);
      END_STATE();
    case 56:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(111);
      END_STATE();
    case 57:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 58:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_class);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_trait);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_fun);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_val);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_url_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_definition_name);
      if (('A' <= lookahead && lookahead <= 'F')) ADVANCE(84);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
      if (('G' <= lookahead && lookahead <= 'Z')) ADVANCE(86);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_definition_name);
      if (('A' <= lookahead && lookahead <= 'F')) ADVANCE(86);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);
      if (('G' <= lookahead && lookahead <= 'Z')) ADVANCE(86);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_definition_name);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(91);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(92);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_definition_name);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(111);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_definition_name);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(86);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_definition_name);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_definition_name);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(92);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_variable_name);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(89);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_variable_name);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_enum_field_name);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(92);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(92);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_enum_field_name);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(90);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(92);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_enum_field_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(92);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(54);
      if (lookahead == '_') ADVANCE(10);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(51);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(105);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(54);
      if (lookahead == '_') ADVANCE(10);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(7);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(50);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(55);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(101);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(98);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(98);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(111);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(101);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(99);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(102);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_bin_literal);
      if (lookahead == '_') ADVANCE(8);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_bin_literal);
      if (lookahead == '_') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(111);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_float_literal);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(11);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(106);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(109);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(108);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_BSLASHu);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(aux_sym__uni_character_literal_token1);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym__escaped_identifier);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$') ADVANCE(119);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym__line_str_text);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(116);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(117);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym__line_str_text);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$' &&
          lookahead != '\\') ADVANCE(117);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym__multi_line_str_text);
      if (lookahead == '`') ADVANCE(115);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(118);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$') ADVANCE(119);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym__multi_line_str_text);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '$') ADVANCE(119);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 3},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 1},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 1},
  [53] = {.lex_state = 6},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 3},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 3},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 3},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 52},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 3},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 4},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 4},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 3},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 52},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 3},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 52},
  [124] = {.lex_state = 3},
  [125] = {.lex_state = 52},
  [126] = {.lex_state = 52},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 3},
  [131] = {.lex_state = 4},
  [132] = {.lex_state = 52},
  [133] = {.lex_state = 4},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 4},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 52},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 3},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 52},
  [152] = {.lex_state = 52},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 4},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 53},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 52},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 3},
  [175] = {.lex_state = 4},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 3},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 3},
  [197] = {.lex_state = 3},
  [198] = {.lex_state = 3},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 53},
  [202] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_package] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_class] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_trait] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_fun] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_val] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
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
  },
  [1] = {
    [sym_source_file] = STATE(200),
    [anon_sym_package] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(5), 1,
      ts_builtin_sym_end,
    ACTIONS(7), 1,
      anon_sym_import,
    ACTIONS(9), 1,
      anon_sym_class,
    ACTIONS(11), 1,
      anon_sym_trait,
    ACTIONS(13), 1,
      anon_sym_enum,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(8), 2,
      sym_definitions,
      aux_sym_source_file_repeat2,
    STATE(16), 2,
      sym_import_statement,
      aux_sym_source_file_repeat1,
    STATE(61), 2,
      sym_trait_name,
      aux_sym_class_definition_repeat1,
    STATE(38), 4,
      sym_class_definition,
      sym_trait_definition,
      sym_enum_definition,
      sym_fun_definition,
  [40] = 7,
    ACTIONS(21), 1,
      sym_integer_literal,
    ACTIONS(25), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(23), 4,
      sym_hex_literal,
      sym_bin_literal,
      sym_float_literal,
      anon_sym_null,
    STATE(97), 7,
      sym__primary_expression,
      sym_boolean_literal,
      sym_character_literal,
      sym__string_literal,
      sym_line_string_literal,
      sym_multi_line_string_literal,
      sym__literal_constant,
  [72] = 7,
    ACTIONS(25), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_BQUOTE,
    ACTIONS(31), 1,
      sym_integer_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(33), 4,
      sym_hex_literal,
      sym_bin_literal,
      sym_float_literal,
      anon_sym_null,
    STATE(128), 7,
      sym__primary_expression,
      sym_boolean_literal,
      sym_character_literal,
      sym__string_literal,
      sym_line_string_literal,
      sym_multi_line_string_literal,
      sym__literal_constant,
  [104] = 11,
    ACTIONS(7), 1,
      anon_sym_import,
    ACTIONS(9), 1,
      anon_sym_class,
    ACTIONS(11), 1,
      anon_sym_trait,
    ACTIONS(13), 1,
      anon_sym_enum,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(17), 1,
      anon_sym_AT,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    STATE(2), 2,
      sym_import_statement,
      aux_sym_source_file_repeat1,
    STATE(6), 2,
      sym_definitions,
      aux_sym_source_file_repeat2,
    STATE(61), 2,
      sym_trait_name,
      aux_sym_class_definition_repeat1,
    STATE(38), 4,
      sym_class_definition,
      sym_trait_definition,
      sym_enum_definition,
      sym_fun_definition,
  [144] = 9,
    ACTIONS(5), 1,
      ts_builtin_sym_end,
    ACTIONS(9), 1,
      anon_sym_class,
    ACTIONS(11), 1,
      anon_sym_trait,
    ACTIONS(13), 1,
      anon_sym_enum,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(17), 1,
      anon_sym_AT,
    STATE(7), 2,
      sym_definitions,
      aux_sym_source_file_repeat2,
    STATE(61), 2,
      sym_trait_name,
      aux_sym_class_definition_repeat1,
    STATE(38), 4,
      sym_class_definition,
      sym_trait_definition,
      sym_enum_definition,
      sym_fun_definition,
  [177] = 9,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    ACTIONS(39), 1,
      anon_sym_class,
    ACTIONS(42), 1,
      anon_sym_trait,
    ACTIONS(45), 1,
      anon_sym_enum,
    ACTIONS(48), 1,
      anon_sym_fun,
    ACTIONS(51), 1,
      anon_sym_AT,
    STATE(7), 2,
      sym_definitions,
      aux_sym_source_file_repeat2,
    STATE(61), 2,
      sym_trait_name,
      aux_sym_class_definition_repeat1,
    STATE(38), 4,
      sym_class_definition,
      sym_trait_definition,
      sym_enum_definition,
      sym_fun_definition,
  [210] = 9,
    ACTIONS(9), 1,
      anon_sym_class,
    ACTIONS(11), 1,
      anon_sym_trait,
    ACTIONS(13), 1,
      anon_sym_enum,
    ACTIONS(15), 1,
      anon_sym_fun,
    ACTIONS(17), 1,
      anon_sym_AT,
    ACTIONS(54), 1,
      ts_builtin_sym_end,
    STATE(7), 2,
      sym_definitions,
      aux_sym_source_file_repeat2,
    STATE(61), 2,
      sym_trait_name,
      aux_sym_class_definition_repeat1,
    STATE(38), 4,
      sym_class_definition,
      sym_trait_definition,
      sym_enum_definition,
      sym_fun_definition,
  [243] = 1,
    ACTIONS(56), 11,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
      anon_sym_GT,
      anon_sym_DOT,
  [257] = 7,
    ACTIONS(58), 1,
      anon_sym_BSLASHu,
    ACTIONS(60), 1,
      sym__escaped_identifier,
    ACTIONS(62), 1,
      anon_sym_DQUOTE,
    ACTIONS(64), 1,
      sym__line_str_text,
    ACTIONS(66), 1,
      anon_sym_DOLLAR,
    STATE(51), 1,
      sym__uni_character_literal,
    STATE(12), 4,
      sym_character_escape_seq,
      sym__line_string_content,
      sym__interpolation,
      aux_sym_line_string_literal_repeat1,
  [282] = 7,
    ACTIONS(68), 1,
      anon_sym_BSLASHu,
    ACTIONS(71), 1,
      sym__escaped_identifier,
    ACTIONS(74), 1,
      anon_sym_DQUOTE,
    ACTIONS(76), 1,
      sym__line_str_text,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    STATE(51), 1,
      sym__uni_character_literal,
    STATE(11), 4,
      sym_character_escape_seq,
      sym__line_string_content,
      sym__interpolation,
      aux_sym_line_string_literal_repeat1,
  [307] = 7,
    ACTIONS(58), 1,
      anon_sym_BSLASHu,
    ACTIONS(60), 1,
      sym__escaped_identifier,
    ACTIONS(66), 1,
      anon_sym_DOLLAR,
    ACTIONS(82), 1,
      anon_sym_DQUOTE,
    ACTIONS(84), 1,
      sym__line_str_text,
    STATE(51), 1,
      sym__uni_character_literal,
    STATE(11), 4,
      sym_character_escape_seq,
      sym__line_string_content,
      sym__interpolation,
      aux_sym_line_string_literal_repeat1,
  [332] = 3,
    ACTIONS(88), 1,
      anon_sym_SLASH,
    STATE(13), 1,
      aux_sym_url_repeat1,
    ACTIONS(86), 7,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [348] = 3,
    ACTIONS(93), 1,
      anon_sym_SLASH,
    STATE(13), 1,
      aux_sym_url_repeat1,
    ACTIONS(91), 7,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [364] = 3,
    ACTIONS(93), 1,
      anon_sym_SLASH,
    STATE(14), 1,
      aux_sym_url_repeat1,
    ACTIONS(95), 7,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [380] = 3,
    ACTIONS(99), 1,
      anon_sym_import,
    STATE(16), 2,
      sym_import_statement,
      aux_sym_source_file_repeat1,
    ACTIONS(97), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [396] = 1,
    ACTIONS(86), 8,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
      anon_sym_SLASH,
  [407] = 4,
    ACTIONS(104), 1,
      anon_sym_BQUOTE,
    ACTIONS(106), 1,
      anon_sym_DOLLAR,
    ACTIONS(102), 2,
      anon_sym_DQUOTE,
      sym__multi_line_str_text,
    STATE(22), 3,
      sym__multi_line_string_content,
      sym__interpolation,
      aux_sym_multi_line_string_literal_repeat1,
  [423] = 4,
    ACTIONS(111), 1,
      anon_sym_BQUOTE,
    ACTIONS(113), 1,
      anon_sym_DOLLAR,
    ACTIONS(108), 2,
      anon_sym_DQUOTE,
      sym__multi_line_str_text,
    STATE(19), 3,
      sym__multi_line_string_content,
      sym__interpolation,
      aux_sym_multi_line_string_literal_repeat1,
  [439] = 1,
    ACTIONS(116), 7,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [449] = 1,
    ACTIONS(118), 7,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [459] = 4,
    ACTIONS(106), 1,
      anon_sym_DOLLAR,
    ACTIONS(122), 1,
      anon_sym_BQUOTE,
    ACTIONS(120), 2,
      anon_sym_DQUOTE,
      sym__multi_line_str_text,
    STATE(19), 3,
      sym__multi_line_string_content,
      sym__interpolation,
      aux_sym_multi_line_string_literal_repeat1,
  [475] = 1,
    ACTIONS(124), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [484] = 1,
    ACTIONS(126), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [493] = 1,
    ACTIONS(128), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [502] = 1,
    ACTIONS(130), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [511] = 1,
    ACTIONS(132), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [520] = 1,
    ACTIONS(134), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [529] = 1,
    ACTIONS(136), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [538] = 1,
    ACTIONS(138), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [547] = 1,
    ACTIONS(140), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [556] = 1,
    ACTIONS(142), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [565] = 1,
    ACTIONS(144), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [574] = 1,
    ACTIONS(146), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [583] = 1,
    ACTIONS(148), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [592] = 1,
    ACTIONS(150), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [601] = 1,
    ACTIONS(152), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [610] = 1,
    ACTIONS(154), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [619] = 1,
    ACTIONS(156), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [628] = 1,
    ACTIONS(158), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [637] = 1,
    ACTIONS(160), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [646] = 1,
    ACTIONS(162), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [655] = 1,
    ACTIONS(164), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [664] = 1,
    ACTIONS(166), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [673] = 1,
    ACTIONS(168), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [682] = 1,
    ACTIONS(170), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [691] = 1,
    ACTIONS(172), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [700] = 1,
    ACTIONS(174), 6,
      ts_builtin_sym_end,
      anon_sym_class,
      anon_sym_trait,
      anon_sym_enum,
      anon_sym_fun,
      anon_sym_AT,
  [709] = 2,
    ACTIONS(178), 1,
      sym__line_str_text,
    ACTIONS(176), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [719] = 4,
    ACTIONS(180), 1,
      anon_sym_fun,
    ACTIONS(182), 1,
      anon_sym_val,
    STATE(75), 1,
      sym_trait_field,
    STATE(136), 2,
      sym_type_field,
      sym_fun_field,
  [733] = 2,
    ACTIONS(186), 1,
      sym__line_str_text,
    ACTIONS(184), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [743] = 2,
    ACTIONS(56), 1,
      sym__line_str_text,
    ACTIONS(188), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [753] = 5,
    ACTIONS(190), 1,
      aux_sym_character_literal_token1,
    ACTIONS(192), 1,
      anon_sym_BSLASHu,
    ACTIONS(194), 1,
      sym__escaped_identifier,
    STATE(167), 1,
      sym_character_escape_seq,
    STATE(169), 1,
      sym__uni_character_literal,
  [769] = 4,
    ACTIONS(180), 1,
      anon_sym_fun,
    ACTIONS(182), 1,
      anon_sym_val,
    STATE(66), 1,
      sym_trait_field,
    STATE(136), 2,
      sym_type_field,
      sym_fun_field,
  [783] = 4,
    ACTIONS(180), 1,
      anon_sym_fun,
    ACTIONS(182), 1,
      anon_sym_val,
    STATE(157), 1,
      sym_trait_field,
    STATE(136), 2,
      sym_type_field,
      sym_fun_field,
  [797] = 2,
    ACTIONS(198), 1,
      sym__line_str_text,
    ACTIONS(196), 4,
      anon_sym_BSLASHu,
      sym__escaped_identifier,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR,
  [807] = 1,
    ACTIONS(196), 4,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym__multi_line_str_text,
      anon_sym_DOLLAR,
  [814] = 3,
    ACTIONS(202), 1,
      sym_definition_name,
    STATE(101), 1,
      sym_type,
    ACTIONS(200), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [825] = 3,
    ACTIONS(204), 1,
      anon_sym_COMMA,
    STATE(59), 1,
      aux_sym_fun_definition_repeat2,
    ACTIONS(207), 2,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
  [836] = 3,
    ACTIONS(202), 1,
      sym_definition_name,
    STATE(85), 1,
      sym_type,
    ACTIONS(209), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [847] = 3,
    ACTIONS(17), 1,
      anon_sym_AT,
    ACTIONS(211), 1,
      anon_sym_class,
    STATE(63), 2,
      sym_trait_name,
      aux_sym_class_definition_repeat1,
  [858] = 3,
    ACTIONS(202), 1,
      sym_definition_name,
    STATE(80), 1,
      sym_type,
    ACTIONS(213), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [869] = 3,
    ACTIONS(215), 1,
      anon_sym_class,
    ACTIONS(217), 1,
      anon_sym_AT,
    STATE(63), 2,
      sym_trait_name,
      aux_sym_class_definition_repeat1,
  [880] = 2,
    ACTIONS(222), 1,
      anon_sym_QMARK,
    ACTIONS(220), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
  [889] = 1,
    ACTIONS(188), 4,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym__multi_line_str_text,
      anon_sym_DOLLAR,
  [896] = 3,
    ACTIONS(224), 1,
      anon_sym_COMMA,
    ACTIONS(226), 1,
      anon_sym_RPAREN,
    STATE(74), 1,
      aux_sym_trait_definition_repeat1,
  [906] = 3,
    ACTIONS(228), 1,
      anon_sym_COMMA,
    ACTIONS(230), 1,
      anon_sym_LBRACE,
    STATE(109), 1,
      aux_sym_fun_definition_repeat2,
  [916] = 3,
    ACTIONS(232), 1,
      anon_sym_COMMA,
    ACTIONS(234), 1,
      anon_sym_RPAREN,
    STATE(87), 1,
      aux_sym_class_definition_repeat2,
  [926] = 3,
    ACTIONS(236), 1,
      anon_sym_COMMA,
    ACTIONS(239), 1,
      anon_sym_RPAREN,
    STATE(59), 1,
      aux_sym_fun_definition_repeat2,
  [936] = 3,
    ACTIONS(241), 1,
      aux_sym_url_token1,
    STATE(141), 1,
      sym_identifier,
    STATE(179), 1,
      sym__extension,
  [946] = 3,
    ACTIONS(243), 1,
      anon_sym_COMMA,
    ACTIONS(245), 1,
      anon_sym_GT,
    STATE(90), 1,
      aux_sym_trait_list_repeat1,
  [956] = 3,
    ACTIONS(232), 1,
      anon_sym_COMMA,
    ACTIONS(247), 1,
      anon_sym_RPAREN,
    STATE(91), 1,
      aux_sym_class_definition_repeat2,
  [966] = 3,
    ACTIONS(249), 1,
      anon_sym_COMMA,
    ACTIONS(252), 1,
      anon_sym_RPAREN,
    STATE(73), 1,
      aux_sym_enum_field_repeat1,
  [976] = 3,
    ACTIONS(224), 1,
      anon_sym_COMMA,
    ACTIONS(254), 1,
      anon_sym_RPAREN,
    STATE(94), 1,
      aux_sym_trait_definition_repeat1,
  [986] = 3,
    ACTIONS(224), 1,
      anon_sym_COMMA,
    ACTIONS(256), 1,
      anon_sym_RPAREN,
    STATE(95), 1,
      aux_sym_trait_definition_repeat1,
  [996] = 3,
    ACTIONS(258), 1,
      anon_sym_LPAREN,
    ACTIONS(260), 1,
      anon_sym_LT,
    STATE(166), 1,
      sym_generic_list,
  [1006] = 3,
    ACTIONS(232), 1,
      anon_sym_COMMA,
    ACTIONS(262), 1,
      anon_sym_RPAREN,
    STATE(87), 1,
      aux_sym_class_definition_repeat2,
  [1016] = 3,
    ACTIONS(202), 1,
      sym_definition_name,
    ACTIONS(264), 1,
      anon_sym_LBRACE,
    STATE(99), 1,
      sym_type,
  [1026] = 3,
    ACTIONS(260), 1,
      anon_sym_LT,
    ACTIONS(266), 1,
      anon_sym_LPAREN,
    STATE(170), 1,
      sym_generic_list,
  [1036] = 3,
    ACTIONS(268), 1,
      anon_sym_COMMA,
    ACTIONS(271), 1,
      anon_sym_RPAREN,
    STATE(69), 1,
      aux_sym_fun_definition_repeat2,
  [1046] = 3,
    ACTIONS(273), 1,
      anon_sym_COMMA,
    ACTIONS(276), 1,
      anon_sym_RPAREN,
    STATE(59), 1,
      aux_sym_fun_definition_repeat2,
  [1056] = 3,
    ACTIONS(278), 1,
      anon_sym_COMMA,
    ACTIONS(280), 1,
      anon_sym_RPAREN,
    STATE(104), 1,
      aux_sym_fun_definition_repeat1,
  [1066] = 3,
    ACTIONS(232), 1,
      anon_sym_COMMA,
    ACTIONS(282), 1,
      anon_sym_RPAREN,
    STATE(106), 1,
      aux_sym_class_definition_repeat2,
  [1076] = 3,
    ACTIONS(284), 1,
      anon_sym_COMMA,
    ACTIONS(286), 1,
      anon_sym_RPAREN,
    STATE(73), 1,
      aux_sym_enum_field_repeat1,
  [1086] = 3,
    ACTIONS(288), 1,
      anon_sym_COMMA,
    ACTIONS(291), 1,
      anon_sym_RPAREN,
    STATE(81), 1,
      aux_sym_fun_definition_repeat2,
  [1096] = 3,
    ACTIONS(293), 1,
      anon_sym_COMMA,
    ACTIONS(296), 1,
      anon_sym_RPAREN,
    STATE(59), 1,
      aux_sym_fun_definition_repeat2,
  [1106] = 3,
    ACTIONS(298), 1,
      anon_sym_COMMA,
    ACTIONS(301), 1,
      anon_sym_RPAREN,
    STATE(87), 1,
      aux_sym_class_definition_repeat2,
  [1116] = 3,
    ACTIONS(228), 1,
      anon_sym_COMMA,
    ACTIONS(303), 1,
      anon_sym_LBRACE,
    STATE(59), 1,
      aux_sym_fun_definition_repeat2,
  [1126] = 3,
    ACTIONS(305), 1,
      anon_sym_COMMA,
    ACTIONS(307), 1,
      anon_sym_RBRACE,
    STATE(93), 1,
      aux_sym_enum_definition_repeat1,
  [1136] = 3,
    ACTIONS(309), 1,
      anon_sym_COMMA,
    ACTIONS(312), 1,
      anon_sym_GT,
    STATE(90), 1,
      aux_sym_trait_list_repeat1,
  [1146] = 3,
    ACTIONS(232), 1,
      anon_sym_COMMA,
    ACTIONS(314), 1,
      anon_sym_RPAREN,
    STATE(87), 1,
      aux_sym_class_definition_repeat2,
  [1156] = 3,
    ACTIONS(316), 1,
      anon_sym_RPAREN,
    ACTIONS(318), 1,
      sym_variable_name,
    STATE(111), 1,
      sym_param,
  [1166] = 3,
    ACTIONS(320), 1,
      anon_sym_COMMA,
    ACTIONS(323), 1,
      anon_sym_RBRACE,
    STATE(93), 1,
      aux_sym_enum_definition_repeat1,
  [1176] = 3,
    ACTIONS(325), 1,
      anon_sym_COMMA,
    ACTIONS(328), 1,
      anon_sym_RPAREN,
    STATE(94), 1,
      aux_sym_trait_definition_repeat1,
  [1186] = 3,
    ACTIONS(224), 1,
      anon_sym_COMMA,
    ACTIONS(330), 1,
      anon_sym_RPAREN,
    STATE(94), 1,
      aux_sym_trait_definition_repeat1,
  [1196] = 3,
    ACTIONS(318), 1,
      sym_variable_name,
    ACTIONS(332), 1,
      anon_sym_RPAREN,
    STATE(119), 1,
      sym_param,
  [1206] = 3,
    ACTIONS(284), 1,
      anon_sym_COMMA,
    ACTIONS(334), 1,
      anon_sym_RPAREN,
    STATE(84), 1,
      aux_sym_enum_field_repeat1,
  [1216] = 3,
    ACTIONS(260), 1,
      anon_sym_LT,
    ACTIONS(336), 1,
      anon_sym_LPAREN,
    STATE(187), 1,
      sym_generic_list,
  [1226] = 3,
    ACTIONS(228), 1,
      anon_sym_COMMA,
    ACTIONS(338), 1,
      anon_sym_LBRACE,
    STATE(120), 1,
      aux_sym_fun_definition_repeat2,
  [1236] = 3,
    ACTIONS(232), 1,
      anon_sym_COMMA,
    ACTIONS(340), 1,
      anon_sym_RPAREN,
    STATE(68), 1,
      aux_sym_class_definition_repeat2,
  [1246] = 3,
    ACTIONS(342), 1,
      anon_sym_COMMA,
    ACTIONS(345), 1,
      anon_sym_RPAREN,
    STATE(86), 1,
      aux_sym_fun_definition_repeat2,
  [1256] = 3,
    ACTIONS(202), 1,
      sym_definition_name,
    ACTIONS(347), 1,
      anon_sym_LBRACE,
    STATE(67), 1,
      sym_type,
  [1266] = 3,
    ACTIONS(243), 1,
      anon_sym_COMMA,
    ACTIONS(349), 1,
      anon_sym_GT,
    STATE(71), 1,
      aux_sym_trait_list_repeat1,
  [1276] = 3,
    ACTIONS(351), 1,
      anon_sym_COMMA,
    ACTIONS(354), 1,
      anon_sym_RPAREN,
    STATE(104), 1,
      aux_sym_fun_definition_repeat1,
  [1286] = 3,
    ACTIONS(241), 1,
      aux_sym_url_token1,
    STATE(5), 1,
      sym_package,
    STATE(20), 1,
      sym_identifier,
  [1296] = 3,
    ACTIONS(232), 1,
      anon_sym_COMMA,
    ACTIONS(356), 1,
      anon_sym_RPAREN,
    STATE(87), 1,
      aux_sym_class_definition_repeat2,
  [1306] = 3,
    ACTIONS(232), 1,
      anon_sym_COMMA,
    ACTIONS(358), 1,
      anon_sym_RPAREN,
    STATE(121), 1,
      aux_sym_class_definition_repeat2,
  [1316] = 3,
    ACTIONS(228), 1,
      anon_sym_COMMA,
    ACTIONS(360), 1,
      anon_sym_LBRACE,
    STATE(88), 1,
      aux_sym_fun_definition_repeat2,
  [1326] = 3,
    ACTIONS(228), 1,
      anon_sym_COMMA,
    ACTIONS(362), 1,
      anon_sym_LBRACE,
    STATE(59), 1,
      aux_sym_fun_definition_repeat2,
  [1336] = 1,
    ACTIONS(207), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
  [1342] = 3,
    ACTIONS(278), 1,
      anon_sym_COMMA,
    ACTIONS(364), 1,
      anon_sym_RPAREN,
    STATE(118), 1,
      aux_sym_fun_definition_repeat1,
  [1352] = 3,
    ACTIONS(305), 1,
      anon_sym_COMMA,
    ACTIONS(366), 1,
      anon_sym_RBRACE,
    STATE(89), 1,
      aux_sym_enum_definition_repeat1,
  [1362] = 3,
    ACTIONS(305), 1,
      anon_sym_COMMA,
    ACTIONS(368), 1,
      anon_sym_RBRACE,
    STATE(93), 1,
      aux_sym_enum_definition_repeat1,
  [1372] = 3,
    ACTIONS(305), 1,
      anon_sym_COMMA,
    ACTIONS(370), 1,
      anon_sym_RBRACE,
    STATE(113), 1,
      aux_sym_enum_definition_repeat1,
  [1382] = 3,
    ACTIONS(232), 1,
      anon_sym_COMMA,
    ACTIONS(372), 1,
      anon_sym_RPAREN,
    STATE(77), 1,
      aux_sym_class_definition_repeat2,
  [1392] = 3,
    ACTIONS(202), 1,
      sym_definition_name,
    ACTIONS(374), 1,
      anon_sym_LBRACE,
    STATE(108), 1,
      sym_type,
  [1402] = 1,
    ACTIONS(376), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
  [1408] = 3,
    ACTIONS(278), 1,
      anon_sym_COMMA,
    ACTIONS(378), 1,
      anon_sym_RPAREN,
    STATE(104), 1,
      aux_sym_fun_definition_repeat1,
  [1418] = 3,
    ACTIONS(278), 1,
      anon_sym_COMMA,
    ACTIONS(380), 1,
      anon_sym_RPAREN,
    STATE(82), 1,
      aux_sym_fun_definition_repeat1,
  [1428] = 3,
    ACTIONS(228), 1,
      anon_sym_COMMA,
    ACTIONS(382), 1,
      anon_sym_LBRACE,
    STATE(59), 1,
      aux_sym_fun_definition_repeat2,
  [1438] = 3,
    ACTIONS(232), 1,
      anon_sym_COMMA,
    ACTIONS(384), 1,
      anon_sym_RPAREN,
    STATE(87), 1,
      aux_sym_class_definition_repeat2,
  [1448] = 1,
    ACTIONS(386), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1453] = 2,
    ACTIONS(241), 1,
      aux_sym_url_token1,
    STATE(103), 1,
      sym_identifier,
  [1460] = 2,
    ACTIONS(202), 1,
      sym_definition_name,
    STATE(110), 1,
      sym_type,
  [1467] = 2,
    ACTIONS(388), 1,
      aux_sym_url_token1,
    STATE(57), 1,
      sym_identifier,
  [1474] = 2,
    ACTIONS(390), 1,
      aux_sym_url_token1,
    STATE(21), 1,
      sym_url,
  [1481] = 1,
    ACTIONS(392), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1486] = 1,
    ACTIONS(252), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1491] = 1,
    ACTIONS(394), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1496] = 2,
    ACTIONS(202), 1,
      sym_definition_name,
    STATE(122), 1,
      sym_type,
  [1503] = 2,
    ACTIONS(396), 1,
      sym_enum_field_name,
    STATE(153), 1,
      sym_enum_field,
  [1510] = 2,
    ACTIONS(241), 1,
      aux_sym_url_token1,
    STATE(160), 1,
      sym_identifier,
  [1517] = 2,
    ACTIONS(396), 1,
      sym_enum_field_name,
    STATE(112), 1,
      sym_enum_field,
  [1524] = 1,
    ACTIONS(398), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1529] = 2,
    ACTIONS(318), 1,
      sym_variable_name,
    STATE(146), 1,
      sym_param,
  [1536] = 1,
    ACTIONS(400), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1541] = 1,
    ACTIONS(402), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1546] = 2,
    ACTIONS(241), 1,
      aux_sym_url_token1,
    STATE(194), 1,
      sym_identifier,
  [1553] = 2,
    ACTIONS(182), 1,
      anon_sym_val,
    STATE(72), 1,
      sym_type_field,
  [1560] = 2,
    ACTIONS(182), 1,
      anon_sym_val,
    STATE(107), 1,
      sym_type_field,
  [1567] = 2,
    ACTIONS(404), 1,
      anon_sym_LPAREN,
    ACTIONS(406), 1,
      anon_sym_DOT,
  [1574] = 2,
    ACTIONS(182), 1,
      anon_sym_val,
    STATE(83), 1,
      sym_type_field,
  [1581] = 2,
    ACTIONS(202), 1,
      sym_definition_name,
    STATE(144), 1,
      sym_type,
  [1588] = 1,
    ACTIONS(408), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1593] = 1,
    ACTIONS(410), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1598] = 1,
    ACTIONS(354), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1603] = 1,
    ACTIONS(412), 2,
      anon_sym_class,
      anon_sym_AT,
  [1608] = 1,
    ACTIONS(414), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1613] = 1,
    ACTIONS(416), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1618] = 2,
    ACTIONS(182), 1,
      anon_sym_val,
    STATE(159), 1,
      sym_type_field,
  [1625] = 2,
    ACTIONS(241), 1,
      aux_sym_url_token1,
    STATE(199), 1,
      sym_identifier,
  [1632] = 2,
    ACTIONS(418), 1,
      aux_sym_url_token1,
    STATE(56), 1,
      sym_identifier,
  [1639] = 1,
    ACTIONS(323), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1644] = 1,
    ACTIONS(420), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1649] = 2,
    ACTIONS(396), 1,
      sym_enum_field_name,
    STATE(114), 1,
      sym_enum_field,
  [1656] = 2,
    ACTIONS(182), 1,
      anon_sym_val,
    STATE(115), 1,
      sym_type_field,
  [1663] = 1,
    ACTIONS(328), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1668] = 2,
    ACTIONS(182), 1,
      anon_sym_val,
    STATE(100), 1,
      sym_type_field,
  [1675] = 1,
    ACTIONS(301), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1680] = 1,
    ACTIONS(312), 2,
      anon_sym_COMMA,
      anon_sym_GT,
  [1685] = 1,
    ACTIONS(422), 1,
      anon_sym_RBRACE,
  [1689] = 1,
    ACTIONS(424), 1,
      anon_sym_EQ_GT,
  [1693] = 1,
    ACTIONS(426), 1,
      anon_sym_LPAREN,
  [1697] = 1,
    ACTIONS(428), 1,
      anon_sym_RBRACE,
  [1701] = 1,
    ACTIONS(430), 1,
      anon_sym_RBRACE,
  [1705] = 1,
    ACTIONS(432), 1,
      anon_sym_LPAREN,
  [1709] = 1,
    ACTIONS(434), 1,
      anon_sym_SQUOTE,
  [1713] = 1,
    ACTIONS(436), 1,
      aux_sym__uni_character_literal_token1,
  [1717] = 1,
    ACTIONS(186), 1,
      anon_sym_SQUOTE,
  [1721] = 1,
    ACTIONS(438), 1,
      anon_sym_LPAREN,
  [1725] = 1,
    ACTIONS(440), 1,
      anon_sym_LBRACE,
  [1729] = 1,
    ACTIONS(442), 1,
      aux_sym_url_token1,
  [1733] = 1,
    ACTIONS(444), 1,
      anon_sym_RBRACE,
  [1737] = 1,
    ACTIONS(446), 1,
      sym_definition_name,
  [1741] = 1,
    ACTIONS(448), 1,
      sym_variable_name,
  [1745] = 1,
    ACTIONS(450), 1,
      anon_sym_EQ_GT,
  [1749] = 1,
    ACTIONS(452), 1,
      anon_sym_EQ_GT,
  [1753] = 1,
    ACTIONS(454), 1,
      anon_sym_COLON,
  [1757] = 1,
    ACTIONS(404), 1,
      anon_sym_LPAREN,
  [1761] = 1,
    ACTIONS(456), 1,
      anon_sym_LPAREN,
  [1765] = 1,
    ACTIONS(458), 1,
      anon_sym_RBRACE,
  [1769] = 1,
    ACTIONS(460), 1,
      anon_sym_RBRACE,
  [1773] = 1,
    ACTIONS(462), 1,
      anon_sym_EQ_GT,
  [1777] = 1,
    ACTIONS(464), 1,
      anon_sym_RBRACE,
  [1781] = 1,
    ACTIONS(178), 1,
      anon_sym_SQUOTE,
  [1785] = 1,
    ACTIONS(466), 1,
      anon_sym_RBRACE,
  [1789] = 1,
    ACTIONS(468), 1,
      anon_sym_LPAREN,
  [1793] = 1,
    ACTIONS(470), 1,
      anon_sym_LPAREN,
  [1797] = 1,
    ACTIONS(472), 1,
      anon_sym_EQ_GT,
  [1801] = 1,
    ACTIONS(474), 1,
      sym_definition_name,
  [1805] = 1,
    ACTIONS(476), 1,
      anon_sym_EQ_GT,
  [1809] = 1,
    ACTIONS(478), 1,
      anon_sym_COLON,
  [1813] = 1,
    ACTIONS(480), 1,
      anon_sym_LBRACE,
  [1817] = 1,
    ACTIONS(482), 1,
      anon_sym_LPAREN,
  [1821] = 1,
    ACTIONS(484), 1,
      anon_sym_LPAREN,
  [1825] = 1,
    ACTIONS(486), 1,
      sym_definition_name,
  [1829] = 1,
    ACTIONS(488), 1,
      sym_definition_name,
  [1833] = 1,
    ACTIONS(490), 1,
      sym_definition_name,
  [1837] = 1,
    ACTIONS(492), 1,
      anon_sym_LPAREN,
  [1841] = 1,
    ACTIONS(494), 1,
      ts_builtin_sym_end,
  [1845] = 1,
    ACTIONS(496), 1,
      aux_sym__uni_character_literal_token1,
  [1849] = 1,
    ACTIONS(498), 1,
      anon_sym_RBRACE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 40,
  [SMALL_STATE(4)] = 72,
  [SMALL_STATE(5)] = 104,
  [SMALL_STATE(6)] = 144,
  [SMALL_STATE(7)] = 177,
  [SMALL_STATE(8)] = 210,
  [SMALL_STATE(9)] = 243,
  [SMALL_STATE(10)] = 257,
  [SMALL_STATE(11)] = 282,
  [SMALL_STATE(12)] = 307,
  [SMALL_STATE(13)] = 332,
  [SMALL_STATE(14)] = 348,
  [SMALL_STATE(15)] = 364,
  [SMALL_STATE(16)] = 380,
  [SMALL_STATE(17)] = 396,
  [SMALL_STATE(18)] = 407,
  [SMALL_STATE(19)] = 423,
  [SMALL_STATE(20)] = 439,
  [SMALL_STATE(21)] = 449,
  [SMALL_STATE(22)] = 459,
  [SMALL_STATE(23)] = 475,
  [SMALL_STATE(24)] = 484,
  [SMALL_STATE(25)] = 493,
  [SMALL_STATE(26)] = 502,
  [SMALL_STATE(27)] = 511,
  [SMALL_STATE(28)] = 520,
  [SMALL_STATE(29)] = 529,
  [SMALL_STATE(30)] = 538,
  [SMALL_STATE(31)] = 547,
  [SMALL_STATE(32)] = 556,
  [SMALL_STATE(33)] = 565,
  [SMALL_STATE(34)] = 574,
  [SMALL_STATE(35)] = 583,
  [SMALL_STATE(36)] = 592,
  [SMALL_STATE(37)] = 601,
  [SMALL_STATE(38)] = 610,
  [SMALL_STATE(39)] = 619,
  [SMALL_STATE(40)] = 628,
  [SMALL_STATE(41)] = 637,
  [SMALL_STATE(42)] = 646,
  [SMALL_STATE(43)] = 655,
  [SMALL_STATE(44)] = 664,
  [SMALL_STATE(45)] = 673,
  [SMALL_STATE(46)] = 682,
  [SMALL_STATE(47)] = 691,
  [SMALL_STATE(48)] = 700,
  [SMALL_STATE(49)] = 709,
  [SMALL_STATE(50)] = 719,
  [SMALL_STATE(51)] = 733,
  [SMALL_STATE(52)] = 743,
  [SMALL_STATE(53)] = 753,
  [SMALL_STATE(54)] = 769,
  [SMALL_STATE(55)] = 783,
  [SMALL_STATE(56)] = 797,
  [SMALL_STATE(57)] = 807,
  [SMALL_STATE(58)] = 814,
  [SMALL_STATE(59)] = 825,
  [SMALL_STATE(60)] = 836,
  [SMALL_STATE(61)] = 847,
  [SMALL_STATE(62)] = 858,
  [SMALL_STATE(63)] = 869,
  [SMALL_STATE(64)] = 880,
  [SMALL_STATE(65)] = 889,
  [SMALL_STATE(66)] = 896,
  [SMALL_STATE(67)] = 906,
  [SMALL_STATE(68)] = 916,
  [SMALL_STATE(69)] = 926,
  [SMALL_STATE(70)] = 936,
  [SMALL_STATE(71)] = 946,
  [SMALL_STATE(72)] = 956,
  [SMALL_STATE(73)] = 966,
  [SMALL_STATE(74)] = 976,
  [SMALL_STATE(75)] = 986,
  [SMALL_STATE(76)] = 996,
  [SMALL_STATE(77)] = 1006,
  [SMALL_STATE(78)] = 1016,
  [SMALL_STATE(79)] = 1026,
  [SMALL_STATE(80)] = 1036,
  [SMALL_STATE(81)] = 1046,
  [SMALL_STATE(82)] = 1056,
  [SMALL_STATE(83)] = 1066,
  [SMALL_STATE(84)] = 1076,
  [SMALL_STATE(85)] = 1086,
  [SMALL_STATE(86)] = 1096,
  [SMALL_STATE(87)] = 1106,
  [SMALL_STATE(88)] = 1116,
  [SMALL_STATE(89)] = 1126,
  [SMALL_STATE(90)] = 1136,
  [SMALL_STATE(91)] = 1146,
  [SMALL_STATE(92)] = 1156,
  [SMALL_STATE(93)] = 1166,
  [SMALL_STATE(94)] = 1176,
  [SMALL_STATE(95)] = 1186,
  [SMALL_STATE(96)] = 1196,
  [SMALL_STATE(97)] = 1206,
  [SMALL_STATE(98)] = 1216,
  [SMALL_STATE(99)] = 1226,
  [SMALL_STATE(100)] = 1236,
  [SMALL_STATE(101)] = 1246,
  [SMALL_STATE(102)] = 1256,
  [SMALL_STATE(103)] = 1266,
  [SMALL_STATE(104)] = 1276,
  [SMALL_STATE(105)] = 1286,
  [SMALL_STATE(106)] = 1296,
  [SMALL_STATE(107)] = 1306,
  [SMALL_STATE(108)] = 1316,
  [SMALL_STATE(109)] = 1326,
  [SMALL_STATE(110)] = 1336,
  [SMALL_STATE(111)] = 1342,
  [SMALL_STATE(112)] = 1352,
  [SMALL_STATE(113)] = 1362,
  [SMALL_STATE(114)] = 1372,
  [SMALL_STATE(115)] = 1382,
  [SMALL_STATE(116)] = 1392,
  [SMALL_STATE(117)] = 1402,
  [SMALL_STATE(118)] = 1408,
  [SMALL_STATE(119)] = 1418,
  [SMALL_STATE(120)] = 1428,
  [SMALL_STATE(121)] = 1438,
  [SMALL_STATE(122)] = 1448,
  [SMALL_STATE(123)] = 1453,
  [SMALL_STATE(124)] = 1460,
  [SMALL_STATE(125)] = 1467,
  [SMALL_STATE(126)] = 1474,
  [SMALL_STATE(127)] = 1481,
  [SMALL_STATE(128)] = 1486,
  [SMALL_STATE(129)] = 1491,
  [SMALL_STATE(130)] = 1496,
  [SMALL_STATE(131)] = 1503,
  [SMALL_STATE(132)] = 1510,
  [SMALL_STATE(133)] = 1517,
  [SMALL_STATE(134)] = 1524,
  [SMALL_STATE(135)] = 1529,
  [SMALL_STATE(136)] = 1536,
  [SMALL_STATE(137)] = 1541,
  [SMALL_STATE(138)] = 1546,
  [SMALL_STATE(139)] = 1553,
  [SMALL_STATE(140)] = 1560,
  [SMALL_STATE(141)] = 1567,
  [SMALL_STATE(142)] = 1574,
  [SMALL_STATE(143)] = 1581,
  [SMALL_STATE(144)] = 1588,
  [SMALL_STATE(145)] = 1593,
  [SMALL_STATE(146)] = 1598,
  [SMALL_STATE(147)] = 1603,
  [SMALL_STATE(148)] = 1608,
  [SMALL_STATE(149)] = 1613,
  [SMALL_STATE(150)] = 1618,
  [SMALL_STATE(151)] = 1625,
  [SMALL_STATE(152)] = 1632,
  [SMALL_STATE(153)] = 1639,
  [SMALL_STATE(154)] = 1644,
  [SMALL_STATE(155)] = 1649,
  [SMALL_STATE(156)] = 1656,
  [SMALL_STATE(157)] = 1663,
  [SMALL_STATE(158)] = 1668,
  [SMALL_STATE(159)] = 1675,
  [SMALL_STATE(160)] = 1680,
  [SMALL_STATE(161)] = 1685,
  [SMALL_STATE(162)] = 1689,
  [SMALL_STATE(163)] = 1693,
  [SMALL_STATE(164)] = 1697,
  [SMALL_STATE(165)] = 1701,
  [SMALL_STATE(166)] = 1705,
  [SMALL_STATE(167)] = 1709,
  [SMALL_STATE(168)] = 1713,
  [SMALL_STATE(169)] = 1717,
  [SMALL_STATE(170)] = 1721,
  [SMALL_STATE(171)] = 1725,
  [SMALL_STATE(172)] = 1729,
  [SMALL_STATE(173)] = 1733,
  [SMALL_STATE(174)] = 1737,
  [SMALL_STATE(175)] = 1741,
  [SMALL_STATE(176)] = 1745,
  [SMALL_STATE(177)] = 1749,
  [SMALL_STATE(178)] = 1753,
  [SMALL_STATE(179)] = 1757,
  [SMALL_STATE(180)] = 1761,
  [SMALL_STATE(181)] = 1765,
  [SMALL_STATE(182)] = 1769,
  [SMALL_STATE(183)] = 1773,
  [SMALL_STATE(184)] = 1777,
  [SMALL_STATE(185)] = 1781,
  [SMALL_STATE(186)] = 1785,
  [SMALL_STATE(187)] = 1789,
  [SMALL_STATE(188)] = 1793,
  [SMALL_STATE(189)] = 1797,
  [SMALL_STATE(190)] = 1801,
  [SMALL_STATE(191)] = 1805,
  [SMALL_STATE(192)] = 1809,
  [SMALL_STATE(193)] = 1813,
  [SMALL_STATE(194)] = 1817,
  [SMALL_STATE(195)] = 1821,
  [SMALL_STATE(196)] = 1825,
  [SMALL_STATE(197)] = 1829,
  [SMALL_STATE(198)] = 1833,
  [SMALL_STATE(199)] = 1837,
  [SMALL_STATE(200)] = 1841,
  [SMALL_STATE(201)] = 1845,
  [SMALL_STATE(202)] = 1849,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat2, 2),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat2, 2), SHIFT_REPEAT(198),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat2, 2), SHIFT_REPEAT(197),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat2, 2), SHIFT_REPEAT(196),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat2, 2), SHIFT_REPEAT(70),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat2, 2), SHIFT_REPEAT(190),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 4),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(201),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(154),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(152),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(201),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(51),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2),
  [76] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(11),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_line_string_literal_repeat1, 2), SHIFT_REPEAT(152),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_url_repeat1, 2),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_url_repeat1, 2), SHIFT_REPEAT(172),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_url, 2),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_url, 1),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(126),
  [102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_multi_line_string_literal_repeat1, 2), SHIFT_REPEAT(19),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_multi_line_string_literal_repeat1, 2),
  [113] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_multi_line_string_literal_repeat1, 2), SHIFT_REPEAT(125),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package, 1),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 2),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_definition, 9, .production_id = 19),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 8, .production_id = 14),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_definition, 10, .production_id = 21),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 10, .production_id = 20),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 6, .production_id = 2),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trait_definition, 6, .production_id = 3),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trait_definition, 6, .production_id = 2),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trait_definition, 5, .production_id = 1),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 5, .production_id = 1),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 6, .production_id = 3),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_definition, 9, .production_id = 18),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_definition, 9, .production_id = 17),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 6, .production_id = 5),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 9, .production_id = 16),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 9, .production_id = 15),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definitions, 1),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_definition, 11, .production_id = 24),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 7, .production_id = 7),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trait_definition, 7, .production_id = 7),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_definition, 7, .production_id = 8),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 7, .production_id = 9),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_definition, 10, .production_id = 22),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_definition, 8, .production_id = 13),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_definition, 7, .production_id = 10),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_definition, 8, .production_id = 12),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 8, .production_id = 11),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__uni_character_literal, 2),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__uni_character_literal, 2),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character_escape_seq, 1),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_escape_seq, 1),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [192] = {.entry = {.count = 1, .reusable = false}}, SHIFT(168),
  [194] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__interpolation, 2, .production_id = 23),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__interpolation, 2, .production_id = 23),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_field, 5, .production_id = 8),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [204] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fun_definition_repeat2, 2), SHIFT_REPEAT(124),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fun_definition_repeat2, 2),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_field, 6, .production_id = 13),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_field, 7, .production_id = 19),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_class_definition_repeat1, 2),
  [217] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_class_definition_repeat1, 2), SHIFT_REPEAT(190),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [236] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_fun_field, 9, .production_id = 24), SHIFT(124),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_field, 9, .production_id = 24),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [249] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_field_repeat1, 2), SHIFT_REPEAT(4),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_field_repeat1, 2),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [268] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_fun_field, 8, .production_id = 22), SHIFT(124),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_field, 8, .production_id = 22),
  [273] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_fun_field, 8, .production_id = 21), SHIFT(124),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_field, 8, .production_id = 21),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [288] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_fun_field, 7, .production_id = 18), SHIFT(124),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_field, 7, .production_id = 18),
  [293] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_fun_field, 7, .production_id = 17), SHIFT(124),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_field, 7, .production_id = 17),
  [298] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_class_definition_repeat2, 2), SHIFT_REPEAT(150),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_class_definition_repeat2, 2),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [309] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_trait_list_repeat1, 2), SHIFT_REPEAT(132),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_trait_list_repeat1, 2),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [320] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_definition_repeat1, 2), SHIFT_REPEAT(131),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_definition_repeat1, 2),
  [325] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_trait_definition_repeat1, 2), SHIFT_REPEAT(55),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_trait_definition_repeat1, 2),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [342] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_fun_field, 6, .production_id = 12), SHIFT(124),
  [345] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fun_field, 6, .production_id = 12),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [351] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fun_definition_repeat1, 2), SHIFT_REPEAT(135),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fun_definition_repeat1, 2),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 2),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [386] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param, 3, .production_id = 4),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_field, 5),
  [394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_line_string_literal, 3),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [398] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line_string_literal, 3),
  [400] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trait_field, 1),
  [402] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_literal, 3),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [408] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_field, 4, .production_id = 6),
  [410] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_field, 4),
  [412] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_trait_name, 2),
  [414] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_line_string_literal, 2),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line_string_literal, 2),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [426] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_list, 4),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [484] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_list, 3),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__extension, 3),
  [494] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
};

#ifdef __cplusplus
extern "C" {
#endif
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
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
