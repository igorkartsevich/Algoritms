#pragma once
#include "SuperArray.h"
#include "Animal.h"
#include <vector>

void selectionSort(SuperArray* arr);

void insertionSort(std::vector<Animal*>& arr);

void countingSort(std::vector<int>& arr, int maxValue);

void bubbleSort(std::vector<int>& arr);