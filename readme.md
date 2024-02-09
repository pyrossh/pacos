# 👾 Pacos Programming Language

A simple statically typed imperative programming language. Its main aim to be simple and easy to code correct programs. It takes inspiration for golang, ponylang, and dart. It comes packed with linting, formatting, test runner, language server, and package management in-built.

The compiler users the tree-sitter parser so has out of the box syntax highlighting support for helix and zed editor.

Here is some sample code, please enjoy.
```rs
module lambda

import pacos/list
import pacos/math
import pacos/http

const start_year = 2101
const end_year = 2111
const name: String = "Gleam"
const size: Int = 100

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

fn first_item(l: list[int]): int? =
  l[0]

fn first_item(l: list[int]): int? =
  match l
    [] -> nil
    [head, ...rest] -> head

fn first_item(l: list[int]): int? =
  if l.size > 0
    l[0]
  else
    nil

fn to-celsius(f: float): float =
  (f - 32) * (5 / 9)

class Cat[A: Comparable & Stringable] is Stringable:
  name: str
  age: int

  fn Cat():
    pass

  fn ~Cat():
    pass

 fn Cat.with_name(name: str):
    Cat(name: name, age: 0)

  fn fullname() -> str:
    name + age.to_str()

  fn talk():
    println("cat ${name} says meow")

  fn to_str() -> str:
    "Cat<{fullname()}, ${age}>"

record Cat[A](
  name: str
  age:  int
) where A is Comparable & Stringable

fn Cat.with_name(name: str) =
  Cat(name: name, age: 0)

fn (c: Cat) init(): str =
  c.name + c.age.to_str()

fn (c: Cat) deinit(): str =
  c.name + c.age.to_str()

fn (c: Cat) fullname(): str =
  c.name + c.age.to_str()

fn (c: Cat) talk() =
  println("cat ${c.name} says meow")

fn (c: Cat) to_str(): str =
  "Cat<{c.fullname()}, ${c.age}>"


type MapCallback = fn(v: a): v

trait Comparable(
  fn compare(left: A, right: A): bool
)

trait ToStr(
  fn to_str(): str
)

enum Temperature =
  | celsius(float)
  | fahrenheit(float)

fn (s Temperature) to_str() =
  match s
    celsius(t) && t > 30 -> "${t}C is above 30 celsius"
    celsius(t) -> "${t}C is below 30 celsius"
    fahrenheit(t) && t > 86 -> "${t}F is above 86 fahrenheit"
    fahrenheit(t) -> "${t}F is below 86 fahrenheit"


group("Cat Record") |g|
  test("talks") |t|
    c := Cat(name = "123", age = 1)
    c.talk()

  test("fullname") |t|
    Cat("rabby", 21).fullname() == "rabby21"
    c2 := Cat(...c, age: c.age + 1)

  test("to_str") |t|
    items := [Cat("Molly", 9), Cat("Fenton", 6)]
        .retain(|p| p.name.size > 5)
        .map(|p| describe(p))
        .each(|d| println(d))
    assert items[0].to_str() == "Cat<Fenton, 6>"

test("enum ordinal value") |t|
  expect(Value.zero).to_equal(0)
  expect(Value.one).to_equal(1)
  expect(Value.two).to_equal(2)

bench("1231") |t, n|
  for 0..n |i|
    println(i)
```

## Language Reference

**Keywords**

```rs
for,while,if,else,record,enum,fn,assert,when,match,type
```

### Types
```
nil, any, bool, byte, int, float, dec, str, time, duration, regex, uuid
[] for lists      list[int], list[list[int]]
[] for maps       map[int], map[map[int]]
? for optional    int? str?
! for return error types int!, str!
```

**nil**

The nil type is used to represent types that are nilable

**any**

The any type is an empty trait and is used to represent all types

**bool**

A bool can be either `true` or `false`. It is used in logical operations and conditional statements.

```rb
assert true != false

if true || false then
  print("works")
end
```

**byte**

A byte represents an unsigned 8 bit number. It is mainly used to represent strings and binary data.
```rs
let data: []byte?
data = [104, 101, 197, 130, 197, 130, 111, 0]
```

**int**

An int is a signed 64 bit number. It can be represented in various ways,
0b - Binary (Base 2)
0x - Hexadecimal (Base 16)
13 - Standard (Base 10)

