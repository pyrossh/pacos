---
title: Traits
description: These are basic types
---

Traits are used to implement static/dynamic dispatch

```rs
trait Equatable[A] where
  fn eq(other: A): bool
  fn ne(other: A): bool

trait Comparable[A: Ord] where
  fn compareTo(other: A): int

trait ArithmeticOperator[A] where
  fn add(other: A): A
  fn subtract(other: A): A
  fn multiply(other: A): A
  fn divide(other: A): A
  fn remainder(other: A): A
  
trait UnaryOperator[A] where
  fn unaryPlus(): A
  fn unaryMinus(): A
  fn increment(): A
  fn decrement(): A

trait LogicalOperator[A] where
  fn and(other: A): A
  fn or(other: A): A
  fn not(): A

trait AssignmentOperator[A] where
  fn assign(other: A) A

trait BitwiseOperator[A] where
  fn bitwiseAnd(other: A): A
  fn bitwiseOr(other: A): A
  fn bitwiseXor(): A
  fn bitwiseLeftShift(): A
  fn bitwiseRightShift(): A
```