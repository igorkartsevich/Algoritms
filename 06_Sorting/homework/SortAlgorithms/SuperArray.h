#pragma once

class SuperArray {
public:
    SuperArray() {};
    ~SuperArray() {};
    virtual int getSize() =0;
    virtual int get(int position) =0;
    virtual void set(int position, int value) = 0;
};