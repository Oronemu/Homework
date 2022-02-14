#if os(Linux)
    import Glibc
#else
    import Darwin
#endif

print("Enter radius and height of cylinder")
var check: Bool = false

repeat {
  guard let r = Double(readLine() ?? "") else {
    print("r is NaN")
    continue
  }
  guard let h = Double(readLine() ?? "") else {
    print("h is NaN")
    continue
  }
  let circle = Circle(r)
  let cyliner = Cylinder(h, circle)
  print("Cylinder volume is \(round(cyliner.calcVolume() * 100) / 100)")
  check = true
} while !check
