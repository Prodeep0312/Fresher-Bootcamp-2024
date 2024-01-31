#include <iostream>
#include <string>
#include <mutex> 
using namespace std;

class ICommunicationManager {
public:
    virtual void shareContent(std::string imageLink) = 0;
};

class ImageGallery {
    std::string images[5] = {"one.jpg", "two.jpg", "three.jpg", "four.jpg", "five.jpg"};

public:
    void share(int index, ICommunicationManager* comManager) {
        comManager->shareContent(images[index]);
    }
};

template <typename T>
class CommunicationManagerFactory {
private:
    static std::mutex mutex_; 

public:
    static T* getInstance() {
        std::lock_guard<std::mutex> lock(mutex_); 
        static T instance;
        return &instance;
    }
};


template <typename T>
std::mutex CommunicationManagerFactory<T>::mutex_;

class BluetoothManager : public ICommunicationManager {
    friend class CommunicationManagerFactory<BluetoothManager>;

public:
   void searchDevices() {}
    void pairDevice() {}
    void sendContent() {}
    void turnOn() {}
    void turnOff() {}

    void shareContent(std::string imageLink) override {
        cout << "BluetoothManager sharing the image: " << imageLink << endl;
    }


private:
    BluetoothManager() {}
};

class WhatsUpManager : public ICommunicationManager {
    friend class CommunicationManagerFactory<WhatsUpManager>;

public:
    void turnOn() {}
    void turnOff() {}
    void shareContent() {}
    void joinGroup() {}
    void addMember() {}
    void createGroup() {}

    void shareContent(std::string imageLink) override {
        cout << "WhatsUpManager sharing the image: " << imageLink << endl;
    }

private:
    WhatsUpManager() {}
};

class MailManager : public ICommunicationManager {
    friend class CommunicationManagerFactory<MailManager>;

public:
    void pullNewMails() {}
    void senMails() {}
    void composeEmail() {}
    void addAttachment() {}

    void shareContent(std::string imageLink) override {
        cout << "MailManager sharing the image: " << imageLink << endl;
    }

private:
    MailManager() {}
};

int main() {
    ICommunicationManager* _mailManager = CommunicationManagerFactory<MailManager>::getInstance();
    ICommunicationManager* _bluetoothManager = CommunicationManagerFactory<BluetoothManager>::getInstance();
    ICommunicationManager* _whatsUpManager = CommunicationManagerFactory<WhatsUpManager>::getInstance();

    ImageGallery* imageMgmt = new ImageGallery();
    imageMgmt->share(0, _mailManager);
    imageMgmt->share(0, _bluetoothManager);
    imageMgmt->share(0, _whatsUpManager);

    delete imageMgmt;

    return 0;
}
