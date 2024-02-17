# 👾 Pacos Programming Language

A simple, statically typed, imperative, minimalistic programming language. Its main aim to be simple and easy to code correct programs. It takes inspiration for golang, ponylang, and dart. It comes packed with linting, formatting, test runner, language server, and package management in-built.

The compiler users the tree-sitter parser so has out of the box syntax highlighting support for helix and zed editor.

Here is some sample code, please enjoy.

```rb
module lambda

import pacos/list
import pacos/math
import pacos/http

START_YEAR = 2101
END_YEAR = 2111
NAME = "Gleam"
SIZE = 100

fn sum(a: int, b: int): int = a + b

fn sum_all(series: list[int]): int =
  series.reduce(0, |v| v + 1)

fn fib(n: int) -> int
  match n
    0 | 1 -> n
    _ -> fib(n - 1) + fib(n - 2)

fn fib(n: int) -> int
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

record Cat[A: Comparable & Stringable](
  name: str
  age:  int
)

fn Cat.with_name(name: str): Cat =
  Cat(name: name, age: 0)

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

fn (s: Temperature) to_str(): str =
  match s
    celsius(t) && t > 30 -> "${t}C is above 30 celsius"
    celsius(t) -> "${t}C is below 30 celsius"
    fahrenheit(t) && t > 86 -> "${t}F is above 86 fahrenheit"
    fahrenheit(t) -> "${t}F is below 86 fahrenheit"


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
      .each(|d| println(d))
  assert items[0].to_str() == "Cat<Fenton, 6>"

bench("1231") |n|
  for i := range n
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
[1, 2, 3] for lists      list[int], list[list[int]]
[:a => 1, :b => 2] for maps       map[int], map[map[int]]
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

if true || false
  print("works")
```

**byte**

A byte represents an unsigned 8 bit number. It is mainly used to represent strings and binary data.

```rb
let data: []byte?
data = [104, 101, 197, 130, 197, 130, 111, 0]
```

**int**

An int is a signed 64 bit number. It can be represented in various ways,
0b - Binary (Base 2)
0x - Hexadecimal (Base 16)
27 - Standard (Base 10)

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

A float represents a 64-bit floating point (52-bit mantissa) IEEE-754-2008 binary64

**str**

A str represents an array of runes or unicode code points. It is encoded to UTF-8 by default.
It supports interpolation of variables/values that implement the ToStr interface.

```go
"Hello World"
name := "Pacos"
age := 1
println("Name ${name} age ${age}")
```

**list**

```py
import pacos/list

a := [1, 2, 3]                // list[int]
b := [[1, 2], [3, 4], [5, 6]] // list[list[int]]

actors := ["Krabs", "Squidward"]
actors.add("Spongebob")
actors.length() // ==> 3
actors.contains("Krabs") // ==> true
actors.get(0) // => "Krabs"
actors.get(5) // => nil

items
  .map(|v| v + 1)
  .each(|v| println("v", v))
  .reduce(0, |v| v + 1)
```

**map**

```rb
import pacos/map

nums := Map.new(:one => 1, :two => 2)
map.get(:one) // =>`
map.get(:unknown) // => nil

friends_tree := [
  :value => "Fred",
  :left => [
    :value => "Jim",
  ],
  :right => [
    :value => "Shiela",
    :left => [
      :value => "Alice",
    },
    :right => [
      :value => "Bob"
    ],
  ],
]

friends_tree
  .map(|k, v| v)
  .each(|k, v| println("v", v))
  .reduce(0, |k, v| v + 1)
```

**Constants**

Constants can be declared at the top level of a program. They cannot be reassigned.

- Primitive values like`int, float, str` are directly replaced in code.
- Reference values like `list, map, records` are initialized at program start and passed by reference when used. Their data can be modified.

```rb
PI = 3.14159f
ERR_MESSAGE = "An unknown error occured"
COUNT = count(10)
COUNTRIES_LIST = ["US", "INDIA", "CANADA"]
COUNTRY_CODES = [
  :in => "INDIA",
  :us => "United States",
  :ca => "Canada"
]

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

**Assignment Operators**

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

type Seq0 = fn(yield: fn(): bool): bool
type Seq1[V] = fn(yield: fn(V): bool): bool
type Seq2[K, V] = fn(yield: fn(K, V): bool): bool

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

record Tree[E](
  value E,
  left: Tree[E]?,
  right: Tree[E]?,
)

fn (t Tree[E]) op_range(yld: fn(E): bool): bool =
  t ? true : t.left.in_order(yld) && yld(t.val) && t.right.in_order(yld)

tt := Tree(
  value: 10,
  left: Tree(20, Tree(30), Tree(39)),
  right: Tree(40),
)

for t := range tt
  println(v)
```

**When expression/statement**

```rb
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
```

Arithmetic (+, -, /, \*, @divFloor, @sqrt, @ceil, @log, etc.)
Bitwise operators (>>, <<, &, |, ~, etc.)
Comparison operators (<, >, ==, etc.)

**if expression/statement**

```rb
if post.valid()
  render_create_view()
else
  render_post(post: post)
```

### Conditional operators

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
```

**variadic function**

```go
fn add(items ...str) =
  list.add(items)
```

**generics**

```
fn add[T: int | float](a: List[T], b: List[T]): List[T] =
  pass
```

```
fn create_post_action(req: Request): Response =
  post := Post(title = req.params.title, body = req.params.body)
  if post.valid()
    RenderNewView()
  else
    post := createRecord(post)
    setSuccessMessage("Post created")
    redirectTo("/posts")
```

### General naming convention

| Item                    | Convention               |
| ----------------------- | ------------------------ |
| Modules                 | snake_case               |
| Types                   | UpperCamelCase           |
| Traits                  | UpperCamelCase           |
| Enum variants           | UpperCamelCase           |
| Functions               | snake_case               |
| Methods                 | snake_case               |
| General constructors    | new or with_more_details |
| Conversion constructors | from_some_other_type     |
| Local variables         | snake_case               |
| Constants               | SCREAMING_SNAKE_CASE     |
| Generics                | single uppercase letter  |
