#include "WorkPlanner.h"
#include "..\TestTask9\WorkPlanner.h"
#include <set>
#include <map>
#include <algorithm>

namespace Homework::WorkPlanner {

    size_t FindMaximumIncome(const std::vector<size_t>& workRates, size_t hours) {
        std::multiset<int> ratesSet;
        for (auto rate : workRates)
            ratesSet.emplace(rate);

        size_t profit{};
        std::for_each(rbegin(ratesSet), (hours < ratesSet.size()) ? rbegin(ratesSet) + hours : rend(ratesSet),
            [&profit](int rate) { profit += rate; });

        return profit;
    }

    size_t FindMinimumManagers(const std::vector<std::pair<std::time_t, std::time_t>>& intervals) {
        if(intervals.size() == 0) return 0;

        using map_type = std::map<std::time_t, std::time_t>;
        map_type mapOfIntervals(begin(intervals), end(intervals));

        auto getIterator = [&mapOfIntervals](map_type::iterator it) {
            while (it != end(mapOfIntervals) && it->second == 0)
                ++it;
            return it;
        };

        auto mark_0_usedIntervals = [&mapOfIntervals, getIterator](map_type::iterator it) {
            while (it != end(mapOfIntervals)) {
                auto it_next = getIterator(mapOfIntervals.upper_bound(it->second));
                it->second = 0;
                it = it_next;
            }
        };

        size_t employees{};
        while (true) {
            auto start_it = getIterator(begin(mapOfIntervals));

            if (start_it != end(mapOfIntervals)) {
                ++employees;
                mark_0_usedIntervals(start_it);
            }

            else return employees;;
        }
    }

    double LoadTruck(size_t truckCapacity, const std::vector<std::pair<size_t, size_t>>& goods) {
        using map_type = std::multimap<double, std::pair<size_t, size_t>>;
        map_type mapGoods;

        for (auto good : goods)
            mapGoods.emplace(good.second / good.first, good);

        double cost{};
        auto it = rbegin(mapGoods);
        while (it != rend(mapGoods)) {
            if (int(truckCapacity - it->second.first) > 0) {
                truckCapacity -= it->second.first;
                cost += it->second.second;
                ++it;
            }
            else {
                cost += (double)truckCapacity / it->second.first * it->second.second;
                break;
            }
        }

        return cost;
    }

}

