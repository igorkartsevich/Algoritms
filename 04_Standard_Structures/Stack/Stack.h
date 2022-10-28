#include <vector>
#include <string>
#include <sstream>

// Stack implemented using dynamic array inside
class Stack {
private:
    struct Node {
        long x;
        Node* next;
        Node(long _x) {
            x = _x;
        };
    };
    int size{ 0 };
    Node* begin{ nullptr };

public:
    Stack() {}
    virtual ~Stack() {};

    int getSize();

    // This function is called when it's not enough memory to fit new elements.
    // It creates new long array and copies all the elements there.
    void reallocate();

    // Adds element to the end of the stack
    void push_back(long x);

    // Removes last element from the stack and returns its value
    long pop_back();

    // Returns value of the last element in the stack
    long top();

    // Calculates the result of reversed polish notation. https://en.wikipedia.org/wiki/Reverse_Polish_notation
    // This one is simplified. Every number and character are separated by exactly one space.
    // Only + - * should be supported.
    // Example: calcPolish("1 2 3 * -") should return -5 | because (1 - (2 * 3))
    static long calcPolish(const std::string& s);
};
