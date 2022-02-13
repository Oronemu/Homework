package Java.Lab1;

import static java.lang.Math.PI;
import static java.lang.Math.sqrt;

abstract class Figure{
    public abstract double calcArea();
    public abstract double calcPerimeter();
}

class Circle extends Figure{
    private double radius;

    public double calcArea(){
        return PI * radius * radius;
    }

    public double calcPerimeter(){
        return 2 * PI * radius;
    }

    public double getRadius(){
        return radius;
    }

    Circle(double radius) throws Except{
        if (radius > 0){
            this.radius = radius;
        }
        else throw new Except(101, ": Error creating circle");
    }
}

class Triangle extends Figure{
    private double a, b, c;

    public double calcArea(){
       double p = calcPerimeter() / 2;
       return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    public double calcPerimeter(){
        return a + b + c;
    }

    public double getA(){
        return a;
    }

    public double getB(){
        return b;
    }

    public double getC(){
        return c;
    }

    Triangle(double a, double b, double c) throws Except{
        if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a)
	    {
            this.a = a;
            this.b = b;
            this.c = c;
	    }
        else throw new Except(1, "Error creating triangle");
    }
}

class Ring extends Figure{
    private double r, R;

    public double calcArea(){
        return PI * R * R - PI * r * r;
    }

    public double calcPerimeter(){
        return 2 * PI * r + 2 * PI * R;
    }

    public double getSmallRadius(){
        return r;
    }

    public double getBigRadius(){
        return R;
    }

    Ring(double r, double R) throws Except{
        if (r > 0 && R > 0 && r != R) {
            if (r > R) {
                this.r = R;
                this.R = r;
            }
            else {
                this.r = r;
                this.R = R;
            }
        }
        else throw new Except(1, "Error creating ring");
    }
}