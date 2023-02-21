#pragma once
#include <vector>
#include <stdexcept>
#include <exception>

class WretchedPriorityQueue {

private:   
    std::vector<int> innerArray;
    int m_size;

void doubleArray() {
        innerArray.resize(innerArray.size() * 2); 
    }

public: 
    WretchedPriorityQueue(){
        innerArray.resize(50);
        m_size = 0;
    }

    int size() {
        return m_size;
    }

    bool isEmpty() {
        return m_size == 0;
    }

    void add(int x) {
        if (m_size == 0) {
            m_size++;
            innerArray[0] = x;
            return;
        }

        if (size() == innerArray.size()){
            doubleArray();
        }

        auto temp = x;
        for (auto i = 0; i < m_size; ++i) {
            if (x <= innerArray[i]) {
                int next;
                temp = innerArray[i];
                innerArray[i] = x;
                for (int b = i; b < m_size - 1; b++) {
                    next = innerArray[b + 1];
                    innerArray[b + 1] = temp;
                    temp = next;
                }
                break;
            }
        }

        innerArray[m_size] = temp;
        ++m_size;
    }

    int pop() {
        if (isEmpty())
            throw std::out_of_range("The queue is empty");

        auto retValue = innerArray[0];
        if (m_size - 1 >= 0) {
            std::copy(innerArray.begin() + 1, innerArray.end(), innerArray.begin());
        }

        innerArray[m_size - 1] = 0;
        m_size -= 2;
        return retValue;
    }

    int peek() {
        if (isEmpty())
            throw std::out_of_range("The queue is empty");
        return innerArray[0];
    }
};
