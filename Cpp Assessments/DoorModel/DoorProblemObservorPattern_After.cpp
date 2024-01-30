#include<iostream>
#include<algorithm>
using namespace std;

class IObserver {
public:
    virtual void update() = 0;
    virtual ~IObserver() {}
};

class Buzzer : public IObserver {
public:
    void update() override {
        cout << "Buzzer noise added" << endl;
    }
};

class SMSManager : public IObserver {
public:
    void update() override {
        cout << "SMS notification added" << endl;
    }
};

class VisualizationManager : public IObserver {
public:
    void update() override {
        cout << "Video on/off" << endl;
    }
};

class PublisherDoor {
private:
   IObserver** observers;
    int capacity;
    int size;

public:
    PublisherDoor(int capacity) : capacity(capacity), size(0) {
        observers = new IObserver*[capacity];
    }

    ~PublisherDoor() {
        delete[] observers;
    }

    void addObserver(IObserver* observer) {
        if (size < capacity) {
            observers[size++] = observer;
        }
        
    }

    void removeObserver(IObserver* observer) {
        for (int i = 0; i < size; ++i) {
            if (observers[i] == observer) {
                
                for (int j = i; j < size - 1; ++j) {
                    observers[j] = observers[j + 1];
                }
                --size;
                break;
            }
        }
    }

    void notifyObservers() {
        for (int i = 0; i < size; ++i) {
            observers[i]->update();
        }
    }

    void open() {
        cout << "Smart door is opening." << endl;
        notifyObservers();
    }

    void close() {
        cout << "Smart door is closing." << endl;
    }
};

int main() {
    Buzzer buzzer;
    SMSManager smsManager;
    VisualizationManager visualizationManager;

    PublisherDoor pDoor(3);

    pDoor.addObserver(&buzzer);
    pDoor.addObserver(&smsManager);
    pDoor.addObserver(&visualizationManager);

    pDoor.open();
    pDoor.close();

    pDoor.removeObserver(&buzzer);

    pDoor.open();
    pDoor.close();

    return 0;
}