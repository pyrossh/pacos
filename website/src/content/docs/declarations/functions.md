---
title: Functions
description: These are basic types
---

```rs
fn fib(n: int) -> int =
  match n
    0 | 1 -> n
    _ -> fib(n - 1) + fib(n - 2)

fn log(level: str, msg: str) =
  printLn("${level}: ${msg}")

pub fn info(msg: str) =
  log("INFO", msg)

pub fn warning(msg: str) =
  log("WARN", msg)

fn addLists(a: List[T], b: List[T]): List[T] =
  a.concat(b)

// Variadic function
fn addItems(items ...str) =
  for i, v := range items
    printLn("${i} ${v}")
```