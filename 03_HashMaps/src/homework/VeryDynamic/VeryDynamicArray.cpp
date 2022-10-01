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
        for (int i = index; i < size - 1; ++i) // ������� �������, �������� �������� ������
            values[i] = values[i + 1];

        if (--currentIndex * 4 <= size) // ���� ���������� ��������� <=25% �������� ������� ������� - ��������� ������ ������� � ��� ����
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

    //��������� ������
    for (int i = 0; i < 30; ++i)
        a.add(i);
    infoPrint();

    //������� ����� ���������
    for (int i = 29; i >= 0; i -= 3)
        a.deleteElementAt(i);
    infoPrint();

    //������� ����� ���������
    for (int i = 28; i >= 0; i -= 3)
        a.deleteElementAt(i);
    infoPrint();

    //������� ����� ��������� - ������� ������ �� resize
    a.deleteElementAt(18);
    a.deleteElementAt(21);
    // �������� +1 �������
    a.add(777);
    infoPrint();

    return 0;
}