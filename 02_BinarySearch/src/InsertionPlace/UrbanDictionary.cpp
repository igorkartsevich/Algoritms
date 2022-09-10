#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

class UrbanDictionary {

public:
    std::vector<std::string> dictionary;

    void insertNewWord(std::string word) {
        if (dictionary.size() == 0)
            dictionary.push_back(word);
        else {
            int left = 0,
                right = dictionary.size();
            do {
                int middle = left + (right - left) / 2;
                if (dictionary[middle] <= word)
                    left = middle + 1;
                else
                    right = middle;
            } while (left < right);

            dictionary.insert(begin(dictionary) + right, word);
        }
        return; // please implement
    }
};

int main(void) {
    UrbanDictionary dict;

    std::vector<std::string> words = { "Акугама", "Контент", "Лутер", "Тренд", "Фиксер", "Фэшн", "Хипстер", "Япи" };
    std::vector<std::string> non_sorted = words;
    std::random_shuffle(non_sorted.begin(), non_sorted.end());
    for (const auto& s : non_sorted)
        dict.insertNewWord(s);
    assert(words == dict.dictionary);

    dict.dictionary.clear();

    std::vector<std::string> words_1 = {
        "аарона",	"ааронов",	"аб",	"аба",
        "абажур",	"абажурный",	"абажуром",	"абажуры",
        "абаз",	"абазин",	"абазинец",	"абазинка",
        "абазинский",	"абаи",	"абак",	"абака",
        "абакан",	"абаканский",	"абакум",	"абакума"
    };
    std::vector<std::string> non_sorted_1 = words_1;
    std::random_shuffle(non_sorted_1.begin(), non_sorted_1.end());
    for (const auto& s : non_sorted_1)
        dict.insertNewWord(s);
    assert(words_1 == dict.dictionary);

    return 0;
}
