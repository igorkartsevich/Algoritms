#include "Stack.h"

int Stack::getSize() {
    return size;
}

// This function is called when it's not enough memory to fit new elements.
// It creates new long array and copies all the elements there.
void Stack::reallocate() {}

// Adds element to the end of the stack
void Stack::push_back(long x) {
    /* IMPLEMENT THIS */
    Node* node = new Node(x);
    node->next = begin;
    begin = node;
}

// Removes last element from the stack and returns its value
long Stack::pop_back() {
    /* IMPLEMENT THIS */
    long last = begin->x;
    Node* node = begin->next;
    begin = node;
    return last;
}

// Returns value of the last element in the stack
long Stack::top() {
    /* IMPLEMENT THIS */
    return begin->x;
}

long Stack::calcPolish(const std::string& s) {
    /* IMPLEMENT THIS */
    std::stringstream DATA;
    DATA << s;

    Stack stack;
    while (!DATA.eof()) {
        std::string str;
        DATA >> str;
        if (str == "+")
            stack.push_back(stack.pop_back() + stack.pop_back());
        else if (str == "-")
            stack.push_back(-stack.pop_back() + stack.pop_back());
        else if (str == "*")
            stack.push_back(stack.pop_back() * stack.pop_back());
        else if (str != " " && str != "\0")
            stack.push_back(std::stoi(str));
    }

    return stack.pop_back();
}