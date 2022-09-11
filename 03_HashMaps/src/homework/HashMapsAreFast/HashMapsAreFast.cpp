#include <vector>
#include <cassert>
using namespace std;

vector<long long> getUniqueNumbers(vector<long long> inputArray) {
    return inputArray; // please implement
}


bool isThereTwoNumbers(vector<int> numbers, int X) {
    return false; // please implement
}

int main(void) {
    vector<long long> a = {+79127231920, +79127231921, +79127231920, +79127231923, +79127231922, +79127231921, +79127231923, +79127231924};
    assert(getUniqueNumbers(a) == vector<long long>({+79127231920, +79127231921, +79127231923, +79127231922, +79127231924}));
    assert(isThereTwoNumbers({1, -2, 3, 4}, 2) == true);
    assert(isThereTwoNumbers({1, -2, 3, 4}, 6) == false);
    assert(isThereTwoNumbers({1, -2, 3, 4}, -1) == true);
    assert(isThereTwoNumbers({1, -2, 3, 4}, -5) == true);
}
