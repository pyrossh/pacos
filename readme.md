# 👾 Pacos Programming Language

- A statically typed, imperative programming language inspired by rust, koka
- The compiler users the tree-sitter parser so has out of the box syntax highlighting support for helix and zed editor
- Plans to be compiled to WASM

Here is some sample code, please enjoy

```rs
module lambda

import std/list
import std/math
import std/http

const DELTA = 11

fn sum(a: int, b: int): int = a + b + DELTA

fn sumAll(series: list[int]): int =
  series.reduce(0, |v| v + 1)

fn fib(n: int): int =
  match n
    0 | 1 -> n
    _ -> fib(n - 1) + fib(n - 2)

fn fib(n: int): int =
  if n == 0 || n == 1
    n
  else
    fib(n - 1) + fib(n - 2)

fn factorial(n: int): int =
  match n
    a -> 1
    _ -> n * factorial(n - 1)

fn firstItem(items: list[int]): option[int] =
  items.get(0)

fn toCelsius(f: float): float =
  (f - 32) * (5 / 9)

// Variadic function
fn addItems(items ...str) =
  list.add(items)

record Cat(
  name: str
  age:  int
)

// Additional Cat Contructor which is just a static function on type Cat
fn Cat.withName(name: str): Cat =
  Cat(name: name, age: 0)

// A simple method
fn fullname(c: Cat): str =
  c.name + c.age.toStr()

fn talk(c: Cat) =
  printLn("cat ${c.name} says meow")

fn toStr(c: Cat): str =
  "Cat<{c.fullname()}, ${c.age}>"

trait Stringable where
  fn toStr(): str

// `Cat is a speciecs of felidae
struct Cat is Stringable, Equal, Comparable =
  | name: str
  | age:  int

  fn Cat(name: str, age: int) =
    self.name = name
    self.age = age

  fn Cat.withName(name: str): Cat =
    `Create a cat with only name
    Cat(name: name, age: 0)

  fn fullname(): str =
    name + age.toStr()

  fn talk() =
    printLn("cat ${name} says meow")

  fn toStr(): str =
    "Cat<${fullname()}, ${age}>"

enum Temperature where
  | celsius(float)
  | fahrenheit(float)

  fn toStr(): str =
    match self
      celsius(t) && t > 30 -> "${t}C is above 30 celsius"
      celsius(t) -> "${t}C is below 30 celsius"
      fahrenheit(t) && t > 86 -> "${t}F is above 86 fahrenheit"
      fahrenheit(t) -> "${t}F is below 86 fahrenheit"

type MapCallback = fn(v: a): v

struct DB(conn_url: str) where

  fn connect(): Result[unit, DatabaseError] =
   `connect to the database
    online := status()
    if !online
      Err(NotOnline(conn_url))
    else
      Ok(unit)

  fn status(): bool =
    `check if the database is running
    res := exec("select 1")
    if res == None
      false
    else
      true

  fn exec(q: str): Result[unit] =
    `exec some stuff
    printLn("Going to exec q")

#[error]
enum DatabaseError =
  NotOnline(conn_url: str)
  RowReadFailure(query: str)

fn newDB(conn_url: str) result[DB, DatabaseError] =
  db := DB(conn_url: str)
  online := db.status()
  if !online
    err(NotOnline(conn_url))
  else
    db

fn (d: DB) status(): bool =
  res := d.exec("select 1")
  if res == None
    false
  else
    true

suite "Cat" do
  test "talks"  do
    c := Cat(name: "123", age: 1)
    c2 := Cat(...c, age: c.age + 1)
    c.talk()

  test "fullname"  do
    Assert.equal(Cat("rabby", 21).fullname(), "rabby21")

  test "ToStr" do
    items := [Cat("Molly", 9), Cat("Fenton", 6)]
        .retain(|p| p.name.size > 5)
        .map(|p| describe(p))
        .each(|d| printLn(d))
    Assert.equal(items[0].toStr(), "Cat<Fenton, 6>")

