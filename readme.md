# 👾 Pacos Programming Language

- A statically typed, imperative programming language inspired by rust, koka
- The compiler users the tree-sitter parser so has out of the box syntax highlighting support for helix and zed editor
- Plans to be compiled to WASM

View the docs here [pacos.sh](https://pacos.sh)

## Rules

- Function parameters are passed by value only. You cannot modify a parameter. The compiler will throw an error if you try to.
- Strict naming convention
- Only one way of doing things ex: loops, condition

### General naming convention

| Item                     | Convention              |
| ------------------------ | ----------------------- |
| Modules                  | snake_case              |
| Types/Traits/Enum        | UpperCamelCase          |
| Fields/Functions/Methods | lowerCamelCase          |
| Local variables          | snake_case              |
| Constants                | SCREAMING_SNAKE_CASE    |
| Generics                 | single uppercase letter |
