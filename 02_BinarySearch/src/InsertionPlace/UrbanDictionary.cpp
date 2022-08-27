#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class UrbanDictionary {

public:
    vector<string> dictionary;


    // Как и в любом словаре, у вас слова идут строго порядку.
    // Напишите функцию которая будет вставлять в словарь новые слова,
    void insertNewWord(string word) {
        // please implement
    }
};

int main(void) {
    UrbanDictionary dict;
    vector<string> words = {"Акугама", "Контент", "Лутер", "Тренд", "Фиксер", "Фэшн", "Хипстер", "Япи"};
    vector<string> non_sorted = words;
    random_shuffle(non_sorted.begin(), non_sorted.end());
    for (const auto& s : non_sorted) {
        dict.insertNewWord(s);
    }
    for (int i = 0; i < words.size(); ++i) {
        assert(words[i] == dict.dictionary[i]);
    }
    cout << "Great, now add some more tests!" << endl;
}
