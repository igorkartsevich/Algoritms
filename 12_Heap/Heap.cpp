#include "Heap.h"
#include <algorithm>

//****************************************

template<typename T>
void relocateUP(std::vector<T>& vector, int index, int indexToRelocate) {
    do {
        std::swap(vector[index], vector[indexToRelocate]);
        std::swap(index, indexToRelocate);
        indexToRelocate = (index - 1) >> 1;
    } while (indexToRelocate >= 0 && vector[indexToRelocate] < vector[index]);
};
void Heap::buildHeapFromArray(std::vector<int>& checks) {
    size_t size = checks.size();
    for (size_t index{1}; index < size; ++index) {
        size_t indexToRelocate = (index - 1) >> 1;
        if (checks[indexToRelocate] < checks[index]) relocateUP(checks, index, indexToRelocate);
    }
}

//****************************************

std::vector<Heap::TruckCoordinate> Heap::kClosestTrucks(const std::vector<Heap::TruckCoordinate>& truckCoordinateList, int k) {
    size_t sizeList = truckCoordinateList.size();
    size_t sizeResult = (k <= sizeList) ? k : sizeList;
    std::vector<TruckCoordinate> result(begin(truckCoordinateList), begin(truckCoordinateList) + sizeResult);
    
    auto lead_result_ToMaxHeap = [&result]() {
        size_t sizeReult = result.size();

        for (int index{ 1 }; index < sizeReult; ++index) {
            size_t indexToRelocate = (index - 1) >> 1;
            if (result[indexToRelocate] < result[index]) relocateUP(result, index, indexToRelocate);
        }
    };

    auto addNewToMaxHeap = [&result](Heap::TruckCoordinate newData) {
        int index{};
        size_t size = result.size();
        result[index] = newData;

        while (true) {
            if ((index << 1) + 2 >= size || (index << 1) + 1 >= size) return;
            else {
                int indexToRelocate = (result[(index << 1) + 1] < result[(index << 1) + 2])
                    ? (index << 1) + 2 : (index << 1) + 1;

                if (result[index] < result[indexToRelocate]) {
                    relocateUP(result, indexToRelocate, index);
                    index = indexToRelocate;
                }
                else return;
            }
        }
    };

    lead_result_ToMaxHeap();
    for (int i{ k }; i < sizeList; ++i)
        if(truckCoordinateList[i] < result[0]) addNewToMaxHeap(truckCoordinateList[i]);

    return result;
}

std::vector<int> Heap::unloadingTruck(int n, const std::vector<int>& times) {
    return std::vector<int>{};
}