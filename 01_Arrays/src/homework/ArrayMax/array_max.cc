#include "array_max.h"
#include <cmath>

namespace ArrayMax {

// Task #1
int findSmallestTransaction(std::vector<int> transactions) {
    int current_max = INT_MIN;
    for (auto element : transactions)
        current_max = std::max(element, current_max);

    return current_max; // Please implement
}

// Task #2
int findBestStudentMistakes(std::vector<int> students) {
    int current_min = INT_MAX;
    for (auto element : students)
        current_min = std::min(element, current_min);

    return current_min; // Please implement
}

// Task #3
double findAverageTime(std::vector<int> times) {
    double accum = 0;
    for (auto time : times)
        accum += time;
    
    return accum / times.size(); // Please implement
}

// Task #4
int findMostProfitableClient(std::vector<std::vector<int>> income) {
    double max_profit_perDay = DBL_MIN;
    int most_profit_customer_index = 0,
        current_customer_index = 0;

    for (auto customer : income) {
        double total_profit = 0;

        for (auto day_profit : customer)
            total_profit += day_profit;

        double current_profit_perDay = total_profit / customer.size();

        if (current_profit_perDay > max_profit_perDay) {
            max_profit_perDay = current_profit_perDay;
            most_profit_customer_index = current_customer_index;
        }

        ++current_customer_index;
    }

    return most_profit_customer_index; // Please implement
}
} // namespace ArrayMax
