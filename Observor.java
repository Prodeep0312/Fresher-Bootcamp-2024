/*OLDER CODE

class Thread {
    int id;
    String state;
    String priority;
    String culture;
    
    Thread()
    {
        this.state="created";
        System.out.println(state);
    }
    
    void start()
    {
         this.state="running";
         System.out.println(state);
    }
    
    void abort()
    {
        this.state="aborted";
         System.out.println(state);
    }
    
      void sleep()
    {
        this.state="sleep";
         System.out.println(state);
    }
      void waits()
    {
        this.state="wait";
         System.out.println(state);
    }
    
    void suspended()
    {
        this.state="suspended";
         System.out.println(state);
    }
    
    
}
class HelloWorld {
    public static void main(String[] args) {
        Thread th=new Thread();
        th.start();
        th.abort();
        th.sleep();
        th.waits();
        th.suspended();
    }
}

*/

import java.util.*;

interface Iobservor{
    void update(String state);
}

class Dashboard implements Iobservor{
    String message;
    public void update(String message){
        this.message = message;
        System.out.println("NOTIFICATION/n thread state  changed to : " + message);
    }
}
class Thread {
    int id;
    String state;
    String priority;
    String culture;
    
    ArrayList<Iobservor> observors;
    
    
    
    
    Thread(int id, String priority, String culture)
    {
        this.state="created";
        System.out.println(state);
        observors = new ArrayList<>();
    }
    
     private void notifyObservors()
    {
        for(Iobservor observor: observors){
            observor.update(this.state);
        }
    }
    
    
    void start()
    {
         this.state="running";
         System.out.println(state);
        notifyObservors();
    }
    
    void abort()
    {
        this.state="aborted";
         System.out.println(state);
         notifyObservors();
         
    }
    
      void sleep()
    {
        this.state="sleep";
         System.out.println(state);
         notifyObservors();
         
    }
      void waits()
    {
        this.state="wait";
         System.out.println(state);
         notifyObservors();
    }
    
    void suspended()
    {
        this.state="suspended";
         System.out.println(state);
         notifyObservors();
    }
    
    void subscribe(Iobservor iobserver)
    {
        observors.add(iobserver);
    }
    
    void unsubscribe(Iobservor iobserver)
    {
        observors.remove(iobserver);
    }
    
   
    
}
class HelloWorld {
    public static void main(String[] args) {
        Thread th = new Thread(1, "high", "en-UK");
      Iobservor dashboard = new Dashboard();
      th.subscribe(dashboard);
        th.start();
        th.abort();
        th.sleep();
        th.waits();
        th.suspended();
    }
}