#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

typedef std::pair<std::string, std::string> KV;

class HashMap {
public:
    KV* entries = new KV[8];
    int size = 8;
    int numberOfElements = 0;

    ~HashMap() {
        delete[] entries;
    }
    int hashFunction(std::string key) {
        long long a = 0;
        for (unsigned char c : key) {
            a = (a * 239 + c) % 1000000007;
        }
        return a;
    }

    void add(std::string key, std::string value) {
        numberOfElements++;
        int index = findGoodIndex(key);
        entries[index] = std::make_pair(key, value);

        if (numberOfElements == size)
            resize(size * 2);
    }

    void resize(int newSize) {
        KV* newEntries = new KV[newSize];
        std::swap(newEntries, entries);
        std::swap(newSize, size);

        for (int i = 0; i < newSize; i++) {
            KV entry = newEntries[i];
            int index = findGoodIndex(entry.first);
            entries[index] = entry;
        }

        delete[] newEntries;
    }

    std::string get(std::string key) {
        int index = findGoodIndex(key);

        if (index == -1)
            return "";

        KV entry = entries[index];
        return entry.second;
    }

    int findGoodIndex(std::string key) {
        int hash = hashFunction(key);
        int index = hash % size;

        for (int i = 0; i < size; i++) {
            int probingIndex = (index + i) % numberOfElements;
            KV entry = entries[probingIndex];
            if ((entry.first.size() == 0) || (entry.first == key)) {
                return probingIndex;
            }
        }
        return -1;
    }

    void deleteKey(std::string key) {
        int index = findGoodIndex(key);

        if (index == -1) // если индекс не найден - выйти
            return;
        else // если найден - удалить и сдвинуть элементы вперед
            for (int i = index; i < numberOfElements - 1; ++i)
                entries[i] = entries[i + 1];

        if (--numberOfElements * 4 <= size) { // есди количество элементов <=25% текущего размера массива, уменьшить размер массива в два раза
            size = numberOfElements * 2;
            resize(size);
        }
        return; // please implement
    }

    std::vector<std::string> getAllKeys() {
        std::vector<std::string> allKeys(numberOfElements);
        for (int i{}; i < numberOfElements; ++i)
            allKeys[i] = entries[i].first;

        return allKeys; // please implement
    }

    std::vector<std::string> getAllValues() {
        std::vector<std::string> allValues(numberOfElements);
        for (int i{}; i < numberOfElements; ++i)
            allValues[i] = entries[i].first;

        return allValues; // please implement
    }

};

int main(void) {
    HashMap h;

    auto infoPrint = [&h]() {
        std::cout << "Vector size: " << h.size << ", Number Of Elements: " << h.numberOfElements << std::endl;
        std::vector<std::string> allKeys = h.getAllKeys();
        std::vector<std::string> allValues = h.getAllValues();
        for (int i{}; i < h.numberOfElements; ++i)
            std::cout << allKeys[i] << "-" << allValues[i] << std::endl;
        std::cout << std::endl;
    };

    // заполнить массив 10 значений
    for (char c = 'a'; c <= 'j'; ++c) {
        std::string s = " ";
        s[0] = c;
        h.add(s, s);
    }
    infoPrint();

    // удалить 6 элементов, вывести массив на resize
    for (char c = 'c'; c <= 'h'; ++c) {
        std::string s = " ";
        s[0] = c;
        h.deleteKey(s);
    }
    infoPrint();

    // удалить два крайних элемента
    for (char c = 'a'; c <= 'b'; ++c) {
        std::string s = " ";
        s[0] = c;
        h.deleteKey(s);
    }
    infoPrint();

    return 0;
}