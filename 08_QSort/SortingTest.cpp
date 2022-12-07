#include "Sorting.h"
#include<iostream>
#include <iomanip>

//create 3 constant values
int SIZE = 5000;//number of values in the lists
int SORTED_ORDER = 0;//for sorted lists
int RANDOM_ORDER = 1;//for unsorted lists

//create the lists for each sorting algorithm
std::vector<int> selArr(SIZE);
std::vector<int> insArr(SIZE);
std::vector<int> bubArr(SIZE);
std::vector<int> quiArr(SIZE);
std::vector<int> merArr(SIZE);


//initializes the lists with the same values
void initLists(int order) {
    int number;
    for (int i = 0; i < SIZE; i++) {
        if (order == SORTED_ORDER)
            number = i;
        else
            number = rand() % SIZE;

        selArr[i] = number;
        insArr[i] = number;
        bubArr[i] = number;
        quiArr[i] = number;
        merArr[i] = number;
    }
}

void sortLists(Sorting<int> &sorting) {
    sorting.selectionSort(selArr);
    sorting.insertionSort(insArr);
    sorting.bubbleSort(bubArr);
    sorting.quickSort(quiArr);
    sorting.mergeSort(merArr);
}

void printComparisonsAndExecutionTime(Sorting<int> sorting) {

   auto formatOut = [](const std::string& name, int val1, int val2) {
        std::cout << std::setw(15) << name << std::setw(15) << val1
            << std::setw(15) << val2 << std::endl;
   };

   std::cout << "----------------------" << std::endl;  
   std::cout << std::setw(15) << "SORTING METHOD";
   std::cout << std::setw(15) << "COMPARISONS";
   std::cout << std::setw(15) << "EXEC.TIME(ms)" << std::endl;
   std::cout << "----------------------" << std::endl;
   formatOut("Selection sort", sorting.selectionSortComparisons, sorting.selectionSortExecutionTime);
   formatOut("Insertion sort", sorting.insertionSortComparisons, sorting.insertionSortExecutionTime);
   formatOut("Bubble sort", sorting.bubbleSortComparisons, sorting.bubbleSortExecutionTime);
   formatOut("Quick sort", sorting.quickSortComparisons, sorting.quickSortExecutionTime);
   formatOut("Merge sort", sorting.mergeSortComparisons, sorting.mergeSortExecutionTime);
   std::cout << "-----------------------" << std::endl;
   std::cout << std::endl;
}

static void performSorting(int order) {
    if (order == SORTED_ORDER)//display if the lists are in sorted order or not
        std::cout << "Sorted Lists..." << std::endl;
    else
        std::cout << "Unsorted Lists..." << std::endl;
    //create new sorter
    Sorting<int> sorting;

    //initialize the lists in sorted order
    initLists(order);

    //sort the lists
    sortLists(sorting);

    //display the number of comparisons and total execution time
    printComparisonsAndExecutionTime(sorting);
}

int main() {
  performSorting(SORTED_ORDER);
  performSorting(RANDOM_ORDER);
  performSorting(RANDOM_ORDER);
  std::cout << "All tests passed successfully! Congrats";
  return 0;
}