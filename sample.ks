module sample

import std.{List, Map, Math, Random}

Int.random()
Float.random()
Float.PI

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

  fn fullname() -> Str {
    return "${self.name} ${self.age}"
  }

  override fn toStr() -> Str {
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

@handler("GET", "/posts")
fn getPosts() -> List<Post> {
  return listOf(Post(id: 123))
}

fn handler(req: Request) -> Response {
  return Response()
    .status(2)
    .body("213")
    .headers("1" => "2")
}

fn hasFlag(b: bool, d: List) {
  return data
}

record Greeter(name: String) {
  fn greet() {
    println("Hello, ${name}")
  }
}

fn main(args: List[String]) {
  let g = Greeter(name: "abc")
  g = g.copy(
    name = "123"
  )
  Greeter(...g, name: "123")
}


fn main() {
  val a = (1 * 5) + (2 + 3)
  match a {
    case a < b => {
      printLn(a != b)
    }
    case a > 9 => {
      printLn(a == 9)
    } 
    case a < 9 => {
      printLn(b == 0)
    }
    case _ => {
      printLn(a == 9)
    }
  }

  val list = listOf<Shape>(Circle(123), Square(20))

  match list.get(0) {
    case Circle(c): {
      printLn("${c}")
    }
    case Square(a): {
      printLn("${a}")
    }
  }
}



birds = 3
iguanas = 2
total = addAndStringify birds iguanas

main() =
    Stdout.line! "There are $(total) animals."

addAndStringify(num1: Int, num2: Int) -> Str = 
    (num1 + num2) |> Int.toStr()

addAndStringify = \num1: Int, num2: Int -> Str
    Num.toStr (num1 + num2)

val user = User(1, 2, 3)

params = {"one" => 1, "two" => 2, "three" => 3}
params.each do |k,v|
  puts("#{k}=#{v}")
end

lib LibM
  fun sqrt(x: LibC::Double) -> LibC::Double
  fun pow(x: LibC::Double, y: LibC::Double) -> LibC::Double
end

primitive Int : Comparable, ToStr
  fn abs() -> Float
  fn ceil() -> Float
  fn floor() -> Float
  fn round() -> Float
  fn trunc() -> Float
  fun log() -> Float
  fun log2() -> Float
  fun log10() -> Float
  fun logb() -> Float
  fun pow(y: Float) -> Float
    LibM.pow(self, y)
  end
  fun pow(y: Int) -> Float
    pow(y.toFloat())
  end
  fun sqrt() -> Float
    LibM.sqrt(self)
  end
end

primitive Str : Comparable, ToStr
  val data: Buffer

  fun get(i: Int) -> Char
    return data.get(i)
  end

  fun contains(search: Str) -> Bool
  end

  fun indexOf(sub: Str) -> Int
  end

  fun test(pattern: Regex) -> Bool
  end

  fun search(key: Str) -> (Int, Bool)
    val (low, mid, high) = (0, 0, n.numItems)
    while low < high do
      mid = (low + high) / 2
      val cmp = key > n.items[mid].key
      low = cmp > 0 ? mid + 1 : low
      high = cmp < 0 ? mid : high
      if cmp == 0 then
        return (mid, True)
      end
    end
    return (low, False)
  end

  fun startsWith(search: str) -> Bool
  end

  fun endsWith(search: Str) -> Bool
  end

  fun concat(other: Str) -> Str
    s + other
  end

  fun toStr() -> Str
  end

  fun matchPattern(pattern: Regex) -> []Str
  end

  fun matchAll(pattern: Regex) -> []Str
  end

  fun padStart(sub: Str, count: Int) -> Str
  end

  fun padEnd(sub: Str, count: Int) -> Str
  end

  fun repeat(count: Int) -> Str
  end

  fun replace(pattern: Regex, sub: Str) -> Str
  end

  fun replaceAll(pattern: Regex, sub: Str) -> Str
  end

  fun search(pattern: Regex) -> Str
  end

  fun slice(start: Int, e: Int) -> Str
  end

  fun split(separator: Str, limit: Int) -> []Str
  end

  fun sub(start: Int, e: Int) -> Str
  end

  fun toLower() -> Str
  end
end

record Response(a): Option(a, _)
  val body: Buffer = emptyBuffer()
  val headers: Map(Str, Str) = emptyMap()
  val status: Int = 0

  fun header(k: Str, v: Str) -> Response
    headers.add(kv)
  end

  fun body(buf: Buffer) -> Response
    body = buf
  end

  fun status(v: Int) -> Response
    status = v
  end
end

User::create()
  .name("John Doe")
  .email("john@example.com")
  .todo(Todo::create().title("Make pizza"))
  .todo(Todo::create().title("Finish Toasty"))
  .todo(Todo::create().title("Sleep"))

trait Result(a, b) permits Ok(a), Err(b)
  fn ok() -> a
  fn err() -> b
  fn okOrElse(default: a) -> a
end

tuple Ok(a): Result(a, _)
  fn ok() -> a = self.0
  fn err() -> fail("called 'Result.err()' on an 'Ok' value")
  fn okOrElse(default: a) -> a = self.0
  fn map(cb: fn(a) -> b) -> Result(b) = Ok(cb(self.0))

tuple Err(a): Result(_, a)
  fn get() -> a = fail("called 'Result.get()' on an 'Err' value")
  fn err() -> self.1
  fn okOrElse(default: a) -> a = default
  fn mapErr(cb: fn(a) -> b) -> Result(_, b) = Err(cb(self.1))

trait Option(a) permits Some(a), None
  fn some() -> a
  fn someOrElse(default: a) -> a
  fn map(cb: fn(a) -> b) -> Option(b)

tuple Some(a): Option(a)
  fn some() -> a = self.0
  fn someOrElse(default: a) -> a = self.0
  fn map(cb: fn(a) -> b) -> Option(b) = Some(cb(self.0))

tuple None(a): Option(_)
  fn some() -> a = fail("called 'Option.some()' on an 'Some' value")
  fn someOrElse(default: a) -> a = default
  fn stoplightColor(something: Int) -> Color =
    if something > 0 then
        Red
    else if something == 0 then
        Yellow
    else
        Green

  fn stoplightStr(stoplightColor: Color) -> Str =
      when stoplightColor is
        Red -> "red"
        Green -> "green"
        Yellow -> "yellow"
      end

fn dddd(data: Option(Str)) -> Str =
  if Some(v) = data then
    v.subString(0, 3)
  else if a ==  b then
    "123"
  else
    "1231"

fn dddd(data: Option(Str)) -> Str =
  if Some(v) = data then
    v.subString(0, 3)
  else if a ==  b then
    "123"
  else
    if a < 100 then
      printLn("Data")
    else
      println("No Data")


names = ["Sam", "Lee", "Ari"]
names |> List.append("Jess")
names |> List.map(\num -> num * 2)
List.map([1, 2, 3], \num -> num * 2)

range data, 1, 2, do k,v 
  puts(k, v)
end 