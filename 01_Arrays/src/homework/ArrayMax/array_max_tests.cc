#include <algorithm>
#include <vector>
#include <climits>
#include <gtest/gtest.h>
#include "array_max.h"

using std::vector;
using std::sort;
const vector<vector<int>> smallestTransactionData = {
        {-1000, -100, -10, -1},
        {-1000},
        {-1000, -100, -10, -1, -1},
        {-1000, -100, -10, -1, -1, 0},
        {INT_MIN}
};

TEST(ArrayMaxTest, SmallestTransactionTest) {
    for (vector<int> v : smallestTransactionData) {
        int ans = ArrayMax::findSmallestTransaction(v);
        sort(v.begin(), v.end());
        EXPECT_EQ(ans, v.back());
    }
}

const vector<vector<int>> findBestStudentMistakesData = {
    {9, 4, 1, 8, 7, 13, 6, 5},
    {1000},
    {9, 4, 1, 8, 7, 13, 6, 5, 1, 1, 1, 1, 1},
    {9, 4, 1, 8, 7, 13, 6, 5, 0},
    {INT_MAX}
};

TEST(ArrayMaxTest, FindBestStudentMistakesTest) {
    for (vector<int> v : findBestStudentMistakesData) {
        int ans = ArrayMax::findBestStudentMistakes(v);
        sort(v.begin(), v.end());
        EXPECT_EQ(ans, v.front());
    }
}

const vector<vector<int>> findAverageTimeData = {
        {9999},
        {9, 4, 1, 8, 7, 9, 4, 1, 8, 7, 8, 7, 18, 3, 13, 6, 5},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}
};

TEST(ArrayMaxTest, FindAverageTimeTest) {
    for (const vector<int>& v : findAverageTimeData) {
        double ans = ArrayMax::findAverageTime(v);
        double sum = 0;
        for (int x : v) {
            sum += x;
        }
        sum /= v.size();
        EXPECT_NEAR(ans, sum, 1e-9);
    }
}
const vector<vector<vector<int>>> findMostProfitableClientData = {
    {
        {11, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {12, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {13, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {14, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {15, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {16, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {17, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {18, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {19, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {10, 2, 3, 4, 5, 6, 7, 8, 9, 0}
    },
    {
        {6, INT_MAX, INT_MIN},
        {1, 2, 3},
    },
    {
        {1, 9999, -10},
        {1},
    },
    {
        {95, 67, 13, 55, 44, 11, 10},
        {7, 190, 4, 44, 11, 1, 99},
        {0, 5, -1, 500, 14, 90, 1},
    },
    {
        {6, INT_MAX},
        {1, 2, 3},
    }
};

const vector<int> findMostProfitableClientAns = {
        8, 1, 0, 2, 0
};

TEST(ArrayMaxTest, FindMostProfitableClient) {
    int i = 0;
    for (const vector<vector<int>>& v : findMostProfitableClientData) {
        int ind = ArrayMax::findMostProfitableClient(v);
        EXPECT_EQ(ind, findMostProfitableClientAns[i]);
        i++;
    }
}