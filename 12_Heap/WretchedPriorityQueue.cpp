#include "WretchedPriorityQueue.h"

void WretchedPriorityQueue::doubleArray() {
    innerArray.resize(innerArray.size() * 2);
}

int WretchedPriorityQueue::size() {
    return m_size;
}

bool WretchedPriorityQueue::isEmpty() {
    return m_size == 0;
}

void WretchedPriorityQueue::add(int x) {
    {
        /*if (m_size == 0) {
        m_size++;
        innerArray[0] = x;
        return;
    }*/
    }

    if (size() == innerArray.size()) {
        doubleArray();
    }

    {
        //auto temp = x;
        //for (auto i = 0; i < m_size; ++i) {
        //    if (x >= innerArray[i]) { //if (x <= innerArray[i])
        //        int next;
        //        temp = innerArray[i];
        //        innerArray[i] = x;
        //        for (int b = i; b < m_size - 1; b++) {
        //            next = innerArray[b + 1];
        //            innerArray[b + 1] = temp;
        //            temp = next;
        //        }
        //        break;
        //    }
        //}

        //innerArray[m_size] = temp;
    }

    innerArray.push_back(x);
    int index = innerArray.size() - 1;

    while (true) {
        int indexToSift = (index - 1) >> 1;
        if (indexToSift < 0) break;
        
        if (innerArray[index] > innerArray[indexToSift]) {
            std::swap(innerArray[index], innerArray[indexToSift]);
            std::swap(index, indexToSift);
        }
        else break;
    }

    ++m_size;
}

int WretchedPriorityQueue::pop() {
    if (isEmpty())
        throw std::out_of_range("The queue is empty");

    auto retValue = innerArray[0];
    
    {
        /*if (m_size - 1 >= 0) {
            std::copy(innerArray.begin() + 1, innerArray.end(), innerArray.begin());
        }

        innerArray[m_size - 1] = 0;*/
    }

    innerArray[0] = innerArray.back();
    innerArray.pop_back();
    int index = 0;

    while (true) {
        int indexLeft = (index << 1) + 1;
        if (indexLeft >= innerArray.size()) break;
        
        int indexRight = (index << 1) + 2;
        int indexToSift = (indexRight >= innerArray.size()) ? indexLeft
            : (innerArray[indexLeft] > innerArray[indexRight]) ? indexLeft : indexRight;

        if (innerArray[index] < innerArray[indexToSift]) {
            std::swap(innerArray[index], innerArray[indexToSift]);
            std::swap(index, indexToSift);
        }
        else break;
    }
    
    m_size -= 1; //m_size -= 2;
    return retValue;
}

int WretchedPriorityQueue::peek() {
    if (isEmpty())
        throw std::out_of_range("The queue is empty");
    return innerArray[0];
}