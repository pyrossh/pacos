---
title: Records
description: These are basic types
---

A record is a collect of data indexed by fields. It is a reference type and reference counted.

```rs
record Cat(name: str, age: int) where
  static fn withName(name: str) Cat =
    Cat(name: name, age: 0)

  fn fullname() str =
    name + age.toStr()

  fn talk() =
    printLn("cat ${name} says meow")

  override fn plus(other: Cat) Cat =
    Cat(...self, age: self.age + other.age)

  override fn toStr() str =
    "Cat<${fullname()}, ${age}>"

record Map[K, V](items: List[Pair[K, V]]) where

  static fn of[K, V](kvs: ...Pair[K, V]) Map[K, V]
    Map[K, V]().add(kvs)

  fn range(yld: fn(k: K, v: V): bool) bool
    `allows the range operator to iterate over the Map
    for item := range self.items
      if !yld(item.k, item.v)
        false
    true

  fn add(kvs: ...Pair[K, V]) =
    `adds the specified elements to the start of the list

  fn get(k: K): Option[V] =
    `get a value from the Map using key k
    for k, v := range m
      if k == k
        return v
    None

  fn set(k: K, v: V) =
    `put a value into the Map
    for pair := range self.items
      if pair.k == k
        pair.v = v
        return
    self.items.add(k, v)

  fn putIf(k: K, v: V) =
    `put a value into the Map if its not already present
    pass
```
