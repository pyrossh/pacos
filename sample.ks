module sample

import std.{List, Map, Math, Random}

trait BinaryOp<T> {
  fn add(rhs: T) -> T
  fn sub(rhs: T) -> T
  fn mul(rhs: T) -> T
  fn div(rhs: T) -> T
  fn rem(rhs: T) -> T
  fn mod(rhs: T) -> T
  fn neg(rhs: T) -> T
}

trait BooleanOp<T> {
  fn not() -> T
  fn and(rhs: T) -> T
  fn or(rhs: T) -> T
  fn xor(rhs: T) -> T
}

trait Bitwise<T> {
  fn bitOr(rhs: T) -> T
  fn bitAnd(rhs: T) -> T
  fn bitXor(rhs: T) -> T
  fn shl(rhs: T) -> T
  fn shr(rhs: T) -> T
}

trait Comparable {
  fn compareTo(other: T) -> Compare
}

trait Shape permits Circle, Square, Rectangle {
  fn area() -> Float
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
  static fn fromInt(v: Int) -> Metre {
    return Metre(v)
  }

  fn toFloat() -> Float {
    return self.0
  }
}

`A Cat is new a new type of animal
record Cat(
  name: Option[Str],
  age: Int
): ToStr {
  static fn withName(name: Str): Cat(name: name, age: 0)
  static fn withAge(age: Int): Cat(name: "", age: age)

  fn init() {
    printLn("called init")
    require(name.isNotEmpty()) {
      "name shouldn't be empty"
    }
    ensure(name.size > 20) {
      ValidationErr("name too long")
    }
  }

  fn deinit() {
    printLn("called deinit")
  }

  fn fullname(): Str {
    return "${self.name} ${self.age}"
  }

  override fn toStr(): Str {
    return "Cat<${fullname()}, ${age}>"
  }
}

trait Error {}
trait IOError: Error {}
record FileReadError(file: File): IOError() {}
record DatabaseError(source: DataSource): IOError() {}

val lazyValue: Str by lazy {
    printLn("computed!")
    "Hello"
}

var name: Str by Delegates.observable("<no name>") {
    prop, old, new ->
      printLn("$old -> $new")
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

record LoopScope(running: Bool) {
  fn stop() {
    self.running = False
  }
}

fn loop(scope: LoopScope = LoopScope(), cond: Option<() -> Bool> = None(), builder: LoopScope.() -> Unit) {
  scope.apply(builder)
  if cond is Some {
    if cond() == True && scope.running == True {
      loop(scope, cond, builder)
    }
  } else {
    if scope.running == True {
      loop(scope, cond, builder)
    }
  }
}

fn example() {
  val items = listOf(1, 2, 3, 4, 5)
  items.each { i ->
    if i == 2 {
      continue()
    }
    if i == 4 {
      break()
    }
  }
  range(0, 10).step(1).each { i ->
    print("int ${i}")
  }
  loop().cond({ i < 5 }).do {
    print("forever")
  }
  loop {
    if (a > 5) {
      break()
    }
  }
  val list = "a b c d e f g h i j".split(" ")
  list.groupBy(3) { group ->
    puts group.join ""
  }
}

@result()
fn mkPerson(name: Str, age: Int) -> Result<Person, ValidationError> = result {
  Person(validName(name).bind(), validAge(age).bind())
}

@get("/posts")
fn handler(req: Request) -> Response {
  Response()
    .status(2)
    .body("213")
    .headers("1" => "2")
}

fn hasFlag(b: bool, d: List) {
  return data
}
