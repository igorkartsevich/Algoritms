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
        /*realization*/
        selectionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
    }


    void insertionSort(std::vector<T>& data)
    {
        auto startTime = clock();
        /*realization*/
        insertionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
    }

    void bubbleSort(std::vector<T>& data)
    {
        auto startTime = clock();
        /*realization*/
        bubbleSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
    }

    void mergeSort(std::vector<T>& data)
    {
        auto startTime = clock();
        /*realization*/
        selectionSortExecutionTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
    }

    void quickSort(std::vector<T>& data)
    {
        auto startTime = clock();
        /*realization*/
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