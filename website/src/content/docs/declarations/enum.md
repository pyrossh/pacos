---
title: Enum
description: These are basic types
---

An Algebraic Data Type

```rs
enum Ordering =
  | LT
  | EQ
  | GT

fn (Ordering->ToStr) toStr() str =
  match self
    LT -> "LT"
    EQ -> "EQ"
    GT -> "GT"

enum Shape =
  | Circle(int)
  | Square(int)
  | Rectangle(int, int)

fn (Shape) toStr() str =
  match self
    Circle(r) -> printLn("Circle(${r})")
    Square(s) -> printLn("Square(${s})")
    Rectangle(w, h) -> printLn("Rectangle(${w}, ${h})")

fn (Shape) area() float =
  match self
    Circle(r) -> PI * r * r
    Square(s) -> s * s
    Rectangle(w, h) -> w * h

fn (Shape) draw() float =
  match self
    Circle(r) -> PI * r * r
    Square(s) -> s * s
    Rectangle(w, h) -> w * h
```
