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

    virtual ~Sorting() {};

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

    void selectionSort(std::vector<T>& data)
    {
        auto startTime = clock();
        
        int size = (int)data.size();

        for (int i{}; i < size; ++i) {
            int indexMin = i;
            int min = data[indexMin];

            for (int j{ i + 1 }; j < size; ++j)
                if (data[j] < min) {
                    indexMin = j;
                    min = data[indexMin];
                }

            if (i != indexMin)
                std::swap(data[i], data[indexMin]);
        }

        selectionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
    }

    void insertionSort(std::vector<T>& data)
    {
        auto startTime = clock();
        
        int size = (int)data.size();

        for (int i{ 1 }; i < size; ++i) {
            int index = i;
            while (index > 0 && data[index] < data[index - 1]) {
                std::swap(data[index], data[index - 1]);
                --index;
            }
        }
            
        insertionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
    }

    void bubbleSort(std::vector<T>& data)
    {
        auto startTime = clock();
        
        int size = (int)data.size();
        bool is_sorted = false;

        while (size-- > 1 || !is_sorted) {
            is_sorted = true;

            for (int i{}; i < size; ++i)
                if (data[i] > data[i + 1]) {
                    std::swap(data[i], data[i + 1]);
                    is_sorted = false;
                }
        }

        bubbleSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
    }

    //MergeSORT*************************************************

    std::vector<int> getMerge(std::vector<int> leftArray, std::vector<int> rightArray) {
        int leftSize = (int)leftArray.size();
        int rightSize = (int)rightArray.size();
        std::vector<int> res(leftSize + rightSize);
        int leftIndex{}, rightIndex{}, resIndex{};

        while (leftIndex < leftSize || rightIndex < rightSize)
            (leftIndex < leftSize&& rightIndex < rightSize)
                ? res[resIndex++] = (leftArray[leftIndex] < rightArray[rightIndex])
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

        selectionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
    }

    //QSORT*****************************************************

    void getQSort(std::vector<int>& data, int left, int right) {
        if (right - left <= 1) return;

        srand(time(0));
        int medianaIndex = rand() % (right - left);
        int medianaData = data[medianaIndex];

        while (left < right)
            if (data[left] >= medianaData && data[right] <= medianaData)
                std::swap(data[left++], data[right--]);
            else (data[left] < medianaData) ? ++left : --right;

        getQSort(data, left, medianaIndex);
        getQSort(data, medianaIndex, right);
    }
    void quickSort(std::vector<T>& data)
    {
        auto startTime = clock();
        
        getQSort(data, 0, data.size() - 1);

        quickSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
    }

private:
    void swap(std::vector<T>& data, int index1, int index2)
    {
        T temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
    }

    void quickSort(std::vector<T>& array, int low, int high) {
        if (array.size() == 0)
            return;//завершить выполнение если длина массива равна 0

        if (low >= high)
            return;//завершить выполнение если уже нечего делить

        // выбрать опорный элемент
        int middle = low + (high - low) / 2;
        auto opora = array[middle];

        // разделить на подмассивы, который больше и меньше опорного элемента
        int i = low, j = high;
        while (i <= j) {
            while (compareTo(array[i], opora) < 0) {
                i++;
            }

            while (compareTo(array[j], opora) > 0) {
                j--;
            }

            if (i <= j) {//меняем местами
                swap(array, i, j);
                i++;
                j--;
            }
        }

        // вызов рекурсии для сортировки левой и правой части
        if (low < j)
            quickSort(array, low, j);

        if (high > i)
            quickSort(array, i, high);
    }

    std::function<int(const T&, const T&, int &sortComparisons)> compareTo;
};