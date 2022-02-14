#if os(Linux)
    import Glibc
#else
    import Darwin
#endif

class Figure {
  func CalcArea() -> Double{
    return 0
  }
  func CalcPerimeter() -> Double{
    return 0
  }
}

class Circle: Figure {
  private let r:Double

  init(_ r:Double) {
    self.r = r
  }
  
  override func CalcArea() -> Double {
    return Double.pi * r * r;
  }
  
  override func CalcPerimeter() -> Double {
    return 2 * Double.pi * r;
  }
}

class Triangle: Figure {
  private let a: Double
  private let b: Double
  private let c: Double
  
  init(_ a:Double, _ b:Double, _ c:Double) {
    self.a = a
    self.b = b
    self.c = c
  }
  
  override func CalcArea() -> Double{
    let p = CalcPerimeter() / 2
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }
  
  override func CalcPerimeter() -> Double {
    return a + b + c
  }
}

class Ring: Figure {
  private let r:Double
  private let R:Double
  
  init(_ r:Double, _ R:Double) {
    self.r = r
    self.R = R
  }
  
  override func CalcArea() -> Double{
    return Double.pi * R * R - Double.pi * r * r;
  }
  override func CalcPerimeter() -> Double {
    return 2 * Double.pi * r + 2 * Double.pi * R;
  }
}
