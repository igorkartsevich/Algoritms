#include <iostream>
#include <vector>
using namespace std;

void unique(vector<int> &a) {
    for (int i = 0; i < a.size();) {
        bool found = false;
        int pos = -1;
        for (int j = i + 1; j < a.size(); ++j) {
            if (a[j] == a[i]) {
                found = true;
                pos = j;
                break;
            }
        }
        if (found) {
            for (int j = pos; j < int(a.size()) - 1; ++j) {
                a[j] = a[j + 1];
            }
            a.pop_back();
        } else {
            i++;
        }
    }
}

int main(void) {
    vector<int> a = {15, 23, 20, 5, 15, 20, 15, 20, 13};
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    unique(a);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
