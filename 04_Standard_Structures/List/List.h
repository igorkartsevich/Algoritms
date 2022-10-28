#pragma once

#include <iostream>
#include <vector>

class List {
public:
    List() {};
    virtual ~List() {};

    struct Node {
        int x;
        Node* next = nullptr;
        Node(int _x) {
            x = _x;
        }
    };

    // Pointer to the beginning of the list
    Node* begin{ nullptr };

    // Adds element to the beginning of the list
    void push_front(int x);

    // This function could be useful for debugging and testing.
    void print();

    // This function should return copy of the list where every second element is removed.
    // Initial list should not be changed.
    // E.g. if we run copyEverySecond on list [1, 2, 3, 4, 5, 6, 7, 100, 120, 162, 0, 1]
    // new list with values [1, 3, 5, 7, 120, 0] should be returned.
    List copyEverySecond();

    // Returns number of elements in list
    int getSize();

    // This function converts our list to an array. New array is created with values the same as in list.
    std::vector<int> toArray();

    // This function removes elements x.next from the list
    // O(1) time is expected
    void removeAfter(Node* x);

    // This function inserts new element with value val right after the element x.
    // O(1) time is expected
    void insertAfter(Node* x, int val);

    // This function removes all elements from the list that are divisible by x.
    // E.g. list {1, 2, 3, 4, 4, 10, 7}  after filterDivisible(2) would look like {1, 3, 7}.
    // O(N) time is expected.
    void filterDivisible(int x);

    // This function returns Node from the list by index. O(N) time is expected.
    Node* getAt(int index);

    // This function creates List from an array
    // This function creates List from an array
    static List fromArray(const std::vector<int>& a);

};
