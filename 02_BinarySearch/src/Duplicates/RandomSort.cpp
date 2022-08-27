#include <vector>
#include <iostream>

using namespace std;

bool myIsSorted(const vector<int>& array) {
    // please implement
    return false;
}

void RandomSort(vector<int>& array) {
    // please implement
    // отсортируйте входной массив array
}

int main(void) {
    vector<int> a = {7, 1, 2, 12, 0};
    RandomSort(a);
    for (int x : a) {
        cout << x << " ";
    }
    cout << "Check on other tests" << endl;
}