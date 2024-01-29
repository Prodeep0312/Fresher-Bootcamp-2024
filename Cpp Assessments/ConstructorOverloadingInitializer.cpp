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
   //Initializer List
    Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg)
        : name(nameArg), address(addressArg), panNumber(panNumberArg), aadharNumber(aadharNumberArg),phone(0){}
          

  
    Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg, long long phoneArg)
        : name(nameArg), address(addressArg), panNumber(panNumberArg), aadharNumber(aadharNumberArg),
          phone(phoneArg) {}

   
    Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg, string emailArg)
        : name(nameArg), address(addressArg), panNumber(panNumberArg), aadharNumber(aadharNumberArg),
           email(emailArg),phone(0) {}

    
    Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg, long long phoneArg, string emailArg)
        : name(nameArg), address(addressArg), panNumber(panNumberArg), aadharNumber(aadharNumberArg),
          phone(phoneArg), email(emailArg) {}

    // Member function to display customer information
    void displayInfo() const {
        cout << "Name: " << name << "\n";
        cout << "Address: " << address << "\n";
        cout << "PAN Number: " << panNumber << "\n";
        cout << "Aadhar Number: " << aadharNumber << "\n";
        if (phone != 0) {
            cout << "Phone: " << phone << "\n";
        }
        if (!email.empty()) {
            cout << "Email: " << email << "\n";
        }
    }
};

int main() {
    
    Customer customer1("Prodeep", "123 Main St", "ABCDE1234F", "123456789012");
    Customer customer2("Pradip", "456 Oak St", "FGHIJ5678K", "345678901234", 9876543210);
    Customer customer3("Keerthi", "789 Pine St", "LMNOP9012Q", "567890123456", "k@gmail.com");
    Customer customer4("Vinayak", "101 Cedar St", "QRSTU5678V", "789012345678", 8765432109, "v@yahoo.com");

   
    cout << "Customer 1 Information:\n";
    customer1.displayInfo();
    cout << "\n";

    cout << "Customer 2 Information:\n";
    customer2.displayInfo();
    cout << "\n";

    cout << "Customer 3 Information:\n";
    customer3.displayInfo();
    cout << "\n";

    cout << "Customer 4 Information:\n";
    customer4.displayInfo();

    return 0;
}