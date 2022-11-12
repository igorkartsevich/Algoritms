#include "SimpleRecursion.h"
#include<iostream>
#include <cassert>
#include <vector>

static int findIterationFibonacci(int n)
{
    /* Declare an array to store Fibonacci numbers. */
    std::vector<int> f(n + 2); // 1 extra to handle case, n = 0
    int i;

    /* 0th and 1st number of the series are 0 and 1*/
    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        /* Add the previous 2 numbers in the series
          and store it */
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}



void findFibonacciTest() {
    std::cout << "Find number of Fibonacci" << std::endl;
    for (auto &n : { 1, 2, 7, 12 }) {
        auto actual = SimpleRecursion::findRecursionFibonacci(n);
        auto expected = findIterationFibonacci(n);
        assert(expected == actual);
    }
}

int main() {
  findFibonacciTest();
  std::cout << "All tests for DLList passed successfully! Congrats";
  return 0;
}
