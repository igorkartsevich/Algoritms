#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>

bool doIKnowThisLanguage(const std::vector<std::string>& languagesList, const std::string& language) {
    int left = 0,
        right = languagesList.size() - 1;
    do {
        int middle = (left + right) / 2;
        if (language < languagesList[middle])
            right = --middle;
        else if (language > languagesList[middle])
            left = ++middle;
        else return true;

    } while (left <= right);

    return false; // please implement
}

//*****************************

struct DatingUser {
    int IQ;
    std::string name;
};

std::vector<std::string> findUsers(std::vector<DatingUser>& usersSortedByIQ, int lowerIQBound, int professorIQ) {

    auto leftIndex = [&usersSortedByIQ](int value) {
        int left = 0,
            right = (int)usersSortedByIQ.size();
        do {
            int middle = left + (right - left) / 2;
            if (usersSortedByIQ[middle].IQ >= value)
                right = middle;
            else
                left = middle + 1;

        } while (left < right);
        return left;
    };

    auto rightIndex = [&usersSortedByIQ](int value) {
        int left = 0,
            right = (int)usersSortedByIQ.size();
        do {
            int middle = left + (right - left) / 2;
            if (usersSortedByIQ[middle].IQ <= value)
                left = middle + 1;
            else
                right = middle;

        } while (left < right);
        return --right;
    };

    std::vector<std::string> usersNames;
    auto leftIndex = leftIndex(lowerIQBound);
    auto rightIndex = rightIndex(professorIQ);

    for (auto i = leftIndex; i <= rightIndex; ++i)
        usersNames.push_back(usersSortedByIQ[i].name);

    return usersNames; // please implement
}

//*****************************

int findPhoneNumber(const std::vector<long long>& sortedPhoneNumbers, long long search) {
    int left = 0,
        middle,
        right = sortedPhoneNumbers.size() - 1;

    bool is_sorted_ASC = sortedPhoneNumbers[0] < sortedPhoneNumbers[sortedPhoneNumbers.size() - 1];

    do {
        middle = (left + right) / 2;
        if (search < sortedPhoneNumbers[middle])
            (is_sorted_ASC) ? right = --middle : left = ++middle;
        else if (search > sortedPhoneNumbers[middle])
            (is_sorted_ASC) ? left = ++middle : right = --middle;
        else return middle;

    } while (left <= right);

    return -1; //please implement
}

//*****************************

int main(void) {
    std::vector<std::string> languages = { "ADA", "C", "C++", "D++", "Go", "Java", "Python" };
    assert(doIKnowThisLanguage(languages, "C++"));
    assert(!doIKnowThisLanguage(languages, "RCaml"));

    //*****************************

    std::vector<DatingUser> usersSortedByIQ_normal = { { 100, "100" }, {110, "110"}, {120, "120"}, {130, "130"}, {140, "140"}, {150, "150"} };

    std::vector<std::string> res0 = { "100", "110", "120", "130", "140", "150" };
    assert(findUsers(usersSortedByIQ_normal, 100, 150) == res0);

    std::vector<std::string> res1 = { "110", "120", "130" };
    assert(findUsers(usersSortedByIQ_normal, 110, 130) == res1);

    std::vector<std::string> res2 = { "100", "110", "120" };
    assert(findUsers(usersSortedByIQ_normal, 90, 120) == res2);

    std::vector<std::string> res3 = { "120", "130", "140", "150" };
    assert(findUsers(usersSortedByIQ_normal, 120, 180) == res3);

    std::vector<std::string> res4 = { "120" };
    assert(findUsers(usersSortedByIQ_normal, 120, 120) == res4);

    std::vector<DatingUser> usersSortedByIQ_single = { { 100, "100" } };
    std::vector<std::string> res5 = { "100" };
    assert(findUsers(usersSortedByIQ_single, 100, 100) == res5);

    std::vector<DatingUser> usersSortedByIQ_non_unique = { { 0, "0" }, { 0, "0-1" }, { 0, "0-2" }, { 1, "1-0" }, { 1, "1-1" }, { 2, "2" }, { 2, "2-1" }, { 3, "3-0" }, { 3, "3-1" }, { 3, "3-2" }, { 4, "4" }, { 5, "5" } };
    std::vector<std::string> res6 = { "1-0", "1-1", "2", "2-1", "3-0", "3-1", "3-2" };
    assert(findUsers(usersSortedByIQ_non_unique, 1, 3) == res6);

    //*****************************

    std::vector<long long> numbers = { +78005553535L, +78202019291L, +79121234129L, +79132929102L, +79165474747L };
    assert(findPhoneNumber(numbers, +79991234567) == -1);
    assert(findPhoneNumber(numbers, +78005553535L) == 0);
    assert(findPhoneNumber(numbers, +78202019291L) == 1);
    assert(findPhoneNumber(numbers, +79121234129L) == 2);
    assert(findPhoneNumber(numbers, +79132929102L) == 3);
    assert(findPhoneNumber(numbers, +79165474747L) == 4);
    assert(findPhoneNumber(numbers, +79165454748L) == -1);
    assert(findPhoneNumber(numbers, +78202029291L) == -1);
    assert(findPhoneNumber(numbers, +79121134129L) == -1);
    assert(findPhoneNumber(numbers, +78005653535L) == -1);
    reverse(numbers.begin(), numbers.end());
    assert(findPhoneNumber(numbers, +79991234567) == -1);
    assert(findPhoneNumber(numbers, +78005553535L) == 4);
    assert(findPhoneNumber(numbers, +78202019291L) == 3);
    assert(findPhoneNumber(numbers, +79121234129L) == 2);
    assert(findPhoneNumber(numbers, +79132929102L) == 1);
    assert(findPhoneNumber(numbers, +79165474747L) == 0);
    assert(findPhoneNumber(numbers, +79165454748L) == -1);
    assert(findPhoneNumber(numbers, +78202029291L) == -1);
    assert(findPhoneNumber(numbers, +79121134129L) == -1);
    assert(findPhoneNumber(numbers, +78005653535L) == -1);

    return 0;
}