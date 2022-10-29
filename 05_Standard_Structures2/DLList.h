#include <iostream>
#include <vector>
#include <string>

class DLList {
public:
    DLList() {};
    virtual ~DLList() {};

    struct Node {
        int x;
        Node* next{ nullptr };
        Node* prev{ nullptr };
        Node(int x) {
            this->x = x;
        }
    };
    // You should store pointer to the first element of the list here
    Node* begin{ nullptr };
    // You should store pointer to the last element of the list here
    Node* end{ nullptr };

    // This function should add new element with value x to the front of the list
    void push_front(int x) {
    }

    // This function should add new element with value x to the end of the list
    void push_back(int x) {
    }

    // This function could be useful for debug purposes
    void print() {
        Node* n = begin;
        while (n != nullptr) {
            std::cout << n->x << " ";
            n = n->next;
        }
        std::cout << std::endl;
    }

    // This function should return the number of element in the list
    int getSize() {
        return 0;
    }

    // This function should return an array with values the same as in list
    std::vector<int> toArray() {
        return {};
    }


    // This function should remove the element x from the list
    void remove(Node* x) {
    }

    // This function should remove first element in the list and return its value
    int pop_front() {
        return 0;
    }

    // This function should remove last element in the list and return its value
    int pop_back() {
        return 0;
    }

    // This function should insert element with the value val after the element x
    void insertAfter(Node* x, int val) {
    }

    // This function should return element at index
    Node* getAt(int index) {
        return nullptr;
    }

    // This function construct list from the array
    static DLList fromArray(const std::vector<int> &a) {
        DLList l;
        for (int i = 0; i < a.size(); ++i) {
            l.push_back(a[i]);
        }
        return l;
    }
};