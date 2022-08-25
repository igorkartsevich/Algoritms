#include <vector>
#include <climits>
#include <algorithm>

#include "TopX.h"

int findMaxUnderBoundary(std::vector<int>& inp, int topBoundary) {
    int curr_max = INT_MIN,
        curr_index_to_MAX = 0,
        curr_index = 0;

    for (auto element : inp)
    {
        if (element <= topBoundary && element > curr_max) {
            curr_max = element;
            curr_index_to_MAX = curr_index;
        }

        ++curr_index;
    }

    inp[curr_index_to_MAX] = INT_MAX;
    return curr_max;
}

std::vector<int> findTopElements(const std::vector<int>& inp, int numberOfElements) {
    std::vector<int> res;
    std::vector<int> inp_mirror(inp);
    int previousMax = INT_MAX;

    for (int i = 0; i < numberOfElements; i++) {
        int currentMax = findMaxUnderBoundary(inp_mirror, previousMax);
        previousMax = currentMax;
        res.emplace_back(currentMax);
    }
    return res;
}

//*******************************

int findMinUpperBoundary(std::vector<int>& inp, int topBoundary) {
    int curr_min = INT_MAX,
        curr_index_to_MIN = 0,
        curr_index = 0;

    for (auto element : inp)
    {
        if (element >= topBoundary && element < curr_min) {
            curr_min = element;
            curr_index_to_MIN = curr_index;
        }

        ++curr_index;
    }

    inp[curr_index_to_MIN] = INT_MIN;
    return curr_min;
}

std::vector<int> findBottomElements(const std::vector<int>& inp, int numberOfElements) {
    std::vector<int> res;
    std::vector<int> inp_mirror(inp);
    int previousMin = INT_MIN;

    for (int i = 0; i < numberOfElements; i++) {
        int currentMin = findMinUpperBoundary(inp_mirror, previousMin);
        previousMin = currentMin;
        res.emplace_back(currentMin);
    }
    return res;
}
