#include "Sorting.h"

template<typename T>
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
}