#include "WorkPlanner.h"
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

namespace TestWorkPlanner {

	using namespace std;

	size_t FindMaximumIncome(const vector<size_t>& workRates, size_t k) {
		if (!k) return 0;
		size_t ret = 0;
		multiset<size_t, greater<size_t>> rates(workRates.begin(), workRates.end());
		for (auto it = rates.begin(); it != rates.end() && k-- > 0; ret += *(it++));
		return ret;
	}

	size_t FindMinimumManagers(const vector<pair<time_t, time_t>>& intervals) {
		if (!intervals.size()) return 0;
		multimap<time_t, time_t> rates;
		for_each(intervals.begin(), intervals.end(), [&rates](auto it) {rates.insert({ it.first,it.second }); });
		size_t count = 0;
		auto it = rates.begin();
		while (it != rates.end()) {
			size_t res = 1;
			auto next = it;
			while (++next != rates.end()) {
				if (next->first < it->second) {
					++res;
				}
				else break;
			}
			count = max(count, res);
			++it;
		}
		return count;
	}

	double LoadTruck(TruckCapacity truckCapacity, const vector<GoodsInfo>& goods) {
		multimap<PricePerOne, GoodsCount, greater<PricePerOne>> rates;
		for_each(goods.begin(), goods.end(), [&rates](auto it) {
			rates.insert({ PricePerOne(it.second) / it.first,it.first });
			});
		double ret = 0.0;
		auto it = rates.begin();
		while (it != rates.end()) {
			if (truckCapacity <= it->second) {
				ret += truckCapacity * it->first;
				break;
			}
			ret += it->first * it->second;
			truckCapacity -= it->second;
			++it;
		}
		return ret;
	}
}