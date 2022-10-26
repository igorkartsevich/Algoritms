#include <vector>
#include <string>
#include <sstream>

// Stack implemented using dynamic array inside
class Stack {
private:
    // Array where we store the data
    std::vector<long> a;
    // Number of elements that we actually store in the array. <= a.length
    int size{ 0 };
public:
    Stack() {
        a.resize(10);
    }
    virtual ~Stack() {};

    int getSize() {
        return size;
    }

    // This function is called when it's not enough memory to fit new elements.
    // It creates new long array and copies all the elements there.
    void reallocate() {
        /* IMPLEMENT THIS */
        std::vector<long> new_a(a.size() * 2);
        for (int i{}; i < size; ++i)
            new_a[i] = a[i];
        a = new_a;
    }

    // Adds element to the end of the stack
    void push_back(long x) {
        /* IMPLEMENT THIS */
        if (size + 1 > a.size())
            reallocate();
        for (int i{ size }; i > 0; --i)
            a[i] = a[i - 1];
        a[0] = x;
        ++size;
    }

    // Removes last element from the stack and returns its value
    long pop_back() {
        /* IMPLEMENT THIS */
        int node = a[0];
        for (int i{}; i < size - 1; ++i)
            a[i] = a[i + 1];
        --size;
        return node;
    }

    // Returns value of the last element in the stack
    long top() {
        /* IMPLEMENT THIS */
        return a[0];
    }

    // Calculates the result of reversed polish notation. https://en.wikipedia.org/wiki/Reverse_Polish_notation
    // This one is simplified. Every number and character are separated by exactly one space.
    // Only + - * should be supported.
    // Example: calcPolish("1 2 3 * -") should return -5 | because (1 - (2 * 3))
    static long calcPolish(const std::string& s) {
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
};
