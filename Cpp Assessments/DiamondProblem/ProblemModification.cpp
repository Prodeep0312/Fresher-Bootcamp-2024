#include<iostream>
using namespace std;
class Printer{

    public:
     void print(string path){
        cout<<"Printing ....."<<path;
    }
};

class Scanner{

    public:
     void scan(string path){
        cout<<"Scanning ....."<<path;
    }
};

class PrintScanner:public Printer,public Scanner {
//Had to inherit the above 2 classes so that code could compile
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
        PrintScanner printScannerObj;

        TaskManager::execuctePrintTask(&printerObj,"Test.doc");
        TaskManager::execucteScanTask(&scannerObj,"MyImage.png");
        TaskManager::execuctePrintTask(&printScannerObj,"NewDoc.doc");
        TaskManager::execucteScanTask(&printScannerObj,"YourImage.png");
    }