suite "diagonal" do
  test "3 4 5" do
    Assert.equal 5.0 (diagonal 3.0 4.0)
  test "5 12 13" do
    Assert.equal 5.0 (diagonal 3.0 4.0)
```

# Types

### any

The any type is an empty trait and is used to represent all types

### error

The error type is a trait that represents all Error types

## bool

A bool can be either `true` or `false`. It is used in logical operations and conditional statements.

```rb
assert true != false

if true || false
  print("works")
```

## byte

A byte represents an unsigned 8-bit number. It is mainly used to represent strings and binary data.

```go
up_event := 'a'
key_code := 102
```

## int

An int is a signed 64-bit number. It can be represented in various ways,

| Notation | Type        | Base    | Example                   |
| -------- | ----------- | ------- | ------------------------- |
| 0b       | Binary      | Base 2  | `0b00101010`, `0b1_1111`  |
| 0x       | Hexadecimal | Base 16 | `0xff00ff`, `0xFF80_0000` |
| number   | Standard    | Base 10 | `98762`, `98_762`         |

## float

A float represents a 64-bit floating point [IEEE-754-2008](https://en.wikipedia.org/wiki/Double-precision_floating-point_format).

| Type        | Example           |
| ----------- | ----------------- |
| Normal      | `1.2`, `-0.4`     |
| With suffix | `15.03f`, `12.0f` |
| E notation  | `2.7e-12`, `1e10` |

## dec

A dec is a decimal floating-point numbering format which is 64-bit data type.
It is intended for applications where it is necessary to emulate decimal rounding exactly, such as financial and tax computations.
It supports 16 decimal digits of significand and an exponent range of −383 to +384.

| Type       | Example           |
| ---------- | ----------------- |
| Normal     | `2.4d`, `-13.3d`  |
| E notation | `2.7e-12`, `1e10` |

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
    ok(u) -> return ok(u.id)
    err(IOError(e)) -> printLn("IO failed")
    err(e) -> printLn("generic error ${e.msg()}")
  ok(0)
```

# Declarations

## constants

Constants can be declared at the top level of a program. They cannot be reassigned.

- Primitive values like`int, float, str` are directly replaced in code.
- Reference values like `list, map, records` are initialized at program start and passed by reference when used. Their data can be modified.

```rb
const START_YEAR = 2101
const PI = 3.14159
const NAME = "pacos"
const DEBUG_ENABLED = true
const COUNT = count(10)
const COUNTRIES_LIST = list.of("US", "INDIA", "CANADA")
const COUNTRY_CODES = map.of(
  "in" => "INDIA",
  "us" => "United States",
  "ca" => "Canada"
)

fn count(n: int): int = n * 1
```

## variables

Variables can be declared only at the local scope of a function as they are mutable. They are references/pointers to data.
We use the Short Variable Declaration Operator `:=` to declare a variable

```go
fn calculate(n: int): int =
  a := 1 + n
  b := 1 * n
  a * b
```

## Functions

```rs
fn fib(n: int): int =
  match n
    0 | 1 -> n
    _ -> fib(n - 1) + fib(n - 2)

fn log(level: str, msg: str) =
  printLn("${level}: ${msg}")

fn info(msg: str) =
  printLn("INFO", msg)

fn warning(msg: str) =
  printLn("WARN", msg)

fn addLists[T](a: List[T], b: List[T]): List[T] =
  a.concat(b)

// Variadic function
fn addItems(items ...str) =
  for i, v := range items
    printLn("${i} ${v}")
```

## Records

A record is a collect of data indexed by fields. It is a reference type and reference counted.

```rs
struct Cat is Stringable =
  | name: str
  | age:  int

  fn Cat.withName(name: str): Cat =
    Cat(name: name, age: 0)

  fn fullname(): str =
    name + age.toStr()

  fn talk() =
    printLn("cat ${name} says meow")

  fn toStr(): str =
    "Cat<${fullname()}, ${age}>"
```

