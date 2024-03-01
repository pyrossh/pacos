---
title: Match
description: These are basic types
---

```rs
fn getPerimeter(shape: Shape): Result[float] =
  match shape
    Rectangle(r) -> Ok(2 * r.length() + 2 * r.width())
    Circle(c) -> Ok(2 * c.radius() * PI)
    _ -> Err(RuntimeError("expected shape but found ${@TypeName(shape)}"))

match x, y
  1, 1 -> "both are 1"
  1, _ -> "x is 1"
  _, 1 -> "y is 1"
  _, _ -> "neither is 1"

match n
  2 | 4 | 6 | 8 -> "This is an even number"
  1 | 3 | 5 | 7 -> "This is an odd number"
  _ -> "I'm not sure"

match _
  cmp > 0 -> low = mid + 1
  cmp < 0 -> high = mid
  cmp == 0 -> return mid, true
```