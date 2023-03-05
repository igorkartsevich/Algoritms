#pragma once
#include <string>

class Contact {
public:
    std::string name;
    std::string number;

    Contact(const std::string& _name, 
            const std::string& _number) : 
            name(_name),
            number(_number) 
    { }
};