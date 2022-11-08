#include "SortAlgorithms.h"

void selectionSort(SuperArray* arr) {
	int size = (int)arr->getSize();

	for (int i{}; i < size - 1; ++i) {
		int min = arr->get(i);
		int minIndex{ -1 };
		for (int j{ i + 1 }; j < size; ++j) {
			if (arr->get(j) < min) {
				min = arr->get(j);
				minIndex = j;
			}
		}
		if (minIndex != -1 && arr->get(i) > arr->get(minIndex)) {
			int TMP = arr->get(i);
			arr->set(i, arr->get(minIndex));
			arr->set(minIndex, TMP);
		}
	}
}

void insertionSort(std::vector<Animal*>& arr) {
	int size = (int)arr.size();
	for (int i{ 1 }; i < size; ++i)
		for (int j{ i }; j > 0; --j)
			if (arr[j - 1]->getWeight() > arr[j]->getWeight())
				std::swap(arr[j - 1], arr[j]);
			else
				break;
}

void countingSort(std::vector<int>& arr, int maxValue) {
	std::vector<int> counters(maxValue + 1, 0);
	int size = (int)arr.size();

	for (int i{}; i < size; ++i)
		++counters[arr[i]];

	int counterNumber{};
	int i{};

	while (i < size) {
		if (counters[counterNumber] != 0)
			for (int j{}; j < counters[counterNumber]; ++j)
				arr[i++] = counterNumber;
		++counterNumber;
	}

	return;
}

void bubbleSort(std::vector<int>& arr) {
	int size = (int)arr.size();
	bool is_sorted = false;

	while (!is_sorted) {
		is_sorted = true;
		--size;
		for (int i{}; i < size; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				is_sorted = false;
			}
		}
	}
}