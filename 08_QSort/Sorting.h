#pragma once
#include <time.h>
#include <functional>
#include <vector>

template<class T>
class Sorting
{
public:
    Sorting(std::function<int(const T&, const T&, int& sortComparisons)> compareTo = [](const T& a,
        const T& b, int& sortComparisons) {
            ++sortComparisons;
            return a < b ? -1 : a == b ? 0 : 1;
        }) {
        this->compareTo = compareTo;
    };

    ~Sorting() {};

    int selectionSortComparisons = 0;
    int insertionSortComparisons = 0;
    int bubbleSortComparisons = 0;
    int quickSortComparisons = 0;
    int mergeSortComparisons = 0;
    double selectionSortExecutionTime = 0;
    double insertionSortExecutionTime = 0;
    double bubbleSortExecutionTime = 0;
    double quickSortExecutionTime = 0;
    double mergeSortExecutionTime = 0;

    void selectionSort(std::vector<T>& data) {
        {
            auto startTime = clock();

            int size = (int)data.size();

            for (int i{}; i < size; ++i) {
                int indexMin = i;
                int min = data[indexMin];

                for (int j{ i + 1 }; j < size; ++j)
                    if (compareTo(data[j], min, selectionSortComparisons) < 0) {
                        indexMin = j;
                        min = data[indexMin];
                    }

                if (i != indexMin)
                    std::swap(data[i], data[indexMin]);
            }

            selectionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC * 1000;
        }
    };

    void insertionSort(std::vector<T>& data)
    {
        auto startTime = clock();
        
        int size = (int)data.size();

        for (int i{ 1 }; i < size; ++i) {
            int index = i;
            while (index > 0 && compareTo(data[index], data[index - 1], insertionSortComparisons) < 0) {
                std::swap(data[index], data[index - 1]);
                --index;
            }
        }
            
        insertionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC * 1000;
    }

    void bubbleSort(std::vector<T>& data)
    {
        auto startTime = clock();
        
        int size = (int)data.size();
        bool is_sorted = false;

        while (size-- > 1 || !is_sorted) {
            is_sorted = true;

            for (int i{}; i < size; ++i)
                if (compareTo(data[i], data[i + 1], bubbleSortComparisons) > 0) {
                    std::swap(data[i], data[i + 1]);
                    is_sorted = false;
                }
        }

        bubbleSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC * 1000;
    }

    //MergeSORT*************************************************

    std::vector<int> getMerge(std::vector<int> leftArray, std::vector<int> rightArray) {
        int leftSize = (int)leftArray.size();
        int rightSize = (int)rightArray.size();
        std::vector<int> res(leftSize + rightSize);
        int leftIndex{}, rightIndex{}, resIndex{};

        while (leftIndex < leftSize || rightIndex < rightSize)
            (leftIndex < leftSize&& rightIndex < rightSize)
                ? res[resIndex++] = (compareTo(leftArray[leftIndex], rightArray[rightIndex], mergeSortComparisons) < 0)
                    ? leftArray[leftIndex++]
                    : rightArray[rightIndex++]
                : res[resIndex++] = (leftIndex == leftSize)
                    ? rightArray[rightIndex++]
                    : leftArray[leftIndex++];
        return res;
    }
    std::vector<int> getMergeSort(std::vector<int> data) {
        int size = (int)data.size();
        if (size <= 1)
            return data;
        else {
            int middle = size >> 1;

            std::vector<int> leftArray(middle);
            std::copy(begin(data), begin(data) + middle, begin(leftArray));

            std::vector<int> rightArray(size - middle);
            std::copy(begin(data) + middle, end(data), begin(rightArray));

            return getMerge(getMergeSort(leftArray), getMergeSort(rightArray));
        }
    }
    void mergeSort(std::vector<T>& data)
    {
        auto startTime = clock();
        
        data = getMergeSort(data);

        mergeSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC * 1000;
    }

    //QSORT*****************************************************

    void getQSort(std::vector<int>& data, int left, int right) {
        if (right - left <= 1) return;

        int medianaIndex = rand() % (right - left);
        int medianaData = data[medianaIndex];

        while (left < right)
            if (compareTo(data[left], medianaData, quickSortComparisons) > 0 && compareTo(medianaData, data[right], quickSortComparisons) > 0)
                std::swap(data[left++], data[right--]);
            else (data[left] < medianaData) ? ++left : --right;

        getQSort(data, left, medianaIndex);
        getQSort(data, medianaIndex, right);
    }
    void quickSort(std::vector<T>& data)
    {
        auto startTime = clock();
        
        getQSort(data, 0, data.size() - 1);

        quickSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC * 1000;
    }

private:
    std::function<int(const T&, const T&, int &sortComparisons)> compareTo;

};