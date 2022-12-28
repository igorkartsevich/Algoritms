#include "WorkPlanner.h"
#include "..\TestTask9\WorkPlanner.h"
#include <set>
#include <map>

namespace TaskWorkPlanner {

    size_t FindMaximumIncome(const std::vector<size_t>& workRates, size_t hours) {
        if (hours == 0) return 0;
        std::multiset<int> ratesSet(begin(workRates), end(workRates));
        size_t profit{};

        for (auto it = rbegin(ratesSet); it != rend(ratesSet); ++it)
            if (hours-- > 0)
                profit += *it;
            else
                break;

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

        auto getSetIntervals = [&mapOfIntervals, getIterator](map_type::iterator it) {
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
                getSetIntervals(start_it);
            }

            else return employees;;
        }
    }

    /*double LoadTruck(size_t truckCapacity, const std::vector<std::pair<size_t, size_t>>& goods) {
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
    }*/

}

