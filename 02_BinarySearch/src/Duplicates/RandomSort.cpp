#include <vector>
#include <iostream>
#include <cassert>

bool myIsSorted(const std::vector<int>& array) {
    for (int i = 1; i < array.size(); ++i)
        if (array[i] < array[i - 1])
            return false;
    return true;
}

void RandomSort(std::vector<int>& array) {
    bool is_swapped = false;
    int first_index, second_index;

    do {
        first_index = rand() % array.size();
        do {
            second_index = rand() % array.size();
        } while (first_index == second_index);

        if (first_index < second_index && array[first_index] > array[second_index] ||
            first_index > second_index && array[first_index] < array[second_index])
                std::swap(array[first_index], array[second_index]);
        else is_swapped = false;

    } while (is_swapped);

    if (!myIsSorted(array)) RandomSort(array);
    else return;
}

int main(void) {
    srand(time(0));

    std::vector<int> a_1 = { 42, 12, 12, 38 };
    std::vector<int> res1 = { 12, 12, 38, 42 };
    RandomSort(a_1);
    assert(a_1 == res1);

    std::vector<int> a_2 = { 214, 21, 25, 10, 1, 2, 48, 12, 17, 125, 0, 13, 15, 18, 17, 154 };
    std::vector<int> res2 = { 0, 1, 2, 10, 12, 13, 15, 17, 17, 18, 21, 25, 48, 125, 154, 214 };
    RandomSort(a_2);
    assert(a_2 == res2);

    std::vector<int> a_3 = { 7, 7, 7, 7, 7, 1, 1, 1, 2, 12, 0, 0, 0 };
    std::vector<int> res3 = { 0, 0, 0, 1, 1, 1, 2, 7, 7, 7, 7, 7, 12 };
    RandomSort(a_3);
    assert(a_3 == res3);

    return 0;
}