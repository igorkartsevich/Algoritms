#include "ArraySorted.h"

std::vector<std::pair<long long, int>> groupPhoneNumbers(std::vector<long long> phoneNumbers) {
    std::vector<std::pair<long long, int>> ans;
    long long previous_number = phoneNumbers[0];
    int counter = 0;

    for (auto phoneNumber : phoneNumbers) {
        
        if (phoneNumber == previous_number)
            ++counter;
        else {
            ans.push_back({ previous_number, counter });
            previous_number = phoneNumber;
            counter = 1;
        }
    }

    ans.push_back({ previous_number, counter });
    return ans;
}

//*******************************

std::vector<std::pair<std::string, int>> cryptoCurrencyAnalysis(std::string fileContents) {
    std::vector<std::pair<std::string, int>> res;
    bool is_name = true;
    std::string name = "";
    std::string cost = "";

    auto makeRecord = [&res](std::string name, int cost) {
        int size = res.size();
        for (auto i = 0; i < size; ++i) {
            if (res[i].first == name) {
                res[i].second += cost;
                return;
            }
        }

        res.emplace_back(std::make_pair(name, cost));
        return;
    };

    for (auto simbol : fileContents) {

        if (is_name) {
            if (simbol != ':')
                name += simbol;
            else
                is_name = !is_name;
        }
        else {
            if (simbol != '\n')
                cost += simbol;
            else {
                makeRecord(name, std::stoi(cost));
                name = cost = "";
                is_name = !is_name;
            }
        }
    }

    makeRecord(name, std::stoi(cost));

    return res;
}