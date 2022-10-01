#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<string, string> KV;

class HashMap {
public:
    KV *entries = new KV[8];
    int size = 8;
    int numberOfElements = 0;

    ~HashMap() {
        delete[] entries;
    }

    int hashFunction(string key) {
        long long a = 0;
        for (unsigned char c : key) {
            a = (a * 239 + c) % 1000000007;
        }
        return a;
    }

    void add(string key, string value) {
        int index = findGoodIndex(key);
        entries[index] = make_pair(key, value);
        numberOfElements++;
        if (numberOfElements == size) {
            resize(size * 2);
        }
    }

    void resize(int newSize) {
        KV *newEntries = new KV[newSize];
        swap(newEntries, entries);
        swap(newSize, size);
        for (int i = 0; i < newSize; i++) {
            KV entry = newEntries[i];
            int index = findGoodIndex(entry.first);
            entries[index] = entry;
        }
        delete[] newEntries;
    }

    string get(string key) {
        int index = findGoodIndex(key);
        if (index == -1) {
            return "";
        }
        KV entry = entries[index];
        return entry.second;
    }

    int findGoodIndex(string key) {
        int hash = hashFunction(key);
        int index = hash % size;

        for (int i = 0; i < size; i++) {
            int probingIndex = (index + i) % size;
            KV entry = entries[probingIndex];
            if ((entry.first.size() == 0) || (entry.first == key)) {
                return probingIndex;
            }
        }
        return -1;
    }

};

int main(void) {
    HashMap h;
    h.add("Hello", "world");
    cout << h.get("Hello") << endl;
    cout << h.get("Hellop") << endl;
    h.add("test", "best");
    cout << h.get("test") << endl;
    for (char c = 'a'; c <= 'z'; ++c) {
        string s = " ";
        s[0] = c;
        h.add(s, s);
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        string s = " ";
        s[0] = c;
        cout << h.get(s) << endl;
    }
    cout << h.get("Hello") << endl;
}
