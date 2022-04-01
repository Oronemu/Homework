public class Task1 {
    
    public static void main(String[] args) {
        Printer p = new Printer();
        new Thrd(p, "Поток 1");
        new Thrd(p, "Поток 2");
    }
}

class Printer {

    boolean first = true;

    public void print(String threadName) {
        System.out.println(threadName);
    }
}

class Thrd implements Runnable {

    Printer p;
    String name;
    Thread thread;

    public Thrd(Printer p, String name) {
        this.p = p;
        this.name = name;
        thread = new Thread(this, name);
        thread.start();
    }

    @Override
    public void run() {
        while(true) {
            synchronized (p) {
                try {
                    Thread.sleep(500);
                    p.print(name);
                    p.notify();
                    p.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
