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

class Thread {
    int id;
    String state;
    String priority;
    String culture;
    
    ArrayList<Iobservor> x;
    
    
    
    
    Thread(int id)
    {   this.id=id;
    this.priority="testing";
    this.culture="testing";
        this.state="created";
        System.out.println(state);
        x = new ArrayList<>();
    }
    
     private void notifyObservors()
    {
        for(Iobservor observor: x){
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
        x.add(iobserver);
    }
    
    void unsubscribe(Iobservor iobserver)
    {
        x.remove(iobserver);
    }
    
   
    
}

interface Iobservor{
    void update(String state);
}

class Dashboard implements Iobservor{
    String content;
    public void update(String content){
        this.content = content;
    }
    
    public String displayStatus(){
        return this.content;
    }
}

class HelloWorld {
    public static void main(String[] args) {
        Thread th = new Thread(1);
        Iobservor dashboard = new Dashboard();
        th.subscribe(dashboard);
        
        
        th.start();
        th.abort();
        th.sleep();
        th.waits();
        th.suspended();
        
        
        th.unsubscribe(dashboard);
    }
}
