# 👾 Pacos Programming Language

- A statically typed, imperative programming language inspired by rust, koka.
- The compiler users the tree-sitter parser so has out of the box syntax highlighting support for helix and zed editor.

Here is some sample code, please enjoy.

```go
module lambda

import std/list
import std/math
import std/http

const START_YEAR = 2101
const END_YEAR = 2111
const NAME = "Gleam"
const SIZE = 100

fn sum(a: int, b: int): int = a + b

fn sum_all(series: list[int]): int =
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

fn firstItem(l: list[int]): int? =
  l[0]

fn firstItem(l: list[int]): int? =
  match l
    [] -> nil
    [head, ...rest] -> head

fn firstItem(l: list[int]): int? =
  if l.size > 0
    l[0]
  else
    nil

fn toCelsius(f: float): float =
  (f - 32) * (5 / 9)

record Cat[A: Comparable & Stringable](
  name: str
  age:  int
)

fn Cat.withName(name: str): Cat =
  Cat(name: name, age: 0)

fn (c: Cat) fullname(): str =
  c.name + c.age.to_str()

fn (c: Cat) talk() =
  printLn("cat ${c.name} says meow")

fn (c: Cat) toStr(): str =
  "Cat<{c.fullname()}, ${c.age}>"

enum Temperature =
  | celsius(float)
  | fahrenheit(float)

fn (s: Temperature) to_str(): str =
  match s
    celsius(t) && t > 30 -> "${t}C is above 30 celsius"
    celsius(t) -> "${t}C is below 30 celsius"
    fahrenheit(t) && t > 86 -> "${t}F is above 86 fahrenheit"
    fahrenheit(t) -> "${t}F is below 86 fahrenheit"

type MapCallback = fn(v: a): v

trait Comparable(
  fn compare(left: A, right: A): bool
)

trait ToStr(
  fn to_str(): str
)

fn connect_db(conn_url: str): DB! =
  db := postgres_connect(conn_url)?
  db.exec("select 1")?

fn db_select(conn_url: str): void! =
  db := new_db(conn_url)?
  db.exec("select 1")?

record DB(conn_url: str)

error DatabaseError
  DatabaseNotOnline(conn_url: str)
  RowReadFailure(query: str)

fn new_db(conn_url: str) DB! =
  db := DB(conn_url: str)
  online := db.check()?
  if !online
    Err(errors.DatabaseNotOnline(conn_url))
  else
    db

test("talks") |t|
  c := Cat(name: "123", age: 1)
  c.talk()

test("fullname") |t|
  Cat("rabby", 21).fullname() == "rabby21"
  c2 := Cat(...c, age: c.age + 1)

test("to_str") |t|
  items := [Cat("Molly", 9), Cat("Fenton", 6)]
      .retain(|p| p.name.size > 5)
      .map(|p| describe(p))
      .each(|d| printLn(d))
  assert items[0].to_str() == "Cat<Fenton, 6>"

bench("1231") |n|
  for i := range n
    printLn(i)
```

## Language Reference

**Keywords**

```rs
for,while,if,else if,else,record,enum,fn,assert,match,type
```

### Types

**any**

The any type is an empty trait and is used to represent all types

**error**

The error type is a trait that represents all Error types

**bool**

A bool can be either `true` or `false`. It is used in logical operations and conditional statements.

```rb
assert true != false

if true || false
  print("works")
```

**byte**

A byte represents an unsigned 8-bit number. It is mainly used to represent strings and binary data.

```rb
let data: []byte?
data = [104, 101, 197, 130, 197, 130, 111, 0]
```

**int**

An int is a signed 64-bit number. It can be represented in various ways,

```
0b - Binary (Base 2)
0x - Hexadecimal (Base 16)
27 - Standard (Base 10)
```

```rb
0b00101010
0b1_1111_1
0xff00ff
0xFF00FF
0xFF80_0000_0000_0000
98762
1_000_000
```

**float**

