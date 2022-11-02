#pragma once
#include <vector>

static void countingSort(std::vector<int> &arr, int maxValue) {
  std::vector<int> numCounts(maxValue + 1, 0);
  for (int num : arr) {
    numCounts[num]++;
  }
  int currentSortedIndex = 0;
  for (int n = 0; n < numCounts.size(); n++) {
    int count = numCounts[n];
    for (int k = 0; k < count; k++) {
      arr[currentSortedIndex] = n;
      currentSortedIndex++;
    }
  }
}

