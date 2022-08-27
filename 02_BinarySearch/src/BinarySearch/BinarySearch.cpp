#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

bool doIKnowThisLanguage(const vector<string>& languagesList, string language) {
    return false; // please implement
}


struct DatingUser {
    int IQ;
    string name;
};

vector<string> findUsers(vector<DatingUser> usersSortedByIQ, int lowerIQBound, int professorIQ) {
        return vector<string>(); // please implement
}

int findPhoneNumber(const vector<long long>& sortedPhoneNumbers, long long search) {
        return -1; //please implement
}

int main(void) {
    vector<string> languages = {"ADA", "C", "C++", "Go", "Java", "Python"};
    assert(doIKnowThisLanguage(languages, "C++"));
    assert(!doIKnowThisLanguage(languages, "OCaml"));
    vector<long long> numbers = { +78005553535L, +78202019291L, +79121234129L, +79132929102L, +79165474747L };
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
    // add more tests for all functions here
}