#include <iostream>
#include <vector>
#include <exception>

class DLListEmpty_Exception : public std::exception {
public:
    const char* what() const noexcept override;
};

class NodeIsNotFound_Exception : public std::exception {
public:
    const char* what() const noexcept override;
};

class WrongNodeInArgument_Exception : public std::exception {
public:
    const char* what() const noexcept override;
};

class DLList {
public:
    DLList() {};
    virtual ~DLList() {};

    int size{};
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
    void push_front(int x);

    // This function should add new element with value x to the end of the list
    void push_back(int x);

    // This function could be useful for debug purposes
    void print();

    // This function should return the number of element in the list
    int getSize();

    // This function should return an array with values the same as in list
    std::vector<int> toArray();


    // This function should remove the element x from the list
    void remove(Node* x);

    // This function should remove first element in the list and return its value
    int pop_front();

    // This function should remove last element in the list and return its value
    int pop_back();

    // This function should insert element with the value val after the element x
    void insertAfter(Node* x, int val);

    // This function should return element at index
    Node* getAt(int index);

    // This function construct list from the array
    static DLList fromArray(const std::vector<int>& a);
};