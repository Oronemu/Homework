package Java.Lab1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Figure figure;
        Cylinder<Figure> cylinder;

        Scanner input = new Scanner(System.in);

        System.out.println("Введите радиус круга и высоту:");

        System.out.print("Радиус: ");
        double r = input.nextDouble();

        System.out.print("Высота: "); 
        double h = input.nextDouble();

        input.close();

        try {
            figure = new Circle(r);
        }
        catch(Exception except){
            System.out.println(except.getMessage());
            return;
        }
        try {
            cylinder= new Cylinder<Figure>(figure, h);
        }
        catch(Exception except){
            System.out.println(except.getMessage());
            return;
        }
        System.out.println("Объем цилиндра: " + cylinder.calcVolume());
    }
}
