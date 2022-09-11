#include <iostream>
#include <memory>
using namespace std;

class DynamicArray {
public:
    DynamicArray() {
        values = (int*)malloc(sizeof(int) * 8);
        size = 8;
        currentIndex = 0;
    }
    ~DynamicArray() {
        free(values);
    }
    int *values;
    int size;
    int currentIndex;

    void add(int value) {
        values[currentIndex] = value;
        currentIndex++;
        if (currentIndex == size) {
            resize(size * 2);
        }
    }

    void resize(int newSize) {
        values = (int*)realloc(values, newSize * sizeof(int));
        size = newSize;
    }

    void deleteElementAt(int index) {
        // please implement
    }
};

int main(void) {
    DynamicArray a;
    for (int i = 0; i < 30; ++i) {
        a.add(i);
    }
    for (int i = 0; i < 30; ++i) {
        cout << a.values[i] << " ";
    }
    cout << endl;
    cout << a.currentIndex << " " << a.size << endl;
    for (int i = 29; i >= 0; i -= 3) {
        a.deleteElementAt(i);
    }
    for (int i = 0; i < 30; ++i) {
        cout << a.values[i] << " ";
    }
    cout << endl;
    cout << a.currentIndex << " " << a.size << endl;
}