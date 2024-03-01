---
title: While Statement
description: These are basic types
---

```rb
low, mid, high := 0, 0, n.size
while low < high
  mid = (low + high) / 2
  low = cmp > 0 ? mid + 1 : low
  high = cmp < 0 ? mid : high
  if cmp == 0
    return mid, true

while a > b
  a += 1

while Some(top) = stack.pop()
  printLn(top)
```