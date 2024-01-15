/*
ORIGINAL CODE

interface IEngine {
    void start();
}

interface ITransmission {
    void shift();
}

interface IStartupMotor {
    void startMotor();
}


interface IFuelPump {
    void pumpFuel();
}

interface ICar {
    void drive();
}

class Engine implements IEngine {
    
    private final IStartupMotor startupmotor;
    private final IFuelPump fuelpump;

  
    public Engine(IStartupMotor startupmotor, IFuelPump fuelpump) {
        this.startupmotor = startupmotor;
        this.fuelpump =fuelpump;
    }
    public void start() {
       
    }
}


class Transmission implements ITransmission {
    @Override
    public void shift() {
        
    }
}


class StartupMotor implements IStartupMotor {
    @Override
    public void startMotor() {
       
    }
}

class FuelPump implements IFuelPump {
    @Override
    public void pumpFuel() {
       
    }
}



class Car implements ICar {
    private final IEngine engine;
    private final ITransmission transmission;

  
    public Car(IEngine engine, ITransmission transmission) {
        this.engine = engine;
        this.transmission =transmission;
    }

   
    @Override
    public void drive() {
        engine.start();
        transmission.shift();
        System.out.println("Car is now driving.");
    }
}

class HelloWorld {
    public static void main(String[] args) {
        
        IStartupMotor startupMotor=new StartupMotor();
        IFuelPump fuelPump=new FuelPump();
        
        IEngine carEngine = new Engine(startupMotor,fuelPump);
        ITransmission carTransmission = new Transmission();

        
        ICar myCar = new Car(carEngine, carTransmission);

        myCar.drive();
    }
}
modify the code using DI Container so those objects arent created

*/

import org.springframework.*;

interface IEngine {
    void start();
}

interface ITransmission {
    void shift();
}

interface IStartupMotor {
    void startMotor();
}


interface IFuelPump {
    void pumpFuel();
}

interface ICar {
    void drive();
}




class Engine implements IEngine {

    private final IStartupMotor startupMotor;
    private final IFuelPump fuelPump;

    @Autowired
    public Engine(IStartupMotor startupMotor, IFuelPump fuelPump) {
        this.startupMotor = startupMotor;
        this.fuelPump = fuelPump;
    }

    public void start() {
        startupMotor.startMotor();
        fuelPump.pumpFuel();
        System.out.println("Engine started.");
    }
}

class Transmission implements ITransmission {
    @Override
    public void shift() {
        System.out.println("Transmission shifted.");
    }
}

class StartupMotor implements IStartupMotor {
    @Override
    public void startMotor() {
        System.out.println("Startup motor started.");
    }
}

class FuelPump implements IFuelPump {
    @Override
    public void pumpFuel() {
        System.out.println("Fuel pump activated.");
    }
}

class Car implements ICar {

    private final IEngine engine;
    private final ITransmission transmission;

    @Autowired
    public Car(IEngine engine, ITransmission transmission) {
        this.engine = engine;
        this.transmission = transmission;
    }

    @Override
    public void drive() {
        engine.start();
        transmission.shift();
        System.out.println("Car is now driving.");
    }
}

@Configuration
class AppConfig {

    @Bean
    public IStartupMotor startupMotor() {
        return new StartupMotor();
    }

    @Bean
    public IFuelPump fuelPump() {
        return new FuelPump();
    }

    @Bean
    public IEngine carEngine(IStartupMotor startupMotor, IFuelPump fuelPump) {
        return new Engine(startupMotor, fuelPump);
    }

    @Bean
    public ITransmission carTransmission() {
        return new Transmission();
    }

    @Bean
    public ICar myCar(IEngine carEngine, ITransmission carTransmission) {
        return new Car(carEngine, carTransmission);
    }
}

public class HelloWorld {
    public static void main(String[] args) {
        AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(AppConfig.class);

        ICar myCar = context.getBean(ICar.class);
        myCar.drive();
    }
}
