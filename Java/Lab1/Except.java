package Java.Lab1;

class Except extends Exception{
    private int code;
    private String message;

    Except(int code, String message){
        this.code = code;
        this.message = message;
    }

    public void show(){
        System.out.println("Error: " + code + " " + message);
    }
}