#include "Stack.h"
#include <iostream>
#include <cassert>

static void testPolish() {
    assert(Stack::calcPolish("8 9 + 1 7 - *") == -102);
    assert(Stack::calcPolish("9 9 9 9 9 9 9 9 9 * * * * * * * *") == 387420489);
    assert(Stack::calcPolish("2 3 4 5 * 6 - 7 + 8 9 2 * 3 4 1 - 3 4 + * 5 - + * + - * +") == -985);
    assert(Stack::calcPolish("1 2 - 1 2 3 4 5 6 7 8 9 * * * * * * * * * 9 8 7 6 * * * *") == -1097349120);
    assert(Stack::calcPolish("1234") == 1234);
    assert(Stack::calcPolish("-1234") == -1234);
    assert(Stack::calcPolish("1234 1 1 + +") == 1236);
    std::string b = "";
    for (int i = 0; i < 10000; ++i) {
        b.append(std::to_string(i) + " ");
    }
    for (int i = 0; i < 9999; ++i) {
        b.append("+");
        if (i != 9999) {
            b.append(" ");
        }
    }
    assert(Stack::calcPolish(b) == (10000 * 9999) / 2);
    b = "";
    b.append("0 ");
    for (int i = 0; i < 20000; ++i) {
        b.append(std::to_string(i) + " +");
        if (i != 19999) {
            b.append(" ");
        }
    }
    assert(Stack::calcPolish(b) == (20000 * 19999) / 2);
}

int main() {
    testPolish();
    std::cout << "All STACK'S tests for List passed successfully! Congrats";
}
