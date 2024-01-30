#include<iostream>

using namespace std;

class Door {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual ~Door() = default;
};

class Buzzer {
public:
    void makeNoise() {
        cout << "Buzzer ringing\n";
    }
};

class SMSManager {
public:
    void sendNotificationMessage() {
        cout << "Sending SMS notification\n";
    }
};

class VisualizationManager {
public:
    void turnVideoOn() {
        cout << "Turning video camera on\n";
    }

    void turnVideoOff() {
        cout << "Turning video camera off\n";
    }
};

class SimpleDoor : public Door {
public:
    void open() override {
        cout << "Door opened\n";
    }

    void close() override {
        cout << "Door closed\n";
    }
};

class SmartDoor : public SimpleDoor {
    private:
        Buzzer *buzzer;
        SMSManager *smsManager;
        VisualizationManager *visualizationManager;
	//tightly coupled here ..what if more features are added apart from above 3 ? solution :Observor
	//pattern with addsubscriber removesubscriber=>reduces dependency



    public:
        SmartDoor(Buzzer *b)
            : buzzer(b) {}
            
        void setSMSManager(SMSManager *sms){
            this->smsManager=sms;
        }
        
        void setVisualizationManager(VisualizationManager *v){
            this->visualizationManager=v;
        }

        void open() override {
            SimpleDoor::open();
            buzzer->makeNoise();
        }
        
        bool sendNotification() {
            if(smsManager != NULL){
                smsManager->sendNotificationMessage();
                return true;
            }
            return false;
        }
        
        bool turnVideoOn(){
            if(visualizationManager != NULL){
                visualizationManager->turnVideoOn();
                return true;
            }
            return false;
        }

        void close() override {
            SimpleDoor::close(); 
            if(visualizationManager != NULL) 
                visualizationManager->turnVideoOff();
        }
};

class SmartDoorBuilder{
    private:
        SmartDoor* smartDoor;
        
    public:
        SmartDoorBuilder(Buzzer *b) {
            smartDoor = new SmartDoor(b);
        }

        SmartDoorBuilder* setSMSManager(SMSManager *sms) {
            smartDoor->setSMSManager(sms);
            return this;
        }
        
        SmartDoorBuilder* setVisualizationManager(VisualizationManager *v) {
            smartDoor->setVisualizationManager(v);
            return this;
        }

        SmartDoor* getInstance() {
            return smartDoor;
        }
};

int main() {
    Buzzer buzzer;
    SMSManager smsManager;
    VisualizationManager visualizationManager;

    SmartDoor *smartDoorWithBuzzer = (new SmartDoorBuilder{&buzzer})->getInstance();
    
    SmartDoor *smartDoorWithBuzzerSMS = (new SmartDoorBuilder{&buzzer})->setSMSManager(&smsManager)->getInstance();
    
    SmartDoor *smartDoorWithBuzzerSMSVideo = (new SmartDoorBuilder{&buzzer})->setVisualizationManager(&visualizationManager)->setSMSManager(&smsManager)->getInstance();

    smartDoorWithBuzzer->open();
    smartDoorWithBuzzer->close();
    
    cout<<"**********"<<endl;
    
    smartDoorWithBuzzerSMS->open();
    smartDoorWithBuzzerSMS->sendNotification();
    smartDoorWithBuzzerSMS->close();
    
    cout<<"**********"<<endl;
    
    smartDoorWithBuzzerSMSVideo->open();
    smartDoorWithBuzzerSMSVideo->sendNotification();
    smartDoorWithBuzzerSMSVideo->turnVideoOn();
    smartDoorWithBuzzerSMSVideo->close();
    
    
    
    

    return 0;
}