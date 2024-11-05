tuple Int() {
  `Euler's number, the base of natural logarithms, e
  `https://oeis.org/A001113
  const E = 2.718f

  `The natural logarithm of 10
  `https://oeis.org/A002392
  const LN10 = 2.302f

  `The natural logarithm of 2
  `https://oeis.org/A002162
  const LN2 = 0.693f

  `The base 10 logarithm of e
  `formula: 1 / LN10
  const LOG10E = 0.434f

  `The base 2 logarithm of e
  `formula: 1 / LN2
  const LOG2E = 1.442f

  `The ratio of the circumference of a circle to its diameter
  `https://oeis.org/A000796
  const PI = 3.14159f

  `https://oeis.org/A001622
  const PHI = 1.6180f

  `The square root of 1/2
  const SQRT1_2 = 0.707f

  `The square root of 2
  `https://oeis.org/A002193
  const SQRT2 = 1.414f

  `https://oeis.org/A019774
  const SQRT_E = 1.64872f

  `https://oeis.org/A002161
  const SQRT_PI  = 1.77245f

  `https://oeis.org/A139339
  const SQRT_PHI = 1.27201f

  `The difference between 1 and the smallest floating point number greater than 1
  `formula: 7/3 - 4/3 - 1
  const EPSILON = 2.220446049250313e-16f

  `Lowest value of int
  const MIN_INT_VALUE = -0x8000_0000_0000_0000

  `Highest value of int
  const MAX_INT_VALUE = 0x7FFF_FFFF_FFFF_FFFF

  `Lowest valur of float
  const MIN_FLOAT_VALUE = 4.9406564584124654417656879286822137236505980e-324

  `Highest valur of float
  const MAX_FLOAT_VALUE = 1.79769313486231570814527423731704356798070e+308

  fn abs(v: float): float =
    `returns the absolute value of a number v
    a < 0 ? -a : a

  fn acos(v: float) =
    if v < 0.1
      asin(v)
    else
      asin(-1v)


  `2**28
  const LARGE = 1 << 28

  fn acosh(v: float): float =
    when
      x < 1 | IsNaN(x) -> // first case is special case
        NaN()
      x == 1 ->
        0
      x >= Large ->
        Log(x) + Ln2 // x > 2**28
      x > 2 ->
        Log(2*x - 1/(x+Sqrt(x*x-1))) // 2**28 > x > 2
      _ -> 
        t := x - 1
        // ((2*t+t*t).sqrt() + t).log1p()
        Log1p(t + Sqrt(2*t+t*t)) // 2 >= x > 1



  fn asin(v: float) = 0f
  fn asinh(v: float) = 0f
  fn atan(v: float) = 0f
  fn atan2(v: float) = 0f
  fn atanh(v: float) = 0f
  fn cbrt(v: float) = 0f
  fn ceil(v: float) = 0f
  fn clz32(v: float) = 0f
  fn cos(v: float) = 0f
  fn cosh(v: float) = 0f
  fn exp(v: float) = 0f
  fn to_int(): int = 0
  fn to_str(): str = ""

  fn random(): float =
    pass

  fn is_int(): bool =
    pass

  fn is_finite(): bool = true
    ` Check whether this number is finite, ie not +/-infinity and not NaN.
    ` True if exponent is not all 1s
    (bits() and 0x7FF0_0000_0000_0000) != 0x7FF0_0000_0000_0000

  // Check whether this number is +/-infinity
  is_infinite:  Bool =>
    // True if exponent is all 1s and mantissa is 0
    ((bits() and 0x7FF0_0000_0000_0000) == 0x7FF0_0000_0000_0000) and  // exp
    ((bits() and 0x000F_FFFF_FFFF_FFFF) == 0)  // mantissa

  // Check whether this number is NaN.
  fn is_nan(): Bool =>
    // True if exponent is all 1s and mantissa is non-0
    ((bits() and 0x7FF0_0000_0000_0000) == 0x7FF0_0000_0000_0000) and  // exp
    ((bits() and 0x000F_FFFF_FFFF_FFFF) != 0)  // mantissa

  fn to_exponential(v: float): str = ""

  fn to_fixed(v: float): str = ""

  fn to_precision(v: float): str = ""


  fn abs(): F64 = @"llvm.fabs.f64"(this)
  fn ceil(): F64 = @"llvm.ceil.f64"(this)
  fn floor(): F64 = @"llvm.floor.f64"(this)
  fn round(): F64 = @"llvm.round.f64"(this)
  fn trunc(): F64 = @"llvm.trunc.f64"(this)

    fun log(): F64 => @"llvm.log.f64"(this)
  fun log2(): F64 => @"llvm.log2.f64"(this)
  fun log10(): F64 => @"llvm.log10.f64"(this)
  fun logb(): F64 => @logb(this)

  fun pow(y: F64): F64 => @"llvm.pow.f64"(this, y)
  fun powi(y: I32): F64 =>
    ifdef windows then
      pow(y.f64())
    else
      @"llvm.powi.f64"(this, y)
    end

  fun sqrt(): F64 =>
    if this < 0.0 then
      _nan()
    else
      @"llvm.sqrt.f64"(this)
    end

  fn abs(a: int): int => a < 0 ? -a : a
  fn to_str(v: int): str = ""

  fn op_add(x: int, y: int): int =
    @"i64.add"(x, y)


    sub
    mul
    div
    rem

    min
    max

    to_float()
}