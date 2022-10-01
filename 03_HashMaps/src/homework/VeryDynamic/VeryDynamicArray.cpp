#include <iostream>
#include <memory>

class DynamicArray {
public:
    int* values;
    int size;
    int currentIndex;

    DynamicArray() {
        values = (int*)std::malloc(sizeof(int) * 8);
        size = 8;
        currentIndex = 0;
    }

    ~DynamicArray() {
        std::free(values);
    }

    void add(int value) {
        values[currentIndex] = value;
        if (++currentIndex == size)
            resize(size * 2);
        
        return;
    }

    void resize(int newSize) {
        values = (int*)std::realloc(values, newSize * sizeof(int));
        size = newSize;

        return;
    }

    void deleteElementAt(int index) {
        for (int i = index; i < size - 1; ++i) // delete item and remove other items
            values[i] = values[i + 1];

        if (--currentIndex * 4 <= size) // if the number of the items <=25% curremt size of array, resize it less
            resize(currentIndex * 2);

        return; // please implement
    }
};

int main(void) {
    DynamicArray a;

    auto infoPrint = [&a]() {
        for (int i = 0; i < a.currentIndex; ++i)
            std::cout << a.values[i] << " ";
        std::cout << std::endl << a.currentIndex << " " << a.size << std::endl;
    };

    //add items
    for (int i = 0; i < 30; ++i)
        a.add(i);
    infoPrint();

    //delete some items
    for (int i = 29; i >= 0; i -= 3)
        a.deleteElementAt(i);
    infoPrint();

    //delete some items
    for (int i = 28; i >= 0; i -= 3)
        a.deleteElementAt(i);
    infoPrint();

    //delete some items and resize array
    a.deleteElementAt(18);
    a.deleteElementAt(21);
    // add item
    a.add(777);
    infoPrint();

    return 0;
}