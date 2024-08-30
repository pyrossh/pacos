module std

`This is used to represent an error value across the language
trait Error {
  fn code(): Int
  fn msg(): Str
  fn cause(): Option[Error]
}

`Result is a type that represents either success `Ok` or failure `Err`
trait Result[T, E: Error] permits Ok[T], Err[E] {
  fn get() -> T
  fn getOrElse(default: T) -> T
}

tuple Ok[T](T) : Result[T, _] {
  fn get() -> T {
    return self.0
  }
  fn getOrElse(default: T) -> T {
    return self.0
  }
  fn map(cb: fn(a) -> b) -> Result[b, _] {
    return Ok(cb(self.0))
  }
}

tuple Err[E](E) : Result[_, E] {
  fn get() -> T {
    fail("called 'Result.get()' on an 'Err' value")
  }
  fn getOrElse(default: T) -> T {
    return default
  }
  fn mapErr(cb: fn(a) -> b) -> Result[_, b] {
    return Err(cb(self.0))
  }
}