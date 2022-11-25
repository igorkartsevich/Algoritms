#include "BruteForceRecursion.h"
#include <iostream>
#include <set>
#include <cassert>

void orderOfReleaseFeaturesTest() {
    std::cout << "Find all possible order of release features" << std::endl;
    std::vector<std::vector<int>> l1{ {1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                             {2, 3, 1}, {3, 1, 2}, {3, 2, 1} };
    std::vector<std::vector<int>> l2{ {13, 21}, {21, 13} };
    std::vector<std::vector<int>> l3{ {98} };

    std::vector<std::vector<int>> keys{ {1, 2, 3}, {13, 21}, {98} };
    std::vector<std::vector<std::vector<int>>> vals = { l1, l2, l3 };

    for (size_t i = 0; i < keys.size(); ++i) {
        auto res = BruteForceRecursion::orderOfReleaseFeatures(keys[i]);
        std::set<std::vector<int>> actual(res.begin(), res.end());
        std::set<std::vector<int>>expected(vals[i].begin(), vals[i].end());
        assert(expected == actual);
    }
}


void checkPowersOfThreeTest() {
    std::cout << "Help Ivan check powers of 3" << std::endl;
    std::vector<int> numbers{ 12, 11, 91, 112 };
    std::vector<bool> answers{ true, false, true, true };
    for (size_t i = 0; i < numbers.size(); ++i) {
        auto actual = BruteForceRecursion::checkPowersOfThree(numbers[i]);
        assert(answers[i] == actual);
    }
}


void possibleMessagesTest() {
    std::cout << "Find possible messages" << std::endl;
    std::vector<std::string> l1{ "a", "b", "c" };
    std::vector<std::string> l2{ "gd", "ge", "gf", "hd", "he", "hf", "id", "ie", "if" };
    std::vector<std::string> l3{ "adw", "adx", "ady", "adz",
            "aew", "aex", "aey", "aez",
            "afw", "afx", "afy", "afz",
            "bdw", "bdx", "bdy", "bdz",
            "bew", "bex", "bey", "bez",
            "bfw", "bfx", "bfy", "bfz",
            "cdw", "cdx", "cdy", "cdz",
            "cew", "cex", "cey", "cez",
            "cfw", "cfx", "cfy", "cfz" };

    std::vector<std::string> keys{ "", "2", "43", "239" };
    std::vector<std::vector<std::string>> vals = { {}, l1, l2, l3 };

    for (size_t i = 0; i < keys.size(); ++i) {
        auto res = BruteForceRecursion::possibleMessages(keys[i]);
        std::set<std::string> actual(res.begin(), res.end());
        std::set<std::string> expected(vals[i].begin(), vals[i].end());
        assert(expected == actual);
    }
}

int main() {
    orderOfReleaseFeaturesTest();
    checkPowersOfThreeTest();
    possibleMessagesTest();
    std::cout << "All tests for DLList passed successfully! Congrats";
    return 0;
}

