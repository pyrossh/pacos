module std

`This is used to represent an error value across the language
trait Error {
  fn code(): Int
  fn msg(): Str
  fn cause(): Option[Error]
}

`Result is a type that represents either success Ok or failure Err
enum Result[T, E: Error] {
  Ok(T)
  Err(E)
} {
  fn isOk(): bool =
    match self
      Ok(v) -> True
      Err(e) -> False

  fn isErr(): bool =
    !self.isOk()

  fn get(): T =
    match self
      Ok(v) -> v
      Err(e) -> crash("called `result.get()` on a `Err` value")

  fn getOrElse(d: T): T =
    match self
      Ok(v) -> v
      Err(_) -> d

  fn map(cb: fn(v: T)): Self =
    match self
      Ok(v) -> cb(v)
      Err(_) -> self

  fn mapErr(cb: fn(e: error)): Self =
    match self
      Ok(v) -> self
      Err(e) -> cb(v)
}
