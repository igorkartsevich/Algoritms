#include "Interview.h"
#include <assert.h>
#include <algorithm>

    int getRandomNumber(int min, int max) {
        return rand() % (max - min + 1) + min;
    }

    bool slowSolve1(const std::vector<int>& a, int S) {
        // Это медленное решение, вы должны придумать решение, которое работает за О(N)
        // И вообще, подсматривать решения в тестах - нехорошо
        for (int i = 0; i < a.size(); ++i) {
            int s = 0;
            for (int j = i; j < a.size(); ++j) {
                s += a[j];
                if (s == S) return true;
            }
        }
        return false;
    }

    void slowSolve2(std::vector<std::vector<int>>& a) {
        // Это медленное решение, вы должны придумать решение, которое не использует доп массив
        // И вообще, подсматривать решения в тестах - нехорошо
        std::vector<std::vector<int>> b{a.size(), std::vector<int>(a.size())};

        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a.size(); ++j) {
                b[a.size() - j - 1][i] = a[i][j];
            }
        }
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a.size(); ++j) {
                a[i][j] = b[i][j];
            }
        }
    }

    void testFindSubarray() {
        for (int T = 0; T < 1000; ++T) {
            int n = getRandomNumber(0, 10000) + 10;
            std::vector<int> a{n};
            for (int i = 0; i < a.size(); ++i) {
                a[i] = getRandomNumber(0, 1000) - 500;
            }
            int l = getRandomNumber(0, n);
            int r = getRandomNumber(0, n);
            if (r < l) {
                int t = l;
                l = r;
                r = t;
            }
            int S = 0;
            for (int i = l; i <= r; ++i) {
                S += a[i];
            }

            assert(slowSolve1(a, S) == Interview::findSubarray(a, S));
        }

        int cnt = 0;
        for (int T = 0; T < 1000; ++T) {
            int n = getRandomNumber(0, 10000) + 10;
            std::vector<int> a{n};
            for (int i = 0; i < a.size(); ++i) {
                a[i] = getRandomNumber(0, 1000) - 500;
            }
            int l = getRandomNumber(0, n);
            int r = getRandomNumber(0, n);
            if (r < l) {
                int t = l;
                l = r;
                r = t;
            }
            int S = getRandomNumber(0, 20000) - 10000;
            if (!slowSolve1(a, S)) {
                cnt += 1;
            }

            assert(slowSolve1(a, S) == Interview::findSubarray(a, S));
        }
    }

    void testRotateMatrix() {
        for (int T = 0; T < 10000; ++T) {
            int n = getRandomNumber(0, 100) + 1;
            std::vector<std::vector<int>> a{n, std::vector<int>(n)};
            std::vector<std::vector<int>> b{n, std::vector<int>(n)};
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    a[i][j] = rand();
                    b[i][j] = a[i][j];
                }
            }
            slowSolve2(a);
            Interview::rotateMatric(b);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    assert(a[i][j] == b[i][j]);
                }
            }

        }
    }

int main() {
    testFindSubarray();
    testRotateMatrix();
    return 0;
}
