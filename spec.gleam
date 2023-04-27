import gleam/io
import gleam/bool
import gleam/string
import gleam/list
import gleam/http/response.{Request, Response}
import gleam/bit_builder.{BitBuilder}

pub fn main() {
  io.print("hi")
  False
  |> bool.nand(False)
}

pub type Result(value, reason) {
  Ok(value)
  Error(reason)
}

pub fn fib(x: Int) -> Int {
  when x {
    0..1 -> 1
    _ -> fib(x - 1) + fib(x - 2)
  }

  when x > 5 {
  }
}

pub fn handler(request: Request) -> Response {
  let body = bit_builder.from_string("Hello, world!")

  response.new(200)
  |> response.prepend_header("made-with", "Gleam")
  |> response.set_body(body)
}

pub fn main() {
  let res =
    request.new()
    |> request.set_method(Get)
    |> request.set_host("test-api.service.hmrc.gov.uk")
    |> request.set_path("/hello/world")
    |> request.prepend_header("accept", "application/vnd.hmrc.1.0+json")
    |> request.fetch()

  case res {
    Ok(b) -> {
      let data = json.parse(b)
      response.new(200)
      |> response.set_body(json.stringify(data))
    }
    Error(_) -> {
      response.new(500)
      |> response.set_body("Could not find data")
    }
  }
}

pub fn all(results: List(Result(a, e))) -> Result(List(a), e) {
  list.try_map(results, fn(x) { x })
}

pub fn add(x: Int, y: Int) -> Int {
  x + y
}

pub fn multiply(x: Int, y: Int) -> Int {
  x * y
}

/// This function takes a function as an argument
pub fn twice(f: fn(t) -> t, x: t) -> t {
  f(f(x))
}

pub fn add_one(x: Int) -> Int {
  x + 1
}

pub fn add_two(x: Int) -> Int {
  twice(add_one, x)
}

pub const start_year = 2101

pub const end_year = 2111

pub fn is_before(year: Int) -> Bool {
  year < start_year
}

pub fn is_during(year: Int) -> Bool {
  start_year <= year && year <= end_year
}

pub fn describe(year: Int) -> String {
  case year {
    year if year < start_year -> "Before"
    year if year > end_year -> "After"
    _ -> "During"
  }
}

pub const name: String = "Gleam"

pub const size: Int = 100

pub type Headers =
  List(#(String, String))

pub fn main() {
  let string = "123"
  string
  |> string_builder.from_string
  |> string_builder.reverse
  |> string_builder.to_string
}

pub external fn random_float() -> Float =
  "rand" "uniform"

// Elixir modules start with `Elixir.`
pub external fn inspect(a) -> a =
  "Elixir.IO" "inspect"

pub external type Queue(a)

pub external fn new() -> Queue(a) =
  "queue" "new"

pub external fn length(Queue(a)) -> Int =
  "queue" "len"

pub external fn push(Queue(a), a) -> Queue(a) =
  "queue" "in"

fn favourite_number() -> Int {
  // The type annotations says this returns an Int, but we don't need
  // to implement it yet.
  todo
}

pub fn main() {
  favourite_number() * 2
}

fn more_usage() {
  list.new(1, 2, 3)
  |> list.contains(any: 2)
}

pub fn get_name(user: User) {
  case user {
    LoggedIn(name) -> {
      let a = 1.2
      let b = 4.5
      let c = n * factorial(n - 1)
      name
    }
    Guest -> "Guest user"
  }
}

pub type Result(p, q) {
  Ok(p)
  Error(q)
}

// pub type Cat(
//   name: String,
//   cuteness: Int,
//   age: Int
// )

pub fn make_api_call(r: String) -> Result(String, String) {
  make_request(r) |> response.map()
}

pub fn map(res: Response) -> Result(String, String) {
  | res.status() >= 500 -> Error("failed")
  | _ -> Ok("success")
}

pub fn getColorHex(c: String) -> Int {
  when c {
    "red" -> 0xff0000
    "blue" -> 0xff0123
    "green" -> 0xff0123
    "black" -> 0x000000
    "white" -> 0xffffff
    "violet" -> 0x0f0f23
  }
}