package model;

public class Calculator {
    
    public static double sum(double a, double b) {
        return a + b;
    }

    public static double diff(double a, double b) {
        return a - b;
    }

    public static double mult(double a, double b) {
        return a * b;
    }

    public static double div(double a, double b) throws Exception {
        if (b == 0) throw new Exception("Деление на ноль");
        else return a / b;
    }
}