A float represents a 64-bit floating point [IEEE-754-2008](https://en.wikipedia.org/wiki/Double-precision_floating-point_format).

```java
1.2
-0.4
12.0f
15.03f
```

**dec**

A dec is a decimal floating-point numbering format which is 64-bit data type.
It is intended for applications where it is necessary to emulate decimal rounding exactly, such as financial and tax computations.
It supports 16 decimal digits of significand and an exponent range of −383 to +384.

```java
2.4d
-13.3d
```

**str**

A str represents an array of runes or unicode code points. It is encoded to UTF-8 by default.
It supports interpolation of variables/values that implement the ToStr interface.

```go
import std/os.{printLn}

sed := "Hello World"
name := "Pacos"
age := 1
printLn("Name ${name} age ${age}")
```

##list

```py
import pacos/list

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
import pacos/map

nums := Map.of(:one => 1, :two => 2)
map.get(:one) // => 1
map.get(:unknown) // => nil
friends_tree := Map.of(
  :value => "Fred",
  :left => Map.of(
    :value => "Jim",
  ),
  :right => Map.of(
    :value => "Shiela",
    :left => Map.of(
      :value => "Alice",
    ),
    :right => Map.of(
      :value => "Bob"
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

record Car(wheels: int)

c := some(Car(wheels: 2))

match c
  none -> print("no car")
  some(car) -> car.wheels
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

#[json]
record UserData(
  id: int,
  name: str,
  roles: List[str]
)

fn parse_version(header: List[int]): result[Version, error] =
  header.get(0) != nil ? v : error.InvalidHeaderLength(header.get(0))

fn double_number(s: str): result[int] =
  number_str.parse_int().map(|n| 2 * n)

fn fetch_data(route: str): result[UserData] =
  response := fetch(route)?
  data := response.body.readAll()?
  parse_json(data)?

fn main(): result[int] =
  double_number("10")?
  version := parse_version(list.of(1, 2))
  conn := pg.connect()?
  
  match pg.connect()
    ok(c) -> return 0
    err(e) -> return e

  res := fetch_data()
  match res
    ok(u) -> u.id
    err(IOError(e)) -> printLn("IO failed")
    err(e) -> printLn("generic error ${e.msg()}")
  ok(0)
```

**constants**

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

**Assignment statement**

```rb
low, mid, high := 0, 0, n.numItems
x := 10
y := 20
xy_list := [x, y]
xy_map := [x: x, y: y]
assoc_list = [:a => 1, :b => 2]
assoc_list[:a]
assoc_list["b"]
```

**While statement**

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
```

**For statement**

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

**if expression/statement**

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
    c -> err(RuntimeError("expected shape but found ${@TypeName(c)}"))

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

**not operator**

```rb
!a
!true
```

**ternary operator**

```rb
x ? x : y
```

**safe navigation operator**

```rb
a?.b?.c?.d
```

**double-bang operator/not-null assertion operator**

```rb
a!!.b
```

**elvis operator**

```rb
x ?: y
```

**elvis assignment operator**

```rb
atomic_number ?= 2
```

**spread operator**

```
list := [1, 2, 3]
list2 := [0, ...list]
assert list2.length == 4

list = nil
list3 := [0, ...list?];
assert list2.length == 1
```

**cascade operator**

```dart
paint := Paint()
  ..color = Colors.black
  ..strokeCap = StrokeCap.round
  ..strokeWidth = 5.0

v := list.of(1, 2, 3)
  ..add(4, 5)
  ..get(0)
```

**variadic operator**

```go
fn add(items ...str) =
  list.add(items)
```

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
```

**range operator**

```go
type Seq0 = fn(yield: fn(): bool): bool
type Seq1[V] = fn(yield: fn(V): bool): bool
type Seq2[K, V] = fn(yield: fn(K, V): bool): bool

record Tree[E](
  value E,
  left: option[Tree[E]],
  right: option[Tree[E]],
)

fn (t Tree[E]) op_range(yld: fn(E): bool): bool =
  t ? true : t.left?.in_order(yld) && yld(t.val) && t.right?.in_order(yld)

tree := Tree(
  value: 10,
  left: Tree(20, Tree(30), Tree(39)),
  right: Tree(40),
)

for t := range tree
  printLn(v)
```

## Generics

```
fn add[T: int | float](a: List[T], b: List[T]): List[T] =
  pass
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

## Todo

linter, formatter, test runner, language server, package manager