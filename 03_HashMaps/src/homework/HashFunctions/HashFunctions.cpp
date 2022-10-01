#include <string>
#include <cassert>
#include <iostream>

int hashString(const std::string& input) {
    int hashCode{};
    for (auto element : input)
        hashCode += element;

    return hashCode; // Please implement
}

int hashInt(int input) {
    int hashCode{ 0 };
    while (input % 10) {
        hashCode += input % 10;
        input /= 10;
    };

    return hashCode; // Please implement
}

struct Student {
    int age;
    std::string name;
};

int hashStudent(Student input) {
    int hashCode{},
        tmp = hashInt(input.age) * hashString(input.name);
    // tmp = 12345
    // hashCode = hashCode + 12345 * 5
    // hashCode = hashCode + 1234 * 4
    // ...
    while (tmp % 10) {
        hashCode += tmp * (tmp % 10);
        tmp /= 10;
    }
    return hashCode;
}

int main(void) {
    assert(hashInt(10) == hashInt(10));
    assert(hashInt(10) != hashInt(11));

    Student student;
    student.age = 31;
    student.name = "aaaa";
    assert(hashStudent(student), 3955);

    return 0;
}
