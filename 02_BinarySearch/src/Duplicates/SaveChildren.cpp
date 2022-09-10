#include <vector>
#include <iostream>
#include <cassert>

void permutateWords(std::vector<std::vector<char>>& words) {
    auto permulateChars = [](std::vector<char>& word) {
        char tmp = word[0];
        auto size = word.size();
        for (auto i = 1; i < size; ++i)
            word[i - 1] = word[i];

        word[size - 1] = tmp;
        return;
    };

    auto size = words.size();
    for (auto i = 0; i < size; ++i)
        for (auto j = 0; j < size; ++j)
            if (i != j && words[i] == words[j])
                permulateChars(words[j]);

    return;
}

int main(void) {
    std::vector<std::vector<char>> words = {
        {'a', 'b', 'c', 'd', 'e' }, //non_unique
        {'p', 'k', 'k', 'w', 'g' },
        {'a', 'b', 'c', 'd', 'e' }, //non_unique
        {'a', 'b', 'c', 'd', 'e' }, //non_unique
        {'a', 'b', 'c', 'd', 'e' }, //non_unique
        {'a', 'b', 'c', 'd', 'e' }  //non_unique
    };

    permutateWords(words);

    std::vector<std::vector<char>> res = {
        {'a', 'b', 'c', 'd', 'e' }, //non_unique
        {'p', 'k', 'k', 'w', 'g' },
        {'b', 'c', 'd', 'e', 'a' }, //non_unique
        {'c', 'd', 'e', 'a', 'b' }, //non_unique
        {'d', 'e', 'a', 'b', 'c' }, //non_unique
        {'e', 'a', 'b', 'c', 'd' }  //non_unique
    };

    assert(words == res);

    return 0;
}