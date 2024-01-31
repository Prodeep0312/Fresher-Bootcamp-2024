#include <iostream>
using namespace std;

class DynamicIntegerArray {
private:
    int* array;
    int size;
    int capacity;

public:
    DynamicIntegerArray(int initialCapacity) : array(new int[initialCapacity]), size(0), capacity(initialCapacity) {}

   
    void add(int index, int value) {
        if (index < 0 || index >= capacity) {
            cout << "Index out of bounds." << endl;
            return;
        }

        if (index >= size) {
        
            resize();
            size = index + 1;
        }

        array[index] = value;
    }

    
    int get(int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds." << endl;
            return -1;
        }

        return array[index];
    }

   
    void clear() {
        delete[] array;
        array = nullptr;
        size = 0;
        capacity = 0;
    }

    
    ~DynamicIntegerArray() {
        clear();
    }

private:
    
    void resize() {
        int newCapacity = capacity * 2;
        int* newArray = new int[newCapacity];

        
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }

        
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
};

int main() {
    DynamicIntegerArray numbers{3};
    numbers.add(0, 10);
    numbers.add(1, 20);
    numbers.add(2, 30);
    numbers.add(3, 40);

    std::cout << "Value at index 2: " << numbers.get(2) << std::endl;

    numbers.clear();

    return 0;
}