---
title: Enum
description: These are basic types
---

An Algebraic Data Type

```rs
enum Ordering is Stringable =
  | LT
  | EQ
  | GT

  fn toStr(): str =
    match self
      LT -> "LT"
      EQ -> "EQ"
      GT -> "GT"

enum Shape where
  | Circle(int)
  | Square(int)
  | Rectangle(int, int)

enum Shape where
  Circle(int)
  Square(int)
  Rectangle(int, int)
```