




# Crafting Elegant Objects: A Journey from Telescoping Constructors to Builder Pattern

**Introduction**

Constructing complex objects in object-oriented programming often involves navigating a maze of challenges. This article explores and traces the evolution from traditional constructors to the pitfalls of telescoping constructors and introduces the elegant solution offered by the builder pattern which eases the efforts of developers while solving certain problems .

**Traditional Constructors**

In object-oriented programming, constructors are special methods responsible for initializing an object. They play a crucial role in creating instances of classes.

    class Student {
    
    private: string name;int age;
    
    double gpa;
    
    public:
    
    //Traditional Constructor
    
    Student(string nameArg, int ageArg, double gpaArg) {
    
    name = nameArg;
    
    age = ageArg;
    
    gpa = gpaArg;
    
    }
    
    //Initializer List
    
    Student(string nameArg, int ageArg, double gpaArg): name(nameArg),
    
    age(ageArg),
    
    gpa(gpaArg) {}
    
    };

**Constructor Overloading**

Applications may occasionally need more than one constructor. It’s possible that this is due to a user requirement. However, the issue with multiple constructors is that if you have too many parameters, your code may become unclear / too complex.

Consider a scenario where a Customer wants to take a bank loan. The customer has to provide some mandatory set of details like name,address, unique identifaction like pan number,aadhar Card. On the other hand , some fields may be optional like phone number or email address . So there is a possibility of multiple types of Customers based on set of features they have .

![Customer Bank Loan Scenario](https://github.com/Prodeep0312/Fresher-Bootcamp-2024/blob/main/Article/scenario.jpg)






To implement this problem , one solution could be to overload the constructors .  
  

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
    
    : name(nameArg), address(addressArg), panNumber(panNumberArg), aadharNumber(aadharNumberArg) {}
    
    Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg, long long phoneArg)
    
    : name(nameArg), address(addressArg), panNumber(panNumberArg), aadharNumber(aadharNumberArg),
    
    phone(phoneArg) {}
    
    Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg, string emailArg)
    
    : name(nameArg), address(addressArg), panNumber(panNumberArg), aadharNumber(aadharNumberArg),
    
    email(emailArg) {}
    
    Customer(string nameArg, string addressArg, string panNumberArg, string aadharNumberArg, long long phoneArg, string emailArg)
    
    : name(nameArg), address(addressArg), panNumber(panNumberArg), aadharNumber(aadharNumberArg),
    
    phone(phoneArg), email(emailArg) {}
    
    };

However the above code suffers from following **limitations** :-

**1) Code Duplication**

In constructor overloading, if there are common initialization steps among multiple constructors, we may need to duplicate the code in each overloaded constructor. This can lead to code redundancy and increases the chance of errors if the common initialization logic changes.

**2)Maintenance Overhead**

As the number of constructors increases, maintaining and updating the class becomes more challenging. If we need to make changes to the common initialization logic, we have to update it in multiple places, which can be error-prone and time-consuming.

**Telescopic Constructors**

In the telescoping constructor pattern, each constructor with additional parameters calls the constructor with fewer parameters, providing default values for the missing parameters.

This pattern is useful when you want to allow the creation of objects with varying numbers of parameters, with some parameters having default values.

Here's an example of a telescoping constructor for the Customer class:

    class Customer {
    
    private:
    
    string name;
    
    string address;
    
    string panNumber;
    
    string aadharNumber;
    
    long long phone;
    
    string email;
    
    public:
    
    // Telescoping constructor with mandatory parameters
    
    Customer(string nameArg,  string addressArg,
    
    string panNumberArg, string aadharNumberArg)
    
    : name(nameArg), address(addressArg), panNumber(panNumberArg), aadharNumber(aadharNumberArg), phone(0), email("") {}
    
    // Telescoping constructor with optional phone number
    
    Customer(string nameArg, string addressArg,
    
    string panNumberArg,  string aadharNumberArg,
    
    long long phoneArg)
    
    : Customer(nameArg, addressArg, panNumberArg, aadharNumberArg) {
    
    phone = phoneArg;
    
    }
    
    // Telescoping constructor with optional email
    
    Customer(string nameArg,  string addressArg,
    
    string panNumberArg,  string aadharNumberArg,
    
    string emailArg)
    
    : Customer(nameArg, addressArg, panNumberArg, aadharNumberArg) {
    
    email = emailArg;
    
    }
    
    // Telescoping constructor with both optional phone number and email
    
    Customer(string nameArg,  string addressArg,
    
    string panNumberArg,  string aadharNumberArg,
    
    long long phoneArg,  string emailArg)
    
    : Customer(nameArg, addressArg, panNumberArg, aadharNumberArg, phoneArg) {
    
    email = emailArg;
    
    }
    
    };

**Advantages Over Normal Constructor**

Telescoping constructors provide flexibility by allowing the creation of objects with different parameter sets and reduces code duplication as the mandatory parameters initialization is done only once .

**Disadvantages**

Here the construction of the Customer object is tightly coupled with its representation because we are using the Customer class constructor.

**1)Code Proliferation**

Adding optional features leads to a surge of constructors, reducing readability.

**2)Inflexibility**

Changing the order of optional features requires tedious modifications to multiple constructors.

**3)Null Value Woes**

Explicit null values for unused features clutter the code.

So, with the building pattern, we’ll be able to solve this problem.

**Solution of Telescopic Constructor - Builder Pattern**

The builder pattern emerges as a superior solution to the issues associated with telescoping constructors:

What is Builder Pattern?

> The Builder pattern is an object creation design pattern whose 
> intent is to separate the construction of a complex object from 
> its representation using a Builder class. By doing so, the same
> construction process can lead to different representations.

**Implementation of Builder Pattern:**

Let's explore the implementation of the builder pattern using a Computer class:

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
    
    //display logic
    
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
    
    Customer* customer1 = (new CustomerBuilder{" Prodeep ", "Blr", "ADDRV007", "ADH546899"})->getInstance();
    
    customer1->displayInfo();
    
    Customer* customer2 = (new CustomerBuilder{"Prodeep", "Blr", "ADDRV007", "ADH546899"})->setPhone(12345)->getInstance();
    
    customer2->displayInfo();
    
    Customer* customer3 = (new CustomerBuilder{" Prodeep ", "Blr", "ADDRV007", "ADH546899"})->setEmail("vgk@v.com")->getInstance();
    
    customer3->displayInfo();
    
    Customer* customer4 = (new CustomerBuilder{" Prodeep ", "Blr", "ADDRV007", "ADH546899"})->setPhone(12345)->setEmail("vgk@v.com")->getInstance();
    
    customer4->displayInfo();
    
    return 0;
    
    }

**Advantages of the Builder Pattern:**

**1)Modular Construction**

Each feature has a dedicated method in the builder, keeping the main class clean.

**2)Fluent Interface**

Chaining builder methods in the main creates a readable and user-friendly construction process.

**3)Flexibility**

Adding or removing features becomes simple by modifying the builder without touching the main class.

**Conclusion: Embracing Stability and Elegance**

The transition from telescoping constructors to the builder pattern signifies a paradigm shift in object construction. While telescoping constructors have their uses, the builder pattern offers a superior, elegant, and maintainable solution, particularly for complex objects with multiple optional parameters. Adopting the builder pattern in class design contributes to cleaner code, improved readability, and a more satisfying object-oriented experience. Say goodbye to the shaky toothpick tower and welcome the stability and elegance of the builder pattern.
