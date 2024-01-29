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
    
    Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg )
        : name(nameArg), address(addressArg), panNumber(panNumberArg),
          aadharNumber(aadharNumberArg) {}


    void setPhone(long long phoneArg){
            phone=phoneArg;
        }
        
    void setEmail(string emailArg){
            email=emailArg;
        }
    
    void displayInfo()  {
          cout << "Name: " << name <<endl;
        cout << "Address: " << address <<endl;
        cout << "PAN Number: " << panNumber <<endl;
        cout << "Aadhar Number: " << aadharNumber <<endl;
        if (phone!=0) {
            cout << "Phone: " << phone <<endl;
        }
        if (!email.empty()) {
            cout << "Email: " << email <<endl;
        }
    }
};

class CustomerBuilder {
private:
    Customer* customer;
public:
    
   CustomerBuilder(string name, string address, string pan, string adhaar) {
            customer = new Customer(name, address, pan, adhaar);
        }

    
       CustomerBuilder* setPhone(long long phoneArg) {
         customer->setPhone(phoneArg);
            return this;
    }

    CustomerBuilder* setEmail(string emailArg) {
        customer->setEmail(emailArg);
        return this;
    }

    
    Customer* getInstance() {
        return customer;
    }
};

int main() {
    
    Customer* customer1 = (new CustomerBuilder{"venu", "Blr", "ADDRV007", "ADH546899"})->getInstance();
    customer1->displayInfo();
    Customer* customer2 = (new CustomerBuilder{"venu", "Blr", "ADDRV007", "ADH546899"})->setPhone(12345)->getInstance();
      customer2->displayInfo();
    Customer* customer3 = (new CustomerBuilder{"venu", "Blr", "ADDRV007", "ADH546899"})->setEmail("vgk@v.com")->getInstance();
    customer3->displayInfo();
    Customer* customer4 = (new CustomerBuilder{"venu", "Blr", "ADDRV007", "ADH546899"})->setPhone(12345)->setEmail("vgk@v.com")->getInstance();
    customer4->displayInfo();

    


    return 0;
}
