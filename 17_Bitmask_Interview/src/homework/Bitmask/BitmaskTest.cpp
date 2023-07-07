#include "Bitmask.h"
#include <assert.h>
#include <vector>

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void testIsSubmask() {
        for (int i = 0; i < 1000; ++i) {
            std::vector<int> a(4); //std::vector<int> a{4};
            std::vector<int> b(4); //std::vector<int> b{4};

            for (int j = 0; j < 4; ++j) {
                a[j] = getRandomNumber(0, 256);
            }

            bool f = true;
            for (int j = 0; j < 4; ++j) {
                b[j] = getRandomNumber(0, 256);
                if ((a[j] & b[j]) != b[j]) {
                    f = false;
                }
            }

            if (getRandomNumber(0, 1)) {
                f = true;
                for (int j = 0; j < 4; ++j) {
                    b[j] &= a[j];
                }
            }

            auto s1 = std::to_string(a[0]);
            auto s2 = std::to_string(b[0]);
            for (int j = 1; j < 4; ++j) {
                s1 += "." + std::to_string(a[j]);
                s2 += "." + std::to_string(b[j]);
            }

            assert(f == Bitmask::isSubmask(s1, s2));
        }
}

int rotr(int x) {
        int c = x & 1;
        x = x >> 1;
        x = x | (c << 31);
        return x;
}

int rotl(int x) {
        int c = x >> 31;
        x = x << 1;
        x = ((x | 1) ^ 1) ^ c;
        return x;
}

void testRotate() {
    for (int i = 0; i < 10000; ++i) {
        int x = rand();
        int c = getRandomNumber(0, 200);;
        if (getRandomNumber(0, 1)) {
            c *= -1;
        }

        x = 7;
        c = 3;

        int ex = x;
        if (c > 0) {
            for (int j = 0; j < c; ++j) {
                ex = rotl(ex);
            }
        } else {
            for (int j = 0; j < -c; ++j) {
                ex = rotr(ex);
            }
        }

        assert(ex == Bitmask::rotate(x, c));
    }
}

int main() {
    testIsSubmask();
    testRotate();
    return 0;
}
