#include "RandomizedAlgorithms.h"

#include <cassert>
#include <iostream>

void findPiTest(int dots) {
    std::cout << "Calculate PI";
    auto pi = RandomizedAlgorithms::findPi(dots);
    assert(pi > 2.5 && pi < 4);
}


int main() {
    for (auto i : {100, 1000, 10000, 100000, 1000000}) {
        findPiTest(i);
    }
    return 0;
}