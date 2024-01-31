#include <iostream>
using namespace std;

class A {
    public:
        ~A(){
            cout<<"A destructed"<<endl;
        }
};

template <typename T>
class DynamicArray {
private:
    T* array;
    int size;
    int capacity;

public:
    DynamicArray(int initialCapacity) : array(new T[initialCapacity]), size(0), capacity(initialCapacity) {}

    bool operator>(const DynamicArray& other) const {
        return capacity > other.capacity;
    }

    void add(int index, const T& value) {
        if (index >= size) {
            resize();
            size = index + 1;
        }
        array[index] = value;
    }

    T operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds." << endl;
            return T(); // Default value for the type T
        }
        return array[index];
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds." << endl;
            return T(); // Default value for the type T
        }
        return array[index];
    }

    void clear() {
        delete[] array;
        array = nullptr;
        size = 0;
        capacity = 0;
    }

    friend ostream& operator<<(ostream& os, const DynamicArray& arr) {
        os << "DynamicArray: [";
        for (int i = 0; i < arr.size; ++i) {
            os << arr.array[i];
            if (i < arr.size - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    ~DynamicArray() {
        clear();
    }

private:
    void resize() {
        int newCapacity = capacity * 2;
        T* newArray = new T[newCapacity];

        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
};


int main() {
    DynamicArray<int> intArray{3};
    DynamicArray<double> doubleArray{5};
    DynamicArray<char> charArray{5};

    intArray.add(0, 10);
    intArray.add(1, 20);
    intArray.add(2, 30);
    intArray.add(3, 40);

    doubleArray.add(0, 3.14);
    doubleArray.add(1, 2.718);
    doubleArray.add(2, 1.618);
    doubleArray.add(3, 4.669);
    doubleArray.add(4, 0.577);

    charArray.add(0, 'A');
    charArray.add(1, 'B');
    charArray.add(2, 'C');
    charArray.add(3, 'D');
    charArray.add(4, 'E');

    cout << "Int Array: " << intArray << endl;
    cout << "Double Array: " << doubleArray << endl;
    cout << "Char Array: " << charArray << endl;

    intArray.clear();
    doubleArray.clear();
    charArray.clear();
    
    
     A *obj1, *obj2;
    obj1 = new A();
    obj2 = new A();
    
    DynamicArray<A*> dynamicArray{3};
    dynamicArray.add(0, obj1);
    dynamicArray.add(1, obj2);
    
    delete obj1;
    delete obj2;


    return 0;
}