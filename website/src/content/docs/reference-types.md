---
title: Reference Types
description: These are basic refernce types
---

## any

The any type is an empty trait and is used to represent all types

## error

The error type is a trait that represents all Error types

## str

A str represents an array of runes or unicode code points. It is encoded to UTF-8 by default.
It supports interpolation of variables/values that implement the ToStr interface.

```go
import std/os.{printLn}

sed := "Hello World"
name := "Pacos"
age := 1
printLn("Name ${name} age ${age}")
```

## list

```py
import std/list

a := List.of(1, 2, 3)   # List[int]
b := List.of(          # List[List[int]]
  List.of(1),
  List.of(2),
  List.of(3),
)
c := List.of(1, 2, 3 * 4, 8, n)

actors := List.of("Krabs", "Squidward")
actors.add("Spongebob")
actors.length() // ==> 3
actors.contains("Krabs") // ==> true
actors.get(0) // => "Krabs"
actors.get(5) // => nil

items
  .map(|v| v + 1)
  .each(|v| printLn("v", v))
  .reduce(0, |v| v + 1)
```

## map

```rs
import std/map

nums := Map.of("one" => 1, "two" => 2)
map.get("one") // => some(1)
map.get("unknown") // => none
friends_tree := Map.of(
  "value" => "Fred",
  "left" => Map.of(
    "value" => "Jim",
  ),
  "right" => Map.of(
    "value" => "Shiela",
    "left" => Map.of(
      "value" => "Alice",
    ),
    "right" => Map.of(
      "value" => "Bob"
    ),
  ),
)

friends_tree
  .map(|k, v| v)
  .each(|k, v| printLn("v", v))
  .reduce(0, |k, v| v + 1)
```

## option

An option is a type that represents either value present `some` or nothing present `none`

```go
import std/option

c := some(2)

match c
  none -> print("no car")
  some(c) -> print("${c}")

if some(count) = c
  printLn("Hello ${count}")
else
  printLn("nothing")
```

## result

A result is a type that represents either success `ok` or failure `err`

```rs
import std/str
import std/result

#[error]
record FetchError()

#[error]
record IOError()

#[error]
record JsonParseError()

#[error("Version is nil")]
record ParseVersionError()

#[json]
record UserData(
  id: int,
  name: str,
  roles: List[str]
)

fn parseVersion(header: List[int]): result[int, ParseVersionError] =
  header.get(0) ?: ParseError()

fn doubleNumber(s: str): result[int] =
  number_str.parse_int().map(|n| 2 * n)

fn fetchData(route: str): result[UserData] =
  response := fetch(route)?
  data := response.body.readAll()?
  parseJson(data)?

fn main(): result[int] =
  n := doubleNumber("10")?
  version := parseVersion(list.of(1, 2))?
  res := fetchData()
  match res
    Ok(u) -> return Ok(u.id)
    Err(IOError(e)) -> printLn("IO failed")
    Err(e) -> printLn("generic error ${e.msg()}")
  Ok(0)
```