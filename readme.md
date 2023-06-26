![palm](https://user-images.githubusercontent.com/1687946/232222925-76a1d42d-fac9-4e6c-a24a-e622c4360871.svg)
JEYMESSOUSA

# Palm Programming Language

A programming language with a syntax mostly similar to [gleam](https://github.com/gleam-lang/gleam).  
Aims to be compiled to AMD64 and ARM64 using [QBE](https://github.com/8l/qbe) a small and fast compiler backend and also support the C ABI.

## Quick start

```sh
palm new demo  # Create a new project called demo
palm run       # Run the project
palm test      # Run the tests
```

## Syntax

### 1. Imports

```gleam
import nasa/rocket_ship
import animal/cat.{Cat, stroke}
import animal/cat as kitty
```

#### 2. Constants

```gleam
const start_year = 2101
const end_year = 2111
const name: String = "Gleam"
const size: Int = 100
```

#### 3. Inbuilt Types

```gleam
Byte
Bytes
Bool
Int
Float
List(element)
Nil
Result(value, error)
String
UtfCodepoint
Error
False
Nil
Ok
True
```

#### 4. Expressions

```gleam
import palm/string
import palm/bool

let value: Bool = {
    "Hello"
    42 + 12
    False
}
let celsius = { fahrenheit - 32 } * 5 / 9
let st = "Hello, {celsius}!"

case some_number {
  0 -> "Zero"
  1 -> "One"
  2 -> "Two"
  n -> "Some other number" // This matches anything
}

let description =
  case True {
    True -> "It's true!"
    False -> "It's not true."
  }

case x, y {
  1, 1 -> "both are 1"
  1, _ -> "x is 1"
  _, 1 -> "y is 1"
  _, _ -> "neither is 1"
}

case number {
  2 | 4 | 6 | 8 -> "This is an even number"
  1 | 3 | 5 | 7 -> "This is an odd number"
  _ -> "I'm not sure"
}

case xs {
  [] -> "This list is empty"
  [a] -> "This list has 1 element"
  [a, b] -> "This list has 2 elements"
  _other -> "This list has more than 2 elements"
}

// Pipe
"Hello"
|> string_builder.from_string
|> string_builder.reverse
|> string_builder.to_string // => "olleh"
```

#### 5. Types

#### A. ADT (Algebraic Data Type)

```gleam
type Bool = True | False

type MyDatabaseError =
  | InvalidQuery
  | NetworkTimeout

type User = LoggedIn(name: String) | Guest

fn get_name(user: User) {
  case user {
    LoggedIn(name) -> name
    Guest -> "Guest user"
  }
}

fn run() {
  let sara = LoggedIn(name: "Sara")
  let visitor = Guest
  let name = sara
    |> get_name() // => "Sara"
}

// Generics

type Result(value, reason) = Ok(value) | Error(reason)
```

#### B. Record Type

```gleam
import palm/option.{Option}

type Cat(name: String, cuteness: Int, age: Int)

type Person(
  name: String,
  gender: Option(String),
  shoe_size: Int,
  age: Int,
  is_happy: Bool
)

fn have_birthday(person: Person) -> Person {
  Person(..person, age: person.age + 1, is_happy: True)
}

fn run() {
  let cat = Cat(name: "Felix", cuteness: 9001, age: 5)
}

// Generics
type Box(inner: inner_type)

let a = Box(123) // type is Box(Int)
let b = Box("G") // type is Box(String)

// Opaque types
// At times it may be useful to create a type and make the constructors and fields private so that
// users of this type can only use the type through publically exported functions.

type Counter(value: Int)

fn new() {
  Counter(0)
}

fn increment(counter: Counter) {
  Counter(counter.value + 1)
}

let c = Counter(0)
|> increment()
|> increment()

// Type aliases

type Headers = List(String, String)
```

#### 6. Functions

```gleam
fn add(x: Int, y: Int) -> Int:
  x + y

fn multiply(x: Int, y: Int) -> Int {
  x * y
}

/// HoF
fn twice(f: fn(t) -> t, x: t) -> t {
  f(f(x))
}

fn add_one(x: Int) -> Int {
  x + 1
}

fn add_two(x: Int) -> Int {
  twice(add_one, x)
}

/// Type annotations

fn identity(x: some_type) -> some_type {
  x
}

fn inferred_identity(x) {
  x
}

/// Generic functions

fn list_of_two(my_value: a) -> List(a) {
  [my_value, my_value]
}

fn multi_result(x: a, y: b, condition: Bool) -> Result(a, b):
  case condition:
    True -> Ok(x)
    False -> Error(y)


/// Anonymous functions

fn run() {
  let add = fn(x, y) { x + y }

  add(1, 2)
}

/// Currying

fn add(x, y) {
  x + y
}

fn run():
  1
  |> add(3)
  |> add(6)
  |> add(9)

fn returns_nil(a) -> Nil {
  Nil
}
```

#### 7. Lists

```gleam
import palm/list

list.new("Krabs")
|> list.add("Spongebob")
|> list.length() // ==> 3
|> list.contains("Krabs") // ==> true
|> list.get(0) // => Some("Krabs")
|> list.get(5) // => None

let x = list.new(2, 3)
let y = list.new(1, ..x)
```

#### 8. Maps

```gleam
import palm/map

let nums = map.new(:one => 1, :two => 2) // => Map(k, v)
nums |> map.get(:one) // => Some(1)
nums |> map.get(:unknown) // => None
```

#### 9. Optional

```gleam
import palm/option.{Some, None}

let number = Some(1)

case number {
  Some(n) -> n
  None -> 0
}
```

#### 9. Result

```gleam
import palm/io.{println}
import palm/result.{Ok, Error}

let connect_res = Error("Connection failed")

case connect_res {
  Ok(a) -> println("Connection succeeded")
  Err(a) -> println("Error occurred: {a}")
}
```
