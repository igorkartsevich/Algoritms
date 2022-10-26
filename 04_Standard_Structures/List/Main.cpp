#include "List.h"
#include <vector>
#include <cassert>

static void testToArray() {
    std::vector<int> t1{ 1, 2, 5, 1, 2, 6, 1, 6, 8, 324, -10, 20 };
    std::vector<int> t2 { 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 2, 3 };
    assert(t1 == List::fromArray(t1).toArray());
    assert(t2 == List::fromArray(t2).toArray());
    assert(t2 != List::fromArray(t1).toArray());
}

static void testSize() {
    std::vector<int> t1{ 1, 2, 3, 4, 5, 6 };
    std::vector<int> t2{ 1 };
    std::vector<int> t3(10000);
    assert(List::fromArray(t1).getSize() == 6);
    assert(List::fromArray(t2).getSize() == 1);
    assert(List::fromArray(t3).getSize() == 10000);
    assert(List().getSize() == 0);
}
static void testEverySecond() {
    std::vector<int> t1{ 1, 2, 3, 4, 5, 6 };
    std::vector<int> a1{ 1, 3, 5 };
    std::vector<int> t2{ 1 };
    std::vector<int> a2{ 1 };
    std::vector<int> t3{ 1, 1, 1, 1 };
    std::vector<int> a3{ 1, 1 };
    std::vector<int> t4{ 6, 1, 6, 1, 6, 2, 5, 3, 7 };
    std::vector<int> a4{ 6, 6, 6, 5, 7 };
    List l = List::fromArray(t1);
    List l2 = l.copyEverySecond();
    assert(l2.toArray() == a1);
    assert(l.toArray() == t1);

    l = List::fromArray(t2);
    l2 = l.copyEverySecond();
    assert(l2.toArray() == a2);
    assert(l.toArray() == t2);

    l = List::fromArray(t3);
    l2 = l.copyEverySecond();
    assert(l2.toArray() == a3);
    assert(l.toArray() == t3);

    l = List::fromArray(t4);
    l2 = l.copyEverySecond();
    assert(l2.toArray() == a4);
    assert(l.toArray() == t4);
}

static void testFilterX() {
    std::vector<int> t1{ 1, 2, 3, 4, 5, 6 };
    std::vector<int> a1{ 1, 3, 5 };
    std::vector<int> t2{ 1 };
    std::vector<int> a2{ 1 };
    std::vector<int> t3{ 12, 6, 1, 7 };
    std::vector<int> a3{ 1, 7 };
    std::vector<int> t4{ 8, 2, 12, 4, 120, 1240, 5, 1224, 2024 };
    std::vector<int> a4{ 2, 5 };
    std::vector<int> t5(10000);
    List l = List::fromArray(t1);
    l.filterDivisible(2);
    assert(l.toArray() == a1);

    l = List::fromArray(t2);
    l.filterDivisible(7);
    assert(l.toArray() == a2);

    l = List::fromArray(t3);
    l.filterDivisible(3);
    assert(l.toArray() == a3);

    l = List::fromArray(t4);
    l.filterDivisible(4);
    assert(l.toArray() == a4);

    l = List::fromArray(t5);
    l.filterDivisible(7);
    assert(l.getSize() == 0);
}

static void testGetAndInsert() {
    List l;
    l.push_front(4);
    l.push_front(3);
    l.push_front(1);
    l.insertAfter(l.getAt(0), 2);
    l.insertAfter(l.getAt(3), 5);
    List::Node *n = l.getAt(2);
    for (int i = 0; i < 5; ++i) {
        l.insertAfter(n, 100);
    }
    std::vector<int> ans{ 1, 2, 3, 100, 100, 100, 100, 100, 4, 5 };
    assert(l.toArray() == ans);
    List l2;
    for (int i = 0; i < 5; ++i) {
        l2.push_front(0);
        l2.insertAfter(l2.getAt(0), 1);
    }
    std::vector<int> ans2{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };
    assert(l2.toArray() == ans2);
}


int main() {
    testToArray();
    testSize();
    testEverySecond();
    testFilterX();
    testGetAndInsert();
    std::cout <<  "All LIST'S tests for List passed successfully! Congrats";
    return 0;
}