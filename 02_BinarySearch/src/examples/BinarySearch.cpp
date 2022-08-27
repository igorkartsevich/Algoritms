#include <iostream>
#include <vector>
using namespace std;
int binarySearch(const vector<int> &a, int key) {
    int l = -1, r = int(a.size() - 1);
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] < key) {
            l = m;
        } else {
            r = m;
        }
    }
    if (a[r] < key) return r + 1;
    return r;
}

int main(void) {
    vector<int> a = {1, 2, 4, 5, 7};
    cout << binarySearch(a, -1) << endl;
    cout << binarySearch(a, 2) << endl;
    cout << binarySearch(a, 5) << endl;
    cout << binarySearch(a, 6) << endl;
    cout << binarySearch(a, 7) << endl;
    cout << binarySearch(a, 10) << endl;
}