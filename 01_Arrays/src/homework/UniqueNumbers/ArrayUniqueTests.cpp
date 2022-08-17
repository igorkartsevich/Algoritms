#include <algorithm>
#include <gtest/gtest.h>

#include "ArrayUnique.h"



vector<vector<vector<int>>> taxFraudTestData = {
        {
                {12391203, 3828382, 334934939},
                {45345345, 5341312, 55345345},
                {334934939, 1234122, 657657},
        },
        {
                {1,        1,       1},
                {1,        1,       1}
        },
        {
                {1,        2,       3},
                {4,        5,       6},
        }
};

vector<int> taxFraudAns = {334934939, 1, -1};

vector<string> uniqLettersData = {"АААФФФФФФФЖЫЫЫЫБЫРВАААААЛГГГХЫХЫБЛИА", "ОК", "СКИЛЛБОКСТОПЧИК", "ААААААААА"};


TEST(UniqueNumbersTest, TexFraudTest) {
    for (int i = 0; i < taxFraudTestData.size(); ++i) {
        int ans = avoidJailDueToTaxFraud(taxFraudTestData[i]);
        EXPECT_EQ(ans, taxFraudAns[i]);
    }
}

TEST(UniqueNumbersTest, LettersLearnedTest) {
    for (auto s : uniqLettersData) {
        vector<char> ans = lettersLearnedToday(s);
        sort(s.begin(), s.end());
        s.resize(unique(s.begin(), s.end()) - s.begin());
        sort(ans.begin(), ans.end());
        EXPECT_EQ(ans, vector<char>(s.begin(), s.end()));
    }
}
