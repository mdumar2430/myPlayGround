import java.io.*

public class MyThread1 implements Runnable{
	Thread t = null;
		
	public MyThread1(){
		t = new Thread(this, "Thread1");
		t.start();			
	}
	public void run() {
		for(int i=0;;i++){
			System.out.println("Welcome");
			Thread.sleep(1000);
		}
	}
}