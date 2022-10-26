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
    void push_front(int x) {
        Node* node = new Node(x);
        node->next = begin;
        begin = node;
    }

    // This function could be useful for debugging and testing.
    void print() {
        Node* n = begin;
        while (n != nullptr) {
            std::cout << n->x << " ";
            n = n->next;
        }
        std::cout << std::endl;
    }

    // This function should return copy of the list where every second element is removed.
    // Initial list should not be changed.
    // E.g. if we run copyEverySecond on list [1, 2, 3, 4, 5, 6, 7, 100, 120, 162, 0, 1]
    // new list with values [1, 3, 5, 7, 120, 0] should be returned.
    List copyEverySecond() {
        /* TODO IMPLEMENT THIS */
        int counter{};
        Node* node = begin;
        std::vector<int> tmp;
        while (node != nullptr) {
            if (counter % 2 == 0) {
                tmp.push_back(node->x);
            }
            ++counter;
            node = node->next;
        }

        List l;
        for (int i = (int)tmp.size() - 1; i >= 0; --i)
            l.push_front(tmp[i]);
        return l;
    }

    // Returns number of elements in list
    int getSize() {
        /* TODO IMPLEMENT THIS */
        int counter{};
        Node* node = begin;
        while (node != nullptr) {
            ++counter;
            node = node->next;
        }
        return counter;
    }

    // This function converts our list to an array. New array is created with values the same as in list.
    std::vector<int> toArray() {
        /* TODO IMPLEMENT THIS */
        std::vector<int> array;

        Node* node = begin;

        while (node != nullptr) {
            array.push_back(node->x);
            node = node->next;
        }

        return array;
    }

    // This function removes elements x.next from the list
    // O(1) time is expected
    void removeAfter(Node* x) {
        /* TODO IMPLEMENT THIS */
        Node* node = begin;
        Node* nodeTMP = nullptr;

        while (node != nullptr) {
            if (node == x)
                break;
            else node = node->next;
        }

        if (node->next == nullptr) return;

        nodeTMP = node->next->next;
        node->next = nodeTMP;
    }

    // This function inserts new element with value val right after the element x.
    // O(1) time is expected
    void insertAfter(Node* x, int val) {
        /* TODO IMPLEMENT THIS */
        Node* node = begin;
        while (node != nullptr) {
            if (node = x)
                break;
            else node = node->next;
        }
        Node* node_new = new Node(val);
        node_new->next = node->next;
        node->next = node_new;
    }

    // This function removes all elements from the list that are divisible by x.
    // E.g. list {1, 2, 3, 4, 4, 10, 7}  after filterDivisible(2) would look like {1, 3, 7}.
    // O(N) time is expected.
    void filterDivisible(int x) {
        /* TODO IMPLEMENT THIS */
        Node* node = begin;
        Node* nodeTMP = nullptr;

        while (node != nullptr) {
            if (node->x % x != 0) {
                nodeTMP = node;
                node = node->next;

                begin = nodeTMP;
                nodeTMP->next = nullptr;
                break;
            }
            else node = node->next;
        }

        if (nodeTMP == nullptr) {
            begin = nullptr;
            return;
        }

        while (node != nullptr) {
            if (node->x % x != 0) {
                nodeTMP->next = node;
                nodeTMP = node;
                node = node->next;
                nodeTMP->next = nullptr;
            }
            else
                node = node->next;
        }
    }

    // This function returns Node from the list by index. O(N) time is expected.
    Node* getAt(int index) {
        /* TODO IMPLEMENT THIS */
        Node* node = begin;
        int counter{};
        while (node != nullptr) {
            if (counter == index)
                return node;
            node = node->next;
            ++counter;
        }
        return nullptr;
    }

    // This function creates List from an array
    static List fromArray(const std::vector<int>& a) {
        List l;
        for (int i = a.size() - 1; i >= 0; --i) {
            l.push_front(a[i]);
        }
        return l;
    }
};
