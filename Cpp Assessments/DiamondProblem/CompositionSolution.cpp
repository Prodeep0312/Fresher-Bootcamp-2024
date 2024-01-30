#include<iostream>
#include<string>
using namespace std;


class IPrinter {
public:
    virtual void print(string path) = 0;
    virtual ~IPrinter() {}
};


class IScanner {
public:
    virtual void scan(string path) = 0;
    virtual ~IScanner() {}
};

class Device {
private:
    string id;

protected:
    Device(){
            cout<<"Device Constructed"<<endl;
        }
        
    Device(string idArg) : id(idArg) {}

public:
    string getDeviceId() {
        return this->id;
    }

    virtual ~Device() {
        cout << "Device Destructed" << endl;
    }
};

class Printer : public IPrinter, public Device {
public:
    Printer(string idArg) : Device::Device(idArg) {
        cout<<"Printer Constructed"<<endl;
    }

    void print(string path) override {
        cout << "Printing......" << path;
    }
};

class Scanner : public IScanner, public Device {
public:
    Scanner(string idArg) : Device::Device(idArg) {
        cout<<"Scanner Constructed"<<endl;
    }

    void scan(string path) override {
        cout << "Scanning ....." << path;
    }
};

class IPrintScanner : public IPrinter, public IScanner {
};

class PrintScanner : public IPrintScanner, public Device {
private:
    //composition
    Printer printer;
    Scanner scanner;

public:
    PrintScanner(string idArg) : Device::Device(idArg), printer(idArg), scanner(idArg) {
        cout << "PrintScanner  Constructed" << endl;
    }

    ~PrintScanner() {
        cout << "PrintScanner destructed" << endl;
    }

    void print(string path) override {
        printer.print(path);
    }

    void scan(string path) override {
        scanner.scan(path);
    }
};

class TaskManager {
public:
    static void executePrintTask(IPrinter* printer, string documentPath) {
        printer->print(documentPath);
    }

    static void executeScanTask(IScanner* scanner, string documentPath) {
        scanner->scan(documentPath);
    }
};

int main() {
    Printer printerObj("PR1");
    Scanner scannerObj("SC1");
    PrintScanner printScannerObj("PS1");

    TaskManager::executePrintTask(&printerObj, "Test.doc");
    TaskManager::executeScanTask(&scannerObj, "MyImage.png");
    TaskManager::executePrintTask(&printScannerObj, "NewDoc.doc");
    TaskManager::executeScanTask(&printScannerObj, "YourImage.png");

    return 0;
}