## Traits

```rs
trait Equatable[A] where
  fn eq(left: A, right: A): bool
  fn neq(left: A, right: A): bool

trait Comparable[A: Ord] where
  fn compare(left: A, right: A): Ordering
```

## Enums

An Algebraic Data Type

```rs
enum Ordering is Stringable =
  | LT
  | EQ
  | GT

  fn toStr(): str =
    match self
      LT -> "LT"
      EQ -> "EQ"
      GT -> "GT"
```

## Type

```rs
type Size = int
type Metre = float
type MapString[T] = Map[String, T]
```

# Statements

## Assignment statement

```rb
low, mid, high := 0, 0, n.numItems
x := 10
y := 20
xy_list := List.of(1, 2, 3)
xy_map := Map.of(1 => "one", 2 => "two")
```

## while statement

```rb
low, mid, high := 0, 0, n.size
while low < high
  mid = (low + high) / 2
  low = cmp > 0 ? mid + 1 : low
  high = cmp < 0 ? mid : high
  if cmp == 0
    return mid, true

while a > b
  a += 1

while Some(top) = stack.pop()
  printLn(top)
```

## for statement

```rb
for i := range 10
  sum += i

n := 5
for i := range n
  sum += i + 5

for k, v := range json_map
  sum += k + v

for v := range list
  sum += k + v
```

## if expression/statement

```py
if name == "Andreas"
  printLn("What a nice name!")
else if name == "Pacman"
  printLn("Game from the 80s")
else if name == ""
  printLn("Don't you have a name?")
else
  printLn("Boring name...")
```

## Match expression/statement

```rs
fn getPerimeter(shape: Shape): Result[float] =
  match shape
    Rectangle(r) -> Ok(2 * r.length() + 2 * r.width())
    Circle(c) -> Ok(2 * c.radius() * PI)
    _ -> Err(RuntimeError("expected shape but found ${@TypeName(shape)}"))

match x, y
  1, 1 -> "both are 1"
  1, _ -> "x is 1"
  _, 1 -> "y is 1"
  _, _ -> "neither is 1"

match n
  2 | 4 | 6 | 8 -> "This is an even number"
  1 | 3 | 5 | 7 -> "This is an odd number"
  _ -> "I'm not sure"

match
  cmp > 0 -> low = mid + 1
  cmp < 0 -> high = mid
  cmp == 0 -> return mid, true
```

## Operators

**assignment operator**

```go
  x := 5
	y := 3
	x += y  // 8
	x -= y  // 5
	x *= y  // 15
	x /= y  // 5
	x %= y  // 2
	x &= y  // 2
	x |= y  // 3
	x <<= y // 24
	x >>= y // 3
  a ?= 2  // elvis assignment operator
```

**not operator**

```rb
!a
!true
```

**ternary operator**

```rb
x ? a : b
```

**safe navigation operator**

```rb
a?.b?.c?.d
```

**elvis operator**

```rb
x ?: y
```

**cascade operator (remove??)**

```dart
paint := Paint()
  ..color = Colors.black
  ..strokeCap = StrokeCap.round
  ..strokeWidth = 5.0

v := list.of(1, 2, 3)
  ..add(4, 5)
  ..get(0)
```

**range operator**

```rs
type Seq0 = fn(yield: fn(): bool): bool
type Seq1[V] = fn(yield: fn(V): bool): bool
type Seq2[K, V] = fn(yield: fn(K, V): bool): bool

struct Tree[E] =
  | value E
  | left: Option[Tree]
  | right: Option[Tree]

  fn op_range(yld: fn(E): bool): bool =
    t ? true : t.left?.in_order(yld) && yld(t.val) && t.right?.in_order(yld)

let tree = Tree(
  value: 10,
  left: Tree(20, Tree(30), Tree(39)),
  right: Tree(40),
)

for t := range tree:
  printLn(v)
```

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
