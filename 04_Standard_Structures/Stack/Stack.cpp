#include "Stack.h"

int Stack::getSize() {
    return size;
}

// This function is called when it's not enough memory to fit new elements.
// It creates new long array and copies all the elements there.
void Stack::reallocate() {
    /* IMPLEMENT THIS */
    std::vector<long> new_a(a.size() * 2);
    for (int i{}; i < size; ++i)
        new_a[i] = a[i];
    a = new_a;
}

// Adds element to the end of the stack
void Stack::push_back(long x) {
    /* IMPLEMENT THIS */
    if (size + 1 > a.size())
        reallocate();
    for (int i{ size }; i > 0; --i)
        a[i] = a[i - 1];
    a[0] = x;
    ++size;
}

// Removes last element from the stack and returns its value
long Stack::pop_back() {
    /* IMPLEMENT THIS */
    int node = a[0];
    for (int i{}; i < size - 1; ++i)
        a[i] = a[i + 1];
    --size;
    return node;
}

// Returns value of the last element in the stack
long Stack::top() {
    /* IMPLEMENT THIS */
    return a[0];
}