#include <string>
#include <cassert>

using namespace std;

int hashString(string input) {
    return -1; // Please implement
}

int hashInt(int input) {
    return -1; // Please implement
}

struct Student {
    int age;
    string name;
};

int hashStudent(Student input) {
    return -1; // Please implement
}

int main(void) {
    assert(hashInt(10) == hashInt(10));
    assert(hashInt(10) != hashInt(11));
}
