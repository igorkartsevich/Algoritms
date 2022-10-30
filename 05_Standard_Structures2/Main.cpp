#include "DLList.h"
#include <iostream>
#include <vector>
#include <string>
#include <cassert>


static void testToArray() {
    std::vector<int> t1 = { 1, 2, 5, 1, 2, 6, 1, 6, 8, 324, -10, 20 };
    std::vector<int> t2 = { 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 2, 3 };
    assert(t1 == DLList::fromArray(t1).toArray());
    assert(t2 == DLList::fromArray(t2).toArray());
    assert(t2 != DLList::fromArray(t1).toArray());
}

static void testSize() {
    std::vector<int> t1 = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> t2 = { 1 };
    std::vector<int> t3(10000);
    assert(DLList::fromArray(t1).getSize() == 6);
    assert(DLList::fromArray(t2).getSize() == 1);
    assert(DLList::fromArray(t3).getSize() == 10000);
    assert(DLList().getSize() == 0);
}

static void testPushAndPop() {
    DLList l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    assert(l.toArray() == (std::vector<int>{3, 2, 1, 4, 5, 6}));
    assert(6 == l.pop_back());
    assert(5 == l.pop_back());
    assert(3 == l.pop_front());
    assert(l.toArray() == (std::vector<int>{2, 1, 4}));
}

 static void removeAndInsertAfter() {
    DLList l;
    for (int i = 0; i < 10; ++i) {
        l.push_back(1);
    }
    for (int i = 9; i >= 0; --i) {
        l.insertAfter(l.getAt(i), i);
    }
    std::vector<int> res = l.toArray();
    assert(res == (std::vector<int>{1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9}));
    for (int i = 9; i >= 0; --i) {
        l.remove(l.getAt(2 * i));
    }
    assert(l.toArray() ==(std::vector<int> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
    assert(l.getSize() == 10);
    for (int i = 0; i < 10; ++i) {
        l.pop_back();
    }
    assert(l.getSize() == 0);
    for (int i = 0; i < 7; ++i) {
        l.push_front(1);
        l.push_back(2);
    }
    assert(l.getSize() == 14);
    for (int i = 0; i < 14; ++i) {
        l.pop_front();
    }
    assert(l.getSize() == 0);
    l.push_front(1);
    assert(l.end->x == 1);
    l.pop_back();
    l.push_back(2);
    assert(l.begin->x == 2);
    l.pop_front();
    l.push_back(7);
    assert(l.end->x == 7);
}

int main() {
    testToArray();
    testSize();
    testPushAndPop();
    removeAndInsertAfter();
    std::cout << "All tests for DLList passed successfully! Congrats";
    return 0;
}