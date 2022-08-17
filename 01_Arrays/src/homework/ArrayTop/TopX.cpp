#include <vector>
#include <climits>
#include <algorithm>

#include "TopX.h"

using namespace std;

int findMaxUnderBoundary(const vector<int>& inp, int topBoundary) {
    int cur = INT_MIN;
    for (int i = 0; i < inp.size(); ++i) {
        if (inp[i] < topBoundary) {
            cur = max(cur, inp[i]);
        }
    }
    return cur;
}

vector<int> findTopElements(const vector<int>& inp, int numberOfElements) {
    // Создадим массив для результата
    vector<int> res;
    // Нам требуется знать предыдущее значение максимума,
    // По-умолчанию мы положим туда максимальное значение для типа int
    int previousMax = INT_MAX;

    // Выполним цикл столько раз, сколько максимумов нам нужно найти
    for (int i = 0; i < numberOfElements; i++) {
        // Найдем текущий максимум
        int currentMax = findMaxUnderBoundary(inp, previousMax);

        // Обновим значение "предыдущего" максимума
        previousMax = currentMax;

        // Положим результат в выходной массив
        res.push_back(currentMax);
    }
    return res;
}

vector<int> findBottomElements(const vector<int>& inp, int elements) {
    return vector<int>(elements, 0); // Please implement
}
