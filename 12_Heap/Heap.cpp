#include "Heap.h"
#include <algorithm>

template<typename T>
void sift_UP_MAX(std::vector<T>& heap, int index) {
    int indexToSift = (index - 1) >> 1;
    if (indexToSift < 0) return;

    if (heap[indexToSift] < heap[index]) {
        std::swap(heap[index], heap[indexToSift]);
        sift_UP_MAX(heap, indexToSift);
    }
    else return;
}
void sift_DOWN_MAX(std::vector<Heap::TruckCoordinate>& heap, int index) {
    int indexLeft = (index << 1) + 1;
    if (indexLeft >= heap.size()) return;

    int indexRight = (index << 1) + 2;
    int indexToSift = (indexRight >= heap.size())
        ? indexLeft
        : (heap[indexLeft] < heap[indexRight]) ? indexRight : indexLeft;

    if (heap[index] < heap[indexToSift]) {
        std::swap(heap[index], heap[indexToSift]);
        sift_DOWN_MAX(heap, indexToSift);
    }
    else return;
}

//****************************************
void Heap::buildHeapFromArray(std::vector<int>& checks) {
    auto size = checks.size();
    for (int index{1}; index < size; ++index)
        sift_UP_MAX(checks, index);

    return;
}

//****************************************
std::vector<Heap::TruckCoordinate> Heap::kClosestTrucks(const std::vector<Heap::TruckCoordinate>& truckCoordinateList, int k) {
    auto sizeInput = truckCoordinateList.size();
    int sizeResult = (sizeInput > k) ? k : sizeInput;
    std::vector<Heap::TruckCoordinate> result(begin(truckCoordinateList), begin(truckCoordinateList) + sizeResult);
    
    for (int index{ 1 }; index < sizeResult; ++index)
        sift_UP_MAX(result, index);

    for (int index{ sizeResult }; index < sizeInput; ++index) {
        if (truckCoordinateList[index] < result[0]) {
            result[0] = truckCoordinateList[index];
            sift_DOWN_MAX(result, 0);
        }
    }
    return result;
}

//***************************************
struct UnloadingUnit {
    int storageNumber;
    int unloadingTime;
};

void setHeap(std::vector<UnloadingUnit>& heap, int k) {
    for (int i{}; i < heap.size(); ++i) {
        heap[i].storageNumber = i * k;
        heap[i].unloadingTime = 0;
    }
}

void siftUP_byTime(std::vector<UnloadingUnit>& heap, size_t index) {
    size_t indexToSift = (index - 1) >> 1;
    if (index == 0 || indexToSift < 0) return;
    if (heap[index].unloadingTime < heap[indexToSift].unloadingTime) {
        std::swap(heap[index], heap[indexToSift]);
        siftUP_byTime(heap, indexToSift);
    }
    else return;
}

void siftDOWN_byStorage(std::vector<UnloadingUnit>& heap, size_t index, size_t border) {
    int indexLeft = (index << 1) + 1;
    if (indexLeft >= border) return;
    
    int indexRight = indexLeft + 1;
    int indexToSift = (indexRight >= border) ? indexLeft
        : (heap[indexLeft].storageNumber < heap[indexRight].storageNumber) ? indexLeft : indexRight;

    if (heap[indexToSift].storageNumber < heap[index].storageNumber) {
        std::swap(heap[index], heap[indexToSift]);
        siftDOWN_byStorage(heap, indexToSift, border);
    }
    else return;
}

void siftUP_byStorage(std::vector<UnloadingUnit>& heap, size_t index) {
    size_t indexToSift = (index - 1) >> 1;
    if (index == 0 || indexToSift < 0) return;

    if (heap[index].storageNumber < heap[indexToSift].storageNumber) {
        std::swap(heap[index], heap[indexToSift]);
        siftUP_byStorage(heap, indexToSift);
    }
    else return;
}

void siftDOWN_byTime(std::vector<UnloadingUnit>& heap, size_t index, size_t border) {
    int indexLeft = (index << 1) + 1;
    if (indexLeft >= border) return;

    int indexRight = indexLeft + 1;
    int indexToSift = (indexRight >= border) ? indexLeft
        : (heap[indexLeft].unloadingTime < heap[indexRight].unloadingTime) ? indexLeft : indexRight;

    if (heap[indexToSift].unloadingTime < heap[index].unloadingTime) {
        std::swap(heap[index], heap[indexToSift]);
        siftDOWN_byTime(heap, indexToSift, border);
    }
    else return;
}

std::vector<int> Heap::unloadingTruck(int n, const std::vector<int>& times) {
    if (n == 0 || times.empty()) return{};

    int globalTime{};
    std::vector<int> result;

    std::vector<UnloadingUnit> heapFreeStorage(n);
    setHeap(heapFreeStorage, 1);
    std::vector<UnloadingUnit> heapBuzyStorage;

    size_t timesCount{};
    while (true) {
        while(!heapFreeStorage.empty()) {
            heapFreeStorage[0].unloadingTime = times[timesCount++];
            result.push_back(globalTime);

            if (timesCount == times.size()) return result;

            heapBuzyStorage.push_back(heapFreeStorage[0]);
            siftUP_byTime(heapBuzyStorage, heapBuzyStorage.size() - 1);

            heapFreeStorage[0] = heapFreeStorage.back();
            siftDOWN_byStorage(heapFreeStorage, 0, heapFreeStorage.size() - 1);
            heapFreeStorage.pop_back();
        }

        int timeJump = heapBuzyStorage[0].unloadingTime;
        for (auto& node : heapBuzyStorage)
            node.unloadingTime -= timeJump;
        globalTime += timeJump;

        while (!heapBuzyStorage.empty() && heapBuzyStorage[0].unloadingTime == 0) {
            heapFreeStorage.push_back(heapBuzyStorage[0]);
            siftUP_byStorage(heapFreeStorage, heapFreeStorage.size() - 1);

            heapBuzyStorage[0] = heapBuzyStorage.back();
            siftDOWN_byTime(heapBuzyStorage, 0, heapBuzyStorage.size() - 1);
            heapBuzyStorage.pop_back();
        }
    }

}