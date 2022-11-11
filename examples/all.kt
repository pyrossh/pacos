import github.com/std/http

enum Color(val rgb: Int) {
  RED(0xFF0000),
  GREEN(0x00FF00),
  BLUE(0x0000FF)
}

fun Color.isReddish() => Bool {
  return this == Color.Red
}

trait List(
  val name: String
  fun area(): Float
)

class Email(value: String)

fun Email.init() => {
  if !value.match("/s\@/s") {
    throw error("Email not value ${value}")
  }
}

class Array<T>(
  var items: []T,
  var size: Int
)
  
fun Array<T>.get(index: Int): T => {
  return items[int]
}

fun Array<T>.set(index: Int, value: T) => { 
  items[i] = value
}

fun listOf<T>(elements: ...T): List<T> => {
  return Array(elements)
}

class User(
  val name: String,
  val age: Int,
  val email: Email,
)

fun User.init() => {
  assert(name.size > 5, "name is not valid")
  assert(age > 0 && age < 130, "age is not valid")
  assert(email.test("regex"), "email is not valid")
}

fun User.invoke() => {
  println("Hello")
  listOf(0, 1, 2, 3).map { "Number ${it}" }
  range(0, 10, 1).each { i, v ->
    echo i, v
  }
}

fun User.getFullName() => String {
  return "${name} 123"
}

@Get("/about")
fun about() => HtmlNode {
  val sir = "John"
  html {
    head {
      title {
        "Tesla"
      }
    }
    body {
      div {
        "Welcome ${sir}" 
      }
    }
  }
}

fun main(args: List<String>) => {
  println(hello)
  val items = args?
    .map { it.name }
    .filter { it.isVerified }
    .each { it -> it.name } ?: listOf()
  val john = User("John", 2)
  val jill = User(name = "Jill", age = 3)
  val jack = john.copy(age = 5)
  val (name, age) = jack
  // Pair, Triple
  
  val name2 = jill?.let {
    it.name + "123"   
  }

  jill?.run {
    println(it)
  }


  names.each { name, i -> 
    println(name, i)
  }

  TODO()

  when message {
    New -> println("new $id: $quantity")
    Cancel -> println("cancel $id")
  }
}