#include "Heap.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>


bool isHeap(const std::vector<int>& arr, int n) {
    for (auto i = 0; i <= (n - 2) / 2; i++) {
        if (arr[2 * i + 1] > arr[i])
        {
            return false;
        }
        if (2 * i + 2 < n && arr[2 * i + 2] > arr[i])
        {
            return false;
        }
    }
    return true;
}

int getRandomNumber(int min, int max) {
    return min + rand() % (max - min); //return rand() % (max - min + 1) + min;
}

void buildHeapTest(std::vector<int>& arr) { //void buildHeapTest(const std::vector<int>& arr)
    std::cout << "Heap build" << std::endl; //std::cout << "Heap build";
    Heap::buildHeapFromArray(arr);
    assert(isHeap(arr, arr.size() - 1));
}

///////////////////
class LowerPriority {
public:
    bool operator() (const Heap::TruckCoordinate& data_1, const Heap::TruckCoordinate& data_2) {
        return data_2 < data_1;
    }
};
std::vector<Heap::TruckCoordinate> closestTrucks(const std::vector<Heap::TruckCoordinate>& points, int k) {
     std::priority_queue<Heap::TruckCoordinate, std::vector<Heap::TruckCoordinate>, LowerPriority> priorityQueue; //std::priority_queue<Heap::TruckCoordinate> priorityQueue;
     for (auto& point : points){
         priorityQueue.push(point);
     }

     std::vector<Heap::TruckCoordinate> res;

     for (auto l = 0; !priorityQueue.empty() && l < k; l++)
     {
         res.push_back(priorityQueue.top());
         priorityQueue.pop();
     }
     return res;
}

void kClosestTrucksTest(const std::vector<int>& arr) {
    std::cout << "Find trucks" << std::endl;
    std::vector<Heap::TruckCoordinate> lst;
    for (int i = 0; i < arr[0]; ++i){      
      lst.push_back(Heap::TruckCoordinate{rand(), rand()});
    }

    auto ans = Heap::kClosestTrucks(lst, arr[1]);
    auto test = closestTrucks(lst, arr[1]);
    assert(ans.size() == test.size());
    for (auto& val : test){
        assert(std::find(ans.begin(), ans.end(), val) != ans.end());
    }
}

//////////////////////////
struct TruckTime {
    int id;
    long time = 0;

    TruckTime(int _id) : id(_id) {}
 };

 std::vector<int> handleTrucks(int n, const std::vector<int> &tasks) {
     auto cmp = [](TruckTime left, TruckTime right)
     {
         if (left.time == right.time)
             return left.id == right.id;
         return left.time > right.time; // return left.time < right.time;
     };
     std::priority_queue<TruckTime, std::vector<TruckTime>, decltype(cmp) > queue(cmp);

     if (n == 0 || tasks.empty()) return {}; // added code

     for (int i = 0; i < n; i++)
         queue.push(TruckTime(i));

     std::vector<int> records;

     for (int task : tasks)
     {
         auto truckTime = queue.top();
         records.push_back(truckTime.time);
         truckTime.time += task;
         queue.pop(); // added code
         queue.push(truckTime);
     }
     return records;
 }

void unloadedTrucksTest() {
    std::cout << "Unloading trucks";
    auto n = getRandomNumber(0, 50);
    auto size = getRandomNumber(0, 1000);
    std::vector<int> lst(size);
    std::generate(lst.begin(), lst.end(), []() { return getRandomNumber(0, 1000); });

    auto ans = Heap::unloadingTruck(n, lst);
    auto test = handleTrucks(n, lst);
    assert(ans.size() == test.size());
    for (auto& val : test) {
        assert(std::find(ans.begin(), ans.end(), val) != ans.end());
    }
}

int main() {
    buildHeapTest(std::vector<int> {1, 2, -1}); // buildHeapTest({1, 2, -1});
    buildHeapTest(std::vector<int> {}); // buildHeapTest({});
    buildHeapTest(std::vector<int> {1}); // buildHeapTest({1});
    buildHeapTest(std::vector<int> {5, 6, 3, 2, 7, 9, 10, 4, 10});
    std::vector<int> vec(100000);
    std::generate(vec.begin(), vec.end(), [](){ return rand();});
    buildHeapTest(vec);

    kClosestTrucksTest({1, 1});
    kClosestTrucksTest({100, 5});
    kClosestTrucksTest({1000, 5});
    kClosestTrucksTest({10, 500});
    kClosestTrucksTest({10000, 500});

    unloadedTrucksTest();
    return 0;
}