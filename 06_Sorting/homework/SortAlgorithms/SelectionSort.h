#pragma once
#include "SuperArray.h"

static void
selectionSort(SuperArray* arr) {
  for (int i = 0; i < arr->getSize(); i++) {
    int pos = i;
    int min = arr->get(i);
    for (int j = i + 1; j < arr->getSize(); j++) {
      if (arr->get(j) < min) {
        pos = j;
        min = arr->get(j);
      }
    }
    arr->set(pos, arr->get(i));
    arr->set(i, min);
  }
}
