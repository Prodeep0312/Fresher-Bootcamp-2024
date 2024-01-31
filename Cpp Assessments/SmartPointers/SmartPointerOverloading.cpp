#include <iostream>
using namespace std;

template <typename T>
class SmartPointer {
    T* rawPtr;

public:
    SmartPointer(T* ptr) : rawPtr(ptr) {}
    ~SmartPointer() {
        delete rawPtr;
    }
    T* operator->()const{
        return rawPtr;
    }
};

class A {
public:
    ~A() {
        cout << "A destructed" << endl;
    }
    
    void methodA()
    {
        cout << "A.method" << endl;
    }
};

class B {
public:
    ~B() {
        cout << "B destructed" << endl;
    }
    
    void methodB()
    {
        cout << "B.method" << endl;
    }
};

void init() {
    SmartPointer<A> smartPtrA{ new A() };
    smartPtrA->methodA();
    SmartPointer<B> smartPtrB{ new B() };
    smartPtrB->methodB();
}

int main() {
    init();
    return 0;
}
