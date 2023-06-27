#pragma once
#include <string>

class Bitmask {
public:
    // Возвращает битовую маску по ip адресу
    // "0.0.0.0" -> 0
    // "127.0.0.1" -> 2130706433
    static int ipToMask(const std::string& s) {
        // Implement this
        return 0;
    }

    // Возвращает, является ли submask подмаской mask
    static bool isSubmask(const std::string& mask, const std::string& submask);

    // Возвращает битовую маску циклически сдвинутую на cnt
    // Циклы использовать запрещено. cnt может быть меньше 0 и больше 32.
    // rotate(1, 1) == 2
    // rotate(1, -1) == -2147483648
    static int rotate(int mask, int cnt) {
        // Implement this
        return mask;
    }
};
