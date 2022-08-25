#include "ArrayUnique.h"

std::vector<char> lettersLearnedToday(std::string word) {
    std::vector<char> unique_letters;
    
    for (auto word_letter : word) {
        bool is_already_exist = false;

        for (auto unique_letter : unique_letters)
            if (word_letter == unique_letter) {
                is_already_exist = true;
                break;
            }

        if (!is_already_exist)
            unique_letters.emplace_back(word_letter);
    }

    return unique_letters; // please implement
}

//*******************************

int avoidJailDueToTaxFraud(std::vector<std::vector<int>> report) {
    auto total_size = 0;
    for (auto sub_report : report)
        total_size += sub_report.size();

    std::vector<int> total_report(total_size);

    int count = 0;
    for (auto sub_report : report)
        for (auto payment : sub_report)
            total_report[count++] = payment;

    for (int i = 0; i < total_size; ++i)
        for (int j = 0; j < total_size; ++j)
            if (total_report[i] == total_report[j] && i != j)
                return total_report[i];

    return -1;  // please implement
}