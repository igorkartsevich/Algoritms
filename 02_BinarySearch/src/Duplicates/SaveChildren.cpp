#include <vector>
#include <iostream>
#include <cassert>

void permutateWords(std::vector<std::vector<char>>& words) {
    //функция - перестановка букв в слове
    auto permulate = [](std::string& word) {
        char tmp = word[0];
        auto size = word.length();

        for (auto i = 1; i < size; ++i)
            word[i - 1] = word[i];

        word[size - 1] = tmp;
    };

    // сборка букв в слова
    std::vector<std::string> words_TMP;
    for (auto word : words) {
        std::string word_TMP = "";

        for (auto letter : word)
            word_TMP += letter;

        words_TMP.push_back(word_TMP);
    }

    // проверки и коррекция
    auto size = words_TMP.size();
    bool is_equal;
    do {
        is_equal = false;

        for (auto i = 0; i < size; ++i) {

            for (auto j = 0; j < size; ++j) {
                if (i != j && words_TMP[i] == words_TMP[j]) {
                    permulate(words_TMP[i]);
                    is_equal = true;
                    break;
                }
            }
        }
    } while (is_equal);

    // разборка слов назад в буквы
    words.clear();
    for (auto word : words_TMP) {
        std::vector<char> letters_to_word;

        for (auto letter : word)
            letters_to_word.push_back(letter);

        words.push_back(letters_to_word);
    }
    return;
}

int main(void) {
    std::vector<std::vector<char>> words = {
        {'a', 'b', 'c', 'd', 'e' }, //non_unique
        {'o', 'm', 'u', 'a', 'r', 'w' },
        {'p', 'k', 'k', 'w', 'g' },
        {'a', 'b', 'c', 'd', 'e' }, //non_unique
        {'a', 'b', 'c', 'd', 'e' }, //non_unique
        {'a', 'b', 'c', 'd', 'e' }, //non_unique
        {'a', 'b', 'c', 'd', 'e' }  //non_unique
    };

    permutateWords(words);

    std::vector<std::vector<char>> res = {
        {'e', 'a', 'b', 'c', 'd' }, //non_unique
        {'o', 'm', 'u', 'a', 'r', 'w' },
        {'p', 'k', 'k', 'w', 'g' },
        {'d', 'e', 'a', 'b', 'c' }, //non_unique
        {'c', 'd', 'e', 'a', 'b' }, //non_unique
        {'b', 'c', 'd', 'e', 'a' }, //non_unique
        {'a', 'b', 'c', 'd', 'e' }  //non_unique
    };

    assert(words == res);

    return 0;
}