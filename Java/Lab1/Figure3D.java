package Java.Lab1;

interface Figure3D{
    double calcVolume();
}

class Cylinder<typeFigure> implements Figure3D{
    private typeFigure f;
    private double h;

    public Cylinder(typeFigure f, double h) throws Exception{
        if (h > 0) {
			this.h = h;
			this.f = f;
		}
        else throw new Exception("Error creating cylinder");
    }

    public double calcVolume(){
        return h * ((Figure) f).calcArea();
    }
};
