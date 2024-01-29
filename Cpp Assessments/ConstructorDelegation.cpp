#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
    string name;
    string address;
    string panNumber;
    string aadharNumber;
    long long phone;
    string email;

public:
   

     Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg)
        : name(nameArg), address(addressArg), panNumber(panNumberArg), aadharNumber(aadharNumberArg){}
        
     Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg, long long phoneArg)
        : Customer(nameArg, addressArg, panNumberArg, aadharNumberArg) {
        phone = phoneArg;
    } 

     Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg, string emailArg)
        : Customer(nameArg, addressArg, panNumberArg, aadharNumberArg) {
        email = emailArg;
    }
  
    Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg, long long phoneArg, string emailArg)
        : Customer(nameArg, addressArg, panNumberArg, aadharNumberArg, phoneArg) {
        email = emailArg;
    }
    
    void displayInfo()  {
        cout << "Name: " << name <<endl;
        cout << "Address: " << address <<endl;
        cout << "PAN Number: " << panNumber <<endl;
        cout << "Aadhar Number: " << aadharNumber <<endl;
        if (phone <=9999999999) {
            cout << "Phone: " << phone <<endl;
        }
        if (!email.empty()) {
            cout << "Email: " << email <<endl;
        }
    }
};

int main() {
  
    Customer customer1("Prodeep", "123 Main St", "ABCDE1234F", "123456789012");
    Customer customer2("Pradip", "456 Oak St", "FGHIJ5678K", "345678901234", 9876543210);
    Customer customer3("Keerthi", "789 Pine St", "LMNOP9012Q", "567890123456", "k@gmail.com");
    Customer customer4("Vinayak", "101 Cedar St", "QRSTU5678V", "789012345678", 8765432109, "v@yahoo.com");

    customer1.displayInfo();
    customer2.displayInfo();
    customer3.displayInfo();
    customer4.displayInfo();
    return 0;
}