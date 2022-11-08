#include "../../homework/SortAlgorithms/Animal.h"
#include "../../homework/SortAlgorithms/SuperArray.h"
#include "../../homework/SortAlgorithms/SortAlgorithms.h"

#include <algorithm>
#include <cassert>
#include <time.h>
#include <iostream>
#include <string>

class Arr : public SuperArray {
private:
    std::vector<int> array;
    int iteration = 0;

public:
    Arr(std::vector<int> array) : SuperArray() {
        this->array = array;
    };

    virtual ~Arr() {};

    virtual int getSize() override {
        return (int)array.size();
    }

    virtual int get(int position) override {
        return array[position];
    }

    virtual void set(int position, int value) override {
        iteration++;
        array[position] = value;
    }

    int getIteration() {
        return iteration;
    }
};

class ZooAnimal : public Animal {
private:
    int weight;
    std::string name;
public:
    ZooAnimal(int weight, std::string name) : Animal() {
        this->weight = weight;
        this->name = name;
    };
    virtual ~ZooAnimal() {};

    virtual int getWeight() override {
        return weight;
    }

    std::string toString() {
        return "ZooAnimal{weight=" + std::to_string(weight) + ", name='" + name + '\'' + '}';
    }

    static void sort(std::vector<Animal*>& array) {
        for (int left = 0; left < array.size(); left++) {
            Animal* value = array[left];
            int i = left - 1;
            for (; i >= 0; i--) {
                if (value->getWeight() < array[i]->getWeight()) {
                    array[i + 1] = array[i];
                }
                else {
                    break;
                }
            }
            array[i + 1] = value;
        }
    }
};


void bubbleSortTest() {
  std::cout << "Bubble sort" << std::endl;
  std::vector<std::vector<int>> bubbleSortData{
      std::vector<int>{334934939, 1234122, 657657},
      std::vector<int>{},
      std::vector<int>{1},
      std::vector<int>(10000)
  };
  for (size_t i = 0; i < 10000; ++i) {
      bubbleSortData[3][i] = rand();
  }
  auto testSort = [&bubbleSortData](int i) {
      std::vector<int> userArray(bubbleSortData[i]);
      std::sort(userArray.begin(), userArray.end());
      bubbleSort(bubbleSortData[i]);
      assert(bubbleSortData[i] == userArray);
  };
  for (size_t i = 0; i < bubbleSortData.size(); ++i) {
      testSort(i);
  }
}

void selectionSortTest() {
  std::cout << "Selection sort" << std::endl;
  std::vector<std::vector<int>> selectionSortData{
      std::vector<int>{3, 2, 1},
      std::vector<int>{},
      std::vector<int>{1},
      std::vector<int>(100)
  };
  for (size_t i = 99; i > 0; --i) {
      selectionSortData[3][i] = i;
  }
  auto testSort = [&selectionSortData](int i) {
      Arr* arr = new Arr(selectionSortData[i]);
      selectionSort(arr);
      assert((selectionSortData[i].size() - 1) * 2 >= arr->getIteration());
      delete arr;
  };
  for (size_t i = 0; i < selectionSortData.size(); ++i) {
      testSort(i);
  }
}

void insertionSortTest() {
  std::cout << "Insertion sort" << std::endl;
  std::vector<Animal*> arr{
     new ZooAnimal(100, "Zebra Fibi"),  new ZooAnimal(505, "Lion Gunter"),
     new  ZooAnimal(5, "Meerkat Joe"),  new ZooAnimal(100, "Zebra Monika"),
     new  ZooAnimal(50, "Deer Ross"),  new ZooAnimal(5, "Meerkat Chandler") };  
  auto userArr(arr);

  insertionSort(userArr);
  ZooAnimal::sort(arr);
  for (size_t i = 0; i < arr.size(); ++i) {
      auto z1 = dynamic_cast<ZooAnimal*>(arr[i])->toString();
      auto z2 = dynamic_cast<ZooAnimal*>(userArr[i])->toString();
      assert(z1 == z2);
  }
}

void countingSortTest() {
  std::cout << "Counting sort" << std::endl;
  std::vector<int> array(10000000);
  for (size_t i = 0; i < 10000000; ++i) {
    array[i] = rand() % 100 + 1;
  }
  auto userArray(array);

  auto start = clock();
  std::sort(array.begin(), array.end());
  auto quickSort = clock() - start;

  start = clock();
  countingSort(userArray, 100);
  auto countingSort = clock() - start;

  assert((quickSort / countingSort) > 2);
}

int main() {
    bubbleSortTest();
    selectionSortTest();
    insertionSortTest();
    countingSortTest();
    std::cout << "All tests for Sort_Test passed successfully! Congrats";

    return 0;
}