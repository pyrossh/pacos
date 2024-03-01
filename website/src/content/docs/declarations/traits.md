---
title: Traits
description: These are basic types
---

Traits are used to implement static/dynamic dispatch

```rs
trait HasEq[A] where
  fn eq(other: A): bool

trait Equatable[A] where
  fn eq(other: A): bool
  fn ne(other: A): bool

trait Comparable[A: Ord] is Equatable where
  fn lt(other: A): bool
  fn le(other: A): bool
  fn ge(other: A): bool
  fn gt(other: A): bool
  fn compare(other: A): int
```