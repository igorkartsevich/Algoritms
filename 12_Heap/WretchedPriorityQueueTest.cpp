#include "WretchedPriorityQueue.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <chrono>
#include <algorithm>


const int SIZE = 500;

void sizeTest()
{
    WretchedPriorityQueue queue;
    assert(0 == queue.size());
    queue.add(1);
    assert(1 == queue.size());
    queue.pop();
    assert(0 == queue.size());
}

void isEmptyTest()
{
    WretchedPriorityQueue queue;
    assert(queue.isEmpty());
    queue.add(1);
    assert(!queue.isEmpty());
    queue.pop();
    assert(queue.isEmpty());
}

void peekTest()
{
    WretchedPriorityQueue queue;
    for (auto i = 1; i <= SIZE; ++i)
    {
        queue.add(i);
    }

    for (auto i = SIZE; i > 0; --i)
    {
        assert(SIZE - i + 1 == queue.peek());
        assert(SIZE - i + 1 == queue.pop());
    }

    try {
        queue.peek();
        assert(false);
    }
    catch (std::out_of_range &ex){
        assert(true);
    }
}

void popTest()
{
    std::priority_queue<int> ints;
    WretchedPriorityQueue queue;
    for (auto i = 0; i < 100; ++i) {
        auto val = rand();
        ints.push(val);
        queue.add(val);
    }


    while (!ints.empty())
    {
        assert(ints.top() == queue.pop());
        ints.pop();
    }

    try {
        queue.peek();
        assert(false);
    }
    catch (std::out_of_range &ex){
        assert(true);
    }
}

void timeTest()
{
    std::priority_queue<int> ints;
    WretchedPriorityQueue queue;
    std::vector<int> a(1000);
    std::generate(a.begin(), a.end(), []()
                  { return rand(); });

    auto start = std::chrono::steady_clock::now();
    for (int k : a)
    {
        ints.push(k);
    }
    while (!ints.empty())
    {
        ints.pop();
    }
    auto standart = std::chrono::steady_clock::now() - start;

    start = std::chrono::steady_clock::now();
    for (int j : a)
    {
        queue.add(j);
    }
    while (!ints.empty())
    {
        queue.pop();
    }
    auto our = std::chrono::steady_clock::now() - start;

    assert(our / standart < 10);
    //иначе очередь работает слишком долго
}

int main() {
    isEmptyTest();
    peekTest();
    popTest();
    timeTest();
    return 0;
}