```
0b00101010
0b1_1111_1
0xff00ff
0xFF00FF
0xFF80_0000_0000_0000
98762
1_000_000
```

**float**

A float represents a 64-bit floating point (52-bit mantissa) IEEE-754-2008 binary64

**str**

A str represents a slice of runes or unicode code points. It is encoded to UTF-8 by default.
It supports interpolation of variables/values that implement the ToStr interface.

```rs
"Hello World"
name := "Pacos"
age := 1
println("Name ${name} age ${age}")
```
"\u0061" == "a"


**list**

```rs
a := [1, 2, 3]                // list[int]
b := [[1, 2], [3, 4], [5, 6]] // list[list[int]]
```

**map**

```rs
tree = [
  value: "Fred",
  left: [
    value: "Jim",
  ],
  right: [
    value: "Shiela",
    left: [
      value: "Alice",
    },
    right: [
      value: "Bob"
    ],
  ],
]
```


**Assignment statement**

```rs
low, mid, high := 0, 0, n.numItems
x := 10
y := 20
xy_list := [x, y]
xy_map := [x: x, y: y]
assoc_list = [a: 1, b: 2]
assoc_list[:a]
assoc_list["b"]
```

**While statement**

```rs
while low < high
  mid = (low + high) / 2
  low = cmp > 0 > mid + 1 : low
  high = cmp < 0 ? mid : high
  if cmp == 0
    return mid, true

while (eventuallyErrorSequence()) |value| {
  sum1 += value;
else |err|
  try expect(err == error.ReachedZero);
```

**For statement**

```rs
for players_list |value|
  if value == 0
    continue
  sum += value

for items[0..1] |v|
  sum += v

for 0..5 |v|
  sum3 += v

let list = for filter(players_list) |v|

items
  .map(|v| v + 1)
  .each(|v| println("v", v))

items
  .each(v =>
    if v == 2
      break
    if v == 0
      continue
    println(v)
  )
  .map {v => v * 2}
  .reduce(0, |v| => v + 1)

fn range(start: int, end: int, cb: (v: T) -> IterateResult) =

range(0, 5, |v| =>
  sum3 += v
)

// Iterate over multiple objects.
// All lengths must be equal at the start of the loop, otherwise detectable
// illegal behavior occurs.
for items, items2 |i, j|
  count += i + j
```

**When expression/statement**

```rs
when
  cmp > 0 -> low = mid + 1
  cmp < 0 -> high = mid
  cmp == 0 -> return mid, true

when x, y
  1, 1 -> "both are 1"
  1, _ -> "x is 1"
  _, 1 -> "y is 1"
  _, _ -> "neither is 1"

when number
  2 | 4 | 6 | 8 -> "This is an even number"
  1 | 3 | 5 | 7 -> "This is an odd number"
  _ -> "I'm not sure"

match xs
  [] -> "This list is empty"
  [a] -> "This list has 1 element"
  [a, b] -> "This list has 2 elements"
  _ -> "This list has more than 2 elements"

import palm/list

list.new("Krabs")
|> list.add("Spongebob")
|> list.length() // ==> 3
|> list.contains("Krabs") // ==> true
|> list.get(0) // => Some("Krabs")
|> list.get(5) // => None

let x = list.new(2, 3)
let y = list.new(1, ..x)

import palm/map

let nums = map.new(:one => 1, :two => 2) // => Map(k, v)
nums |> map.get(:one) // => Some(1)
nums |> map.get(:unknown) // => None

import palm/io.{println}
import palm/result.{Ok, Error}

let connect_res = Error("Connection failed")

case connect_res {
  Ok(a) -> println("Connection succeeded")
  Err(a) -> println("Error occurred: {a}")
}
```

Arithmetic (+, -, /, *, @divFloor, @sqrt, @ceil, @log, etc.)
Bitwise operators (>>, <<, &, |, ~, etc.)
Comparison operators (<, >, ==, etc.)

**if expression/statement**

```rs
if (a) |value| {
 try expect(value == 0);
} else |err| {
    _ = err;
    unreachable;
}
```

### Conditional operators

**not operator**

```
!a
!true
```

**ternary operator**

```
x ? x : y
```

**safe navigation operator**

```
a?.b?.c?.d
```

**Safe index operator**
```
array?[1]
```

**elvis operator**

```
x ?: y
```

**elvis assignment operator**

```
atomic_number ?= 2
```

**Range operator**
```
for 5..10 |i|
  println(i)
```
