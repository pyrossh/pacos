---
title: Operators
description: These are basic types
---

### Arithmetic
### Relational
### Logical
### Bitwise
### Assignment
### Precedence

**assignment operator**

```go
  x := 5
	y := 3
	x += y  // 8
	x -= y  // 5
	x *= y  // 15
	x /= y  // 5
	x %= y  // 2
	x &= y  // 2
	x |= y  // 3
	x <<= y // 24
	x >>= y // 3
  a ?= 2  // elvis assignment operator
```

**not operator**

```rb
!a
!true
```

**ternary operator**

```rb
x ? a : b
```

**safe navigation operator**

```rb
a?.b?.c?.d
```

**elvis operator**

```rb
x ?: y
```

**cascade operator (remove??)**

```dart
paint := Paint()
  ..color = Colors.black
  ..strokeCap = StrokeCap.round
  ..strokeWidth = 5.0

v := list.of(1, 2, 3)
  ..add(4, 5)
  ..get(0)
```

**range operator**

```rs
type Seq0 = fn(yield: fn(): bool): bool
type Seq1[V] = fn(yield: fn(V): bool): bool
type Seq2[K, V] = fn(yield: fn(K, V): bool): bool

struct Tree[E] =
  | value E
  | left: Option[Tree]
  | right: Option[Tree]

  fn op_range(yld: fn(E): bool): bool =
    t ? true : t.left?.in_order(yld) && yld(t.val) && t.right?.in_order(yld)

let tree = Tree(
  value: 10,
  left: Tree(20, Tree(30), Tree(39)),
  right: Tree(40),
)

for t := range tree:
  printLn(v)
```
