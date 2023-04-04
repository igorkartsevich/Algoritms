#include "Array.h"
#include <cassert>
#include <iostream>

void canFinishTest(int numCourses, const std::vector<std::vector<int>> &prerequisites, bool result)
{
    //std::cout << "Can you finish all Skillbox cources";
    auto actual = Array::canFinish(numCourses, prerequisites);
    auto expected = result;

    assert(actual == expected);
}

int main(){
    canFinishTest(2, {{1, 0}}, true);
    canFinishTest(2, {{1, 0}, {0, 1}}, false);
    canFinishTest(5, {{4, 3}, {3, 2}, {2, 1}, {1, 0}}, true);
    return 0;
}