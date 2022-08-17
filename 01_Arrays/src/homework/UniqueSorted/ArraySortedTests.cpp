#include <algorithm>
#include <gtest/gtest.h>

#include "ArraySorted.h"



vector<vector<long long>> phoneNumberData = {
        {
                79000000000LL,
                79000000000LL,
                79000000001LL,
                79000000002LL,
                79000000002LL,
                79000000003LL,
                79000000003LL,
                79000000003LL,
                79000000003LL,
                79000000004LL
        },
        {
                88005553535LL
        },
        {
                88005553535LL,
                88005553535LL,
                88005553535LL,
                88005553535LL,
                88005553535LL,
                88005553535LL,
        },
        {
            1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 9, 9, 10, 11, 11
        }
};

vector<vector<pair<long long, int>>> phoneNumberAns = {
        {
                { 79000000000LL, 2},
                { 79000000001LL, 1},
                { 79000000002LL, 2},
                { 79000000003LL, 4},
                { 79000000004LL, 1}
        },
        {
                { 88005553535LL, 1}
        },
        {
                { 88005553535L, 6}
        },
        {
                {1, 1},
                {2, 1},
                {3, 1},
                {4, 1},
                {5, 1},
                {6, 1},
                {7, 1},
                {8, 3},
                {9, 3},
                {10, 1},
                {11, 2}
        }
};

vector<string> coinsData = {
        "BTC:42\n"
        "BTC:600\n"
        "BTC:900\n"
        "DOGE:123456\n"
        "DOGE:69420\n"
        "ETH:220\n"
        "ETH:666\n"
        "XMR:14\n"
        "XMR:88\n"
        "XMZ:88",
        "BTC:1999"

};
vector<vector<pair<string, int>>> coinsAns = {
        {
                {"BTC", 1542},
                {"DOGE", 192876},
                {"ETH", 886},
                {"XMR", 102},
                {"XMZ", 88}
        },
        {
                {"BTC", 1999}
        }
};

TEST(UniqueSortedTest, phoneNumbersTest) {
    for (int i = 0; i < phoneNumberData.size(); ++i) {
        vector<pair<long long, int>> ans = groupPhoneNumbers(phoneNumberData[i]), correct = phoneNumberAns[i];
        sort(ans.begin(), ans.end());
        sort(correct.begin(), correct.end());
        EXPECT_EQ(correct, ans);
    }
}

TEST(UniqueSortedTest, CryptoCurrencyTest) {
    for (int i = 0; i < coinsData.size(); ++i) {
        vector<pair<string, int>> ans = cryptoCurrencyAnalysis(coinsData[i]), correct = coinsAns[i];
        sort(ans.begin(), ans.end());
        sort(correct.begin(), correct.end());
        EXPECT_EQ(correct, ans);
    }
}
