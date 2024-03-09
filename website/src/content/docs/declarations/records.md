---
title: Records
description: These are basic types
---

A record is a collect of data indexed by fields. It is a reference type and reference counted.

```rs
struct Cat is Stringable where
  name: str
  age:  int

  static fn withName(name: str): Cat =
    Cat(name: name, age: 0)

  fn fullname(): str =
    name + age.toStr()

  fn talk() =
    printLn("cat ${name} says meow")

  override fn plus(other: Cat): Cat =
    Cat(...self, age: self.age + other.age)

  override fn toStr(): str =
    "Cat<${fullname()}, ${age}>"

struct Rand(seed: int) =
  self.seed = seed

fn Rand.int(): int =
  1 * 2 * seed

struct Cat(name: str, age: int) =
  self.name = name
  self.age = age

fn Cat::withName(name: str): Cat =
  Cat(name: name, age: 0)

fn Cat.fullname(): str =
  name + age.toStr()

fn Cat.talk() =
  printLn("cat ${name} says meow")

fn Cat.plus(other: Cat): Cat =
  Cat(...self, age: self.age + other.age)

fn Cat.toStr(): str =
  "Cat<${fullname()}, ${age}>"

record Response
  field _body: Buffer
  field _headers: Map[str, str]
  field _status: int

  fn _init() =
    _body = Buffer()
    _headers = Map[str, str]()
    _status = 0

  fn header(kv Pair): Self =
    _headers.add(kv)

  fn body(b Buffer): Self =
    _body = b

  fn status(v int): Self =
    _status = v

struct Map[K, V](kvs: ...Pair[K, V]) =
  `A Map is a data structure describing a contiguous section of an array stored separately from the slice variable itself.
  `A Map is not an array. A slice describes a piece of an array.
  self._items = List[Pair[K, V]](kvs)
  self.index = int(0)
  self.length = int(kvs.length)

fn Map.range(yld: fn(k: K, v: V): bool): bool =
  `provide a range operation for map
  for pair := range self._items
    if !yld(pair.k, pair.v)
      false
  true

fn Map.get(k: K): Option[V] =
  for pair := range self._items
    if pair.k == k
      return v
  None

fn Map.set(k: K, v: V) =
  for pair := range self._items
    if pair.k == k
      pair.v = v
      return
  self._items.add(k, v)

fn Map.putIf(k: K, v: V) =
  `put a value into the Map if its not already present
  return

struct Map[K, V] where
  _items: List[Pair[K, V]]

  static fn of[K, V](kvs: ...Pair[K, V]): Map[K, V] =
    Map[K, V]().add(kvs)

  fn range(yld: fn(k: K, v: V): bool): bool =
    `allows the range operator to iterate over the Map
    for item := range self._items
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
    for pair := range self._items
      if pair.k == k
        pair.v = v
        return
    self._items.add(k, v)

  fn putIf(k: K, v: V) =
    `put a value into the Map if its not already present
    pass
```
