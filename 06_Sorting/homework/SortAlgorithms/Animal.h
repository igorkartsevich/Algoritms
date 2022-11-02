#pragma once

class Animal {
public:
    Animal() {};
    virtual ~Animal() {};
    virtual int getWeight() = 0;
};