module std

trait Bool : ToStr permits True, False {
  operator fn eq(other: Bool) -> Bool
  operator fn neq(other: Bool) -> Bool
  operator fn and(other: Bool) -> Bool
  operator fn or(other: Bool) -> Bool
  operator fn not() -> Bool
  override fn toStr() -> Str
}

tuple True() : Bool {
  operator fn eq(other: Bool) -> Bool {
    return other is True
  }
  operator fn neq(other: Bool) -> Bool {
    return !self.eq()
  }
  operator fn and(other: Bool) -> Bool {
    return other is False ? False : True
  }
  operator fn or(other: Bool) -> Bool {
    return True
  }
  operator fn not() -> Bool {
    return False
  }
  override fn toStr() -> Str {
    return "True"
  }
}


tuple False() : Bool {
  operator fn eq(other: Bool) -> Bool {
    return other is False
  }
  operator fn neq(other: Bool) -> Bool {
    return !self.eq()
  }
  operator fn and(other: Bool) -> Bool {
    return False
  }
  operator fn or(other: Bool) -> Bool {
    return other is True ? True : False
  }
  operator fn not() -> Bool {
    return True
  }
  override fn toStr() -> Str {
    return "False"
  }
}