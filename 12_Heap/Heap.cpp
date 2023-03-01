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
enum SiftBy_Type {
    BY_STORAGE,
    BY_TIME
};

struct UnloadingUnit {
    int storageNumber;
    int unloadingTime;
};

void siftUP(std::vector<UnloadingUnit>& heap, size_t index, SiftBy_Type type) {
    size_t indexToSift = (index - 1) >> 1;
    if (index == 0 || indexToSift < 0) return;

    bool compare = (type == BY_STORAGE)
        ? heap[index].storageNumber < heap[indexToSift].storageNumber
        : heap[index].unloadingTime < heap[indexToSift].unloadingTime;

    if (compare) {
        std::swap(heap[index], heap[indexToSift]);
        siftUP(heap, indexToSift, type);
    }
    else return;
}

void siftDOWN(std::vector<UnloadingUnit>& heap, size_t index, size_t border, SiftBy_Type type) {
    int indexLeft = (index << 1) + 1;
    if (indexLeft >= border) return;
    
    int indexRight = indexLeft + 1;
    int indexToSift;

    if (indexRight >= border)
        indexToSift = indexLeft;
    else {
        bool compare = (type == BY_STORAGE)
            ? heap[indexLeft].storageNumber < heap[indexRight].storageNumber
            : heap[indexLeft].unloadingTime < heap[indexRight].unloadingTime;
        
        indexToSift = (compare) ? indexLeft : indexRight;
    }

    bool compare = (type == BY_STORAGE)
        ? heap[indexToSift].storageNumber < heap[index].storageNumber
        : heap[indexToSift].unloadingTime < heap[index].unloadingTime;

    if (compare) {
        std::swap(heap[index], heap[indexToSift]);
        siftDOWN(heap, indexToSift, border, type);
    }
    else return;
}

std::vector<int> Heap::unloadingTruck(int n, const std::vector<int>& times) {
    if (n == 0 || times.empty()) return{};

    int globalTime{};
    std::vector<int> result;

    std::vector<UnloadingUnit> heapFreeStorage(n);
    for (int i{}; i < heapFreeStorage.size(); ++i) {
        heapFreeStorage[i].storageNumber = i;
        heapFreeStorage[i].unloadingTime = 0;
    }

    std::vector<UnloadingUnit> heapBuzyStorage;

    size_t timesCount{};
    while (true) {
        while(!heapFreeStorage.empty()) {
            heapFreeStorage[0].unloadingTime = times[timesCount++];
            result.push_back(globalTime);

            if (timesCount == times.size()) return result;

            heapBuzyStorage.push_back(heapFreeStorage[0]);
            siftUP(heapBuzyStorage, heapBuzyStorage.size() - 1, BY_TIME);

            heapFreeStorage[0] = heapFreeStorage.back();
            siftDOWN(heapFreeStorage, 0, heapFreeStorage.size() - 1, BY_STORAGE);
            heapFreeStorage.pop_back();
        }

        int timeJump = heapBuzyStorage[0].unloadingTime;
        for (auto& node : heapBuzyStorage)
            node.unloadingTime -= timeJump;
        globalTime += timeJump;

        while (!heapBuzyStorage.empty() && heapBuzyStorage[0].unloadingTime == 0) {
            heapFreeStorage.push_back(heapBuzyStorage[0]);
            siftUP(heapFreeStorage, heapFreeStorage.size() - 1, BY_STORAGE);

            heapBuzyStorage[0] = heapBuzyStorage.back();
            siftDOWN(heapBuzyStorage, 0, heapBuzyStorage.size() - 1, BY_TIME);
            heapBuzyStorage.pop_back();
        }
    }
}