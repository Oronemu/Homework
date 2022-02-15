class Figure3D {
  func calcVolume() -> Double {
    fatalError("Must Override")
  }
}

class Cylinder: Figure3D {
  private let h: Double
  private let f: Figure
  
  init(_ h:Double, _ f:Figure) throws {
    if (h < 0) {
      throw ErrorCreatingObject.NegativeValue
    }
    self.f = f
    self.h = h
  }
  
  override func calcVolume() -> Double {
    return h * f.CalcArea()
  }
}
