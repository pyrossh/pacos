module std

trait Bool : ToStr permits True, False {
  operator fn eq(other: Bool) {
    return (self is True && other is True) || (self is False && other is False)
  }
  operator fn neq(other: Bool) {
    return !self.eq()
  }
  operator fn and(other: Bool) {
    return self is False || other is False ? False : True
  }
  operator fn or(other: Bool) {
    return self is True || other is True ? True : False
  }
  operator fn not(): Bool {
    return self is True ? False : True
  }
  override fn toStr() {
    return self is True ? "true" : "false"
  }
}

tuple True() : Bool {}
tuple False() : Bool {}