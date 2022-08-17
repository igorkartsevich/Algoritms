#include <algorithm>
#include <gtest/gtest.h>
#include "TopX.h"

using std::pair;

vector<pair<vector<int>, int>> findTopElementsData = {
        {{10, 20, 30, 40}, 2},
        {{100, 100, 100, 55, 8}, 3},
        {{100, 100, 100, 55, 8}, 2},
        {{100, 55, 8, 100, 100}, 4},
        {{0, 0, 0, 0}, 4},
        {{10}, 1},
        {{-1, -2, -3, -4, -4, -5, -100, 100, 1, 2, 3, 4, 5}, 1},
        {{-1, -2, -3, -4, -4, -5, -100, 100, 1, 2, 3, 4, 5}, 3},
        {{-1, -2, -3, -4, -4, -5, -100, 100, 1, 2, 3, 4, 5}, 5},
        {{-1, -2, -3, -4, -4, -5, -100, 100, 1, 2, 3, 4, 5}, 13},
        {{40, 50, 60, 10, 20, 30, 70, 80}, 3},
        {{40, 50, 60, 10, 20, 30, 70, 80}, 6}
};

TEST(TopXTest, FindTopElementsTest) {
    for (pair<vector<int>, int> data : findTopElementsData) {
        vector<int> ans = findTopElements(data.first, data.second);
        vector<int> correct = data.first;
        sort(correct.rbegin(), correct.rend());
        correct.resize(data.second);
        EXPECT_EQ(ans, correct);
    }
}

TEST(TopXTest, FindBottomElementsTest) {
    for (pair<vector<int>, int> data : findTopElementsData) {
        vector<int> ans = findBottomElements(data.first, data.second);
        vector<int> correct = data.first;
        sort(correct.begin(), correct.end());
        correct.resize(data.second);
        EXPECT_EQ(ans, correct);
    }
}
