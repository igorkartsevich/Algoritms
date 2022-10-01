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
        for (int i = index; i < size - 1; ++i) // удалить элемент, сдвинуть элементы вперед
            values[i] = values[i + 1];

        if (--currentIndex * 4 <= size) // если количество элементов <=25% текущего размера массива - уменьшить размер массива в два раза
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

    //заполнить массив
    for (int i = 0; i < 30; ++i)
        a.add(i);
    infoPrint();

    //удалить часть элементов
    for (int i = 29; i >= 0; i -= 3)
        a.deleteElementAt(i);
    infoPrint();

    //удалить часть элементов
    for (int i = 28; i >= 0; i -= 3)
        a.deleteElementAt(i);
    infoPrint();

    //удалить часть элементов - вывести массив на resize
    a.deleteElementAt(18);
    a.deleteElementAt(21);
    // добавить +1 элемент
    a.add(777);
    infoPrint();

    return 0;
}