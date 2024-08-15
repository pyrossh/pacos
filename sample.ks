module std

import std.{List, Map, Math, Random}

trait Comparable {
  fn compareTo(other: T): Compare
}

trait Shape(type: Int)

enum Shape(index: Int) {
  Circle(Int): Shape(0)
  Square(Int): Shape(1)
  Rectangle(Int, Int): Shape(2)
} {
  fn area() = match self {
    Circle(r) -> PI * r * r,
    Square(n) -> n * n,
    Rectangle(l, b) -> l * b, 
  }
}

trait Shape {
  fn area(): Float
}

tuple Circle(Int): Shape {
  fn area() = PI * self.0 * self.0 
}

tuple Square(Int): Shape {
  fn area() = self.0 * self.0 
}

tuple Rectangle(Int, Int): Shape {
  fn area() = self.0 * self.1 
}

tuple Metre(Float): Shape {
  static fn fromInt(v: Int): Metre {
    return Metre(v)
  }

  fn toFloat(): Float {
    return self.0
  }
}

`Bool is a type that represents true or false
enum Bool {
  True
  False
} 

`Option is a type that represents either value present Some or nothing present
enum Option[T] {
  Some(T)
  None
} {
  fn isNone(): Bool = match self
    None -> True
    Some(t) -> False

  fn isSome(): Bool = !self.isNone()

  fn get(): T = match self
    Some(val) -> val
    None -> fail("called 'option.get()' on a 'none' value")

  `get if present otherwise return default value
  fn getOrElse(default: T): T = match self
    Some(val) -> val
    None -> default

  fn toStr(): str = match self
    Some(v) -> v.toStr()
    None -> "None"
}

enum Result[T, E] {
  Ok(T)
  Err(E)
} {
  fn map(cb: fn(a) -> b): Result[b, e] = match self {
    Ok(t) -> Ok(cb(t))
    Err(e) -> Err(e)
  }
}

`A Cat is new a new type of animal
record Cat(
  name: Option[Str],
  age: Int
): Strable {
  static fn withName(name: Str): Cat(name: name, age: 0)
  static fn withAge(age: Int): Cat(name: "", age: age)

  init {
    require(name.isNotEmpty()) {
      "name shouldn't be empty"
    }
    ensure(name.size > 20) {
      ValidationErr("name too long")
    }
  }

  fn fullname(): Str = "${name} ${age}"

  override fn toStr(): Str {
    "Cat<${fullname()}, ${age}>"
  }
}

trait Error {}
trait IOError: Error {}
record FileReadError(file: File): IOError() {}
record DatabaseError(source: DataSource): IOError() {}

object RuntimeError : Error {
  val message = "Hello"
}

val lazyValue: Str by lazy {
    println("computed!")
    "Hello"
}

var name: Str by Delegates.observable("<no name>") {
    prop, old, new ->
      println("$old -> $new")
}

trait ClosedShape {
  fn area(): Int
}

record Rectangle(width: Int, height: Int) : ClosedShape {
  override fn area() = width * height
}

record Window(bounds: Rectangle) : ClosedShape by bounds

record Response(
  body: Buffer = emptyBuffer(),
  headers: Map[Str, Str] = emptyMap(),
  status: Int = 0,
) {

  fn header(kv: Pair): Self {
    headers.add(kv)
  }

  fn body(b: Buffer): Self {
    body = b
  }

  fn status(v int): Self {
    status = v
  }
}

fn iterate() {
  val items = listOf(1, 2, 3, 4, 5)
  for i in items {
    if i == 5 {
      continue
    }
    if i == 10 {
      break
    }
  }
  while i < 5 {
    print("Hello")
  }
}

fn mkPerson(name: Str, age: Int): Either<Problem, Person> = either {
  Person(validName(name).bind(), validAge(age).bind())
}

#[get("/posts")]
fn handler(req: Request): Response {
  Response()
    .status(2)
    .body("213")
    .headers("1" => "2")
}

fn hasFlag(b: bool, d: List) {
  return data
}


// enum LoopStatus {
//   Continue
//   Break
// }

// fn example() {
//   val items = listOf(1, 2, 3, 4, 5)
//   items.each { i ->
//     if i == 2 {
//       Continue
//     }
//     if i == 4 {
//       Break
//     }
//   }
//   range(0, 10).step(1).each { i ->
//     print("int ${i}")
//   }
//   loop({ i < 5 }) {
//     print("forever")
//   }
//   val list = "a b c d e f g h i j".split(" ")
//   list.groupBy(3) { group ->
//     puts group.join ""
//   }
// }

// tailcall fn loop(cb: () -> Bool, run: () -> LoopStatus) {
//   if (cb()) {
//     if (run() != Break) {
//       loop(cb, run)
//     }
//   }
// }