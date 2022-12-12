#pragma once

#include <vector>
#include <ctime>

namespace HomeworkCheck::WorkPlanner {

	using namespace std;

	size_t FindMaximumIncome(const vector<size_t>& workRates, size_t k);

	size_t FindMinimumManagers(const vector<pair<time_t, time_t>>& intervals);

	using TruckCapacity = size_t;
	using GoodsPrice = size_t;
	using GoodsCount = size_t;
	using PricePerOne = double;
	using GoodsInfo = pair<GoodsCount, GoodsPrice>;
	double LoadTruck(TruckCapacity truckCapacity, const vector<GoodsInfo>& goods);
}