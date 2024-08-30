use std::ops::Add;

#[derive(Clone, Copy, Debug, PartialEq)]
struct Point<T> {
    val: T,
}

impl<T: Add<Output = T>> Add for Point<T> {
    type Output = Self;

    fn add(self, b: Self) -> Self::Output {
        Self {
            val: self.val + b.val,
        }
    }
}

fn main() {
    let a = Point::<i32> { val: 1 };
    let b = Point::<i32> { val: 2 };

    let c = Point::<f32> { val: 1.0 };

    println!("{:?}", a + b);
    println!("{:?}", c == c);
}
