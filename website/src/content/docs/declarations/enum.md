---
title: Enum
description: These are basic types
---

An Algebraic Data Type

```rs
enum Ordering: Stringable {
  LT
  EQ
  GT
} {
  override fn toStr(): Str {
    match self
      LT -> "LT"
      EQ -> "EQ"
      GT -> "GT"
  }
}


enum Shape {
  Circle(int)
  Square(int)
  Rectangle(int, int)
} {
  fn toStr(): Str {
    match self
      Circle(r) -> printLn("Circle(${r})")
      Square(s) -> printLn("Square(${s})")
      Rectangle(w, h) -> printLn("Rectangle(${w}, ${h})")
  }

  fn area(): Float {
    match self
      Circle(r) -> PI * r * r
      Square(s) -> s * s
      Rectangle(w, h) -> w * h
  }

  fn draw(): Float {
    match self
      Circle(r) -> PI * r * r
      Square(s) -> s * s
      Rectangle(w, h) -> w * h
  }
}
```
