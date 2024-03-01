---
title: Basic Types
description: These are basic types
---

## bool

A bool can be either `true` or `false`. It is used in logical operations and conditional statements.

```rb
assert true != false

if true || false
  print("works")
```

## byte

A byte represents an unsigned 8-bit number. It is mainly used to represent strings and binary data.

```go
up_event := 'a'
key_code := 102
```

## int

An int is a signed 64-bit number. It can be represented in various ways,

| Notation | Type        | Base    | Example                   |
| -------- | ----------- | ------- | ------------------------- |
| 0b       | Binary      | Base 2  | `0b00101010`, `0b1_1111`  |
| 0x       | Hexadecimal | Base 16 | `0xff00ff`, `0xFF80_0000` |
| number   | Standard    | Base 10 | `98762`, `98_762`         |

## float

A float represents a 64-bit floating point [IEEE-754-2008](https://en.wikipedia.org/wiki/Double-precision_floating-point_format).

| Type        | Example           |
| ----------- | ----------------- |
| Normal      | `1.2`, `-0.4`     |
| With suffix | `15.03f`, `12.0f` |
| E notation  | `2.7e-12`, `1e10` |

## dec

A dec is a decimal floating-point numbering format which is 64-bit data type.
It is intended for applications where it is necessary to emulate decimal rounding exactly, such as financial and tax computations.
It supports 16 decimal digits of significand and an exponent range of −383 to +384.

| Type       | Example           |
| ---------- | ----------------- |
| Normal     | `2.4d`, `-13.3d`  |
| E notation | `2.7e-12`, `1e10` |