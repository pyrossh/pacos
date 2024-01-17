fun print10()
  for(1,10) fn(i)
    println(i)

fun encode2( s : string, shift : int )
  s.map( fn(c)
    if c < 'a' || c > 'z' then return c
    val base = (c - 'a').int
    val rot  = (base + shift) % 26
    (rot.char + 'a')
  )

fun printhi10()
  repeat(10)
    println("hi")

fun sublist( xs : list<a>, start : int, len : int = xs.length ) : list<a>
  if start <= 0 return xs.take(len)
  match xs
    Nil        -> Nil
    Cons(_,xx) -> xx.sublist(start - 1, len)

fun chisqr( xs : list<float64>, ys : list<float64> ) : float64
  zipwith(xs,ys, fn(x,y) ((x - y)^2.0)/y ).foldr(0.0,(+))


fun fib(n : int) : div int
  if n <= 0   then 0
  elif n == 1 then 1
  else fib(n - 1) + fib(n - 2)

fun fib2(n)
  var x := 0
  var y := 1
  repeat(n)
    val y0 = y
    y := x+y
    x := y0
  x

fun wrong() : (() -> console ())
  var x := 1
  (fn(){ x := x + 1; println(x) })


struct person
  age : int
  name : string
  realname : string = name

type person
  Person
    age : int
    name : string
    realname : string = name

val brian = Person( 29, "Brian" )


type color
  Red
  Green
  Blue

type number
  Infinity
  Integer( i : int )

type bool
  False
  True

type list<a>
  Nil
  Cons{ head : a; tail : list<a> }

type tree
  Tip
  Bin( left: tree, value : int, right: tree )

fun tmap-inorder( t : tree, f : int -> int ) : tree
  match t
    Bin(l,x,r) -> Bin( l.tmap-inorder(f), f(x), r.tmap-inorder(f) )
    Tip        -> Tip
