#pragma once
#include "Animal.h"
#include <vector>

static void insertionSort(std::vector<Animal*> &arr) {
  for (int i = 0; i < arr.size(); i++) { // i - номер текущего шага
    int pos = i;
    auto min = arr[i];
    // цикл выбора наименьшего элемента
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j]->getWeight() < min->getWeight()) {
        pos = j; // pos - индекс наименьшего элемента
        min = arr[j];
      }
    }
    arr[pos] = arr[i];
    arr[i] = min;
  }
}

