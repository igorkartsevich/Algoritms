#pragma once
#include <vector>
#include <stdexcept>
#include <exception>

class WretchedPriorityQueue {

private:   
    std::vector<int> innerArray;
    int m_size;

    void doubleArray();

public: 
    WretchedPriorityQueue(){
        innerArray.resize(50);
        m_size = 0;
    }

    int size();
    bool isEmpty();
    void add(int x);
    int pop();
    int peek();
};
