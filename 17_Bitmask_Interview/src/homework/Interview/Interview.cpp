#include "Interview.h"
#include <unordered_set>

bool Interview::findSubarray(const std::vector<int>& a, int S) {
    int sum{};
    std::unordered_set<int> set;

    for (auto& node : a) {
        if (set.count((sum += node) - S)) return true;
        set.insert(sum);
    }
    return false;
}

void Interview::rotateMatric(std::vector<std::vector<int>>& a) {
    size_t circleToMoveNum{ a.size() >> 1 };
    size_t nodeToMoveNum{ a.size() - 1 };


    for (size_t circleNum{}; circleNum < circleToMoveNum; ++circleNum) {

        for (size_t nodeNum{}; nodeNum < (nodeToMoveNum - (circleNum << 1)); ++nodeNum) {
            size_t cur_X{ circleNum };
            size_t cur_Y{ nodeNum + circleNum };
            size_t turnCounter{3};

            do {
                size_t next_X{ cur_Y };
                size_t next_Y{ nodeToMoveNum - cur_X };

                std::swap(a[cur_X][cur_Y], a[next_X][next_Y]);

                std::swap(cur_X, next_X);
                std::swap(cur_Y, next_Y);

            } while (--turnCounter != 0);
        }
    }
}
