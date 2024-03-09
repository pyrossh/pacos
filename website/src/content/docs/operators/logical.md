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
  x, y := 5, 3
  z := x + y // 8
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
trait Rangeble where  
  fn range[V](yield: fn(V): bool): bool

trait RangebleKV where  
  fn rangeKV[K, V](yield: fn(K, V): bool): bool

record Tree[E](
  value: E
  left: Option[Tree] = None
  right: Option[Tree] = None
)

fn (Tree->Rangeble) range(yld: fn(E): bool): bool =
  t.left?.range(yld) && yld(t.val) && t.right?.range(yld)

let tree = Tree(
  value: 10,
  left: Tree(20, Tree(30), Tree(39)),
  right: Tree(40),
)
for t := range tree
  printLn(v)
```
