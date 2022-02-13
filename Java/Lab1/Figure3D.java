package Java.Lab1;

abstract class Figure3D{
    public abstract double calcVolume();
}

class Cylinder<typeFigure> extends Figure3D{
    private typeFigure f;
    private double h;

    public Cylinder(typeFigure f, double h) throws Except{
        if (h > 0) {
			this.h = h;
			this.f = f;
		}
        else throw new Except(102, ": Error creating cylinder");
    }

    public double calcVolume(){
        return h * ((Figure) f).calcArea();
    }
};
