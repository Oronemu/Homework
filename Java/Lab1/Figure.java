package Java.Lab1;

import static java.lang.Math.PI;
import static java.lang.Math.sqrt;

interface Figure{
    double calcArea();
    double calcPerimeter();
}

class Circle implements Figure {
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

    Circle(double radius) throws Exception{
        if (radius > 0){
            this.radius = radius;
        }
        else throw new Exception("Error creationg circle");
    }
}

class Triangle implements Figure{
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

    Triangle(double a, double b, double c) throws Exception{
        if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a)
	    {
            this.a = a;
            this.b = b;
            this.c = c;
	    }
        else throw new Exception("Error creating triangle");
    }
}

class Ring implements Figure{
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

    Ring(double r, double R) throws Exception{
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
        else throw new Exception("Error creating ring");
    }
}