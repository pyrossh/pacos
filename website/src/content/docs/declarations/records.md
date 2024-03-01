---
title: Records
description: These are basic types
---

A record is a collect of data indexed by fields. It is a reference type and reference counted.

```rs
struct Cat is Stringable where
  | name: str
  | age:  int

  fn Cat.withName(name: str): Cat =
    Cat(name: name, age: 0)

  fn fullname(): str =
    name + age.toStr()

  fn talk() =
    printLn("cat ${name} says meow")

  fn toStr(): str =
    "Cat<${fullname()}, ${age}>"
```