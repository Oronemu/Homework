class Figure3D {
  func calcVolume() -> Double {
    return 0
  }
}

class Cylinder: Figure3D {
  private let h: Double
  private let f: Figure
  
  init(_ h:Double, _ f:Figure) {
    self.f = f
    self.h = h
  }
  
  override func calcVolume() -> Double {
    return h * f.CalcArea()
  }
}
