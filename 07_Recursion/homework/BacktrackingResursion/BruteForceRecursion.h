#pragma once
#include <string>
#include <vector>


class BruteForceRecursion {
public:
    BruteForceRecursion() {};
    virtual ~BruteForceRecursion() {};
    // Task #1
    static std::vector<std::vector<int>> orderOfReleaseFeatures(const std::vector<int>& numbersOfFeatures);

    // Task #2
    static bool checkPowersOfThree(int number);

    // Task #3
    static std::vector<std::string> possibleMessages(const std::string& digits);

    // This can be a hashtable, any structure to map 'number' to 'letters' it can manifest as
private:
    std::vector<std::string> digitToPossibleLetters{
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
};
