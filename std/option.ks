module std

`Option is a type that represents either value present `Some` or nothing present `None`
trait Option[T] permits Some, None {
  fn get() -> T

  `get if present otherwise return default value
  fn getOrElse(default: T) -> T
  
  fn toStr() -> Str
}

tuple Some[T](T) : Option[T] {
  fn get() -> T {
    return self.0
  }
  fn getOrElse(default: T) -> T {
    return self.0
  }
  fn toStr() -> Str {
    return "Some(${self.0.toStr()})"
  }
}

tuple None() : Option[_] {
  fn get() -> T {
    fail("called 'Option.get()' on a 'None' value")
  }
  fn getOrElse(default: T) -> T {
    return default
  }
  fn toStr() -> Str {
    return "None"
  }
}

