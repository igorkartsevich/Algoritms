#pragma once

#include <vector>
#include <ctime>

namespace TaskWorkPlanner {

	size_t FindMaximumIncome(const std::vector<size_t>& workRates, size_t k);

	size_t FindMinimumManagers(const std::vector<std::pair<std::time_t, std::time_t>>& intervals);

	double LoadTruck(size_t truckCapacity, const std::vector<std::pair<size_t, size_t>>& goods);

}