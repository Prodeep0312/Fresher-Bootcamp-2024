#include<iostream>
using namespace std;
class Device{
  private: string id;
  protected:
  Device(){
       cout<<"Device class Constructor"<<endl;
  }
  Device(string idArg):id(idArg){}
   public:
   string getDeviceId()
   {
       return this->id;
   }
   ~Device(){
       cout<<"Device class Destructor"<<endl;
   }
    
    
};
class Printer:virtual public Device{
   

    public:
    Printer(){
         cout<<"Printer class Constructor"<<endl;
    }
    Printer(string idArg):Device::Device(idArg){}
        
    ~Printer()
        {
            cout<<"Destructor in Printer Class"<<endl;
        }
     void print(string path){
        cout<<"Printing ....."<<path;
        
    }
};
//only 1 copy of device to be created for p and s
class Scanner:virtual public Device{

    public:
    Scanner(){
        cout<<"Scanner class Constructor"<<endl;
    }
    Scanner(string idArg):Device::Device(idArg){}
        
        ~Scanner()
        {
            cout<<"Destructor in Scanner Class"<<endl;
        }
     void scan(string path){
        cout<<"Scanning ....."<<path;
    }
};

class PrintScanner :public Printer,public Scanner {
    
    public:
    
    PrintScanner(string idArg):Device::Device{idArg}{
      
    }
    ~PrintScanner(){
        cout<<"Destructor of PrintScanner"<<endl;
    }

};
 class TaskManager{
    public:
     static void execuctePrintTask(Printer *printer,string documentPath){
        printer->print(documentPath);
    }
     static void execucteScanTask(Scanner *scanner,string documentPath){
            scanner->scan(documentPath);
    }
};


    int main(){
        Printer printerObj;
        Scanner scannerObj;
        PrintScanner printScannerObj("PS1");

       TaskManager::execuctePrintTask(&printerObj,"Test.doc");
        TaskManager::execucteScanTask(&scannerObj,"MyImage.png");
        TaskManager::execuctePrintTask(&printScannerObj,"NewDoc.doc");
        TaskManager::execucteScanTask(&printScannerObj,"YourImage.png");
    }