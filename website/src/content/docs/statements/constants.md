---
title: Constants
description: These are basic types
---

Constants can be declared at the top level of a program. They cannot be reassigned.

- Primitive values like`int, float, str` are directly replaced in code.
- Reference values like `list, map, records` are initialized at program start and passed by reference when used. Their data can be modified.

```rb
const START_YEAR = 2101
const PI = 3.14159
const NAME = "pacos"
const DEBUG_ENABLED = true
const COUNT = count(10)
const COUNTRIES_LIST = List.of("US", "INDIA", "CANADA")
const COUNTRY_CODES = Map.of(
  "in" => "INDIA",
  "us" => "United States",
  "ca" => "Canada"
)

fn count(n: int): int = n * 1
```