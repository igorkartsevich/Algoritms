#include "WorkPlanner.h"
#include "..\Task9\WorkPlanner.h"
#include <set>
#include <map>
#include <iostream>

namespace TaskWorkPlanner {

    size_t FindMaximumIncome(const std::vector<size_t>& workRates, size_t hours) {
        if (hours == 0) return 0;
        std::multiset<int> ratesSet(begin(workRates), end(workRates));
        size_t profit{};

        for (auto it = rbegin(ratesSet); it != rend(ratesSet); ++it, --hours)
            if (hours > 0)
                profit += *it;
            else
                break;

        return profit;
    }

    size_t FindMinimumManagers(const std::vector<std::pair<std::time_t, std::time_t>>& intervals) {
        if (intervals.size() == 0) return 0;

        std::multimap<int, int> mapIntervals(begin(intervals), end(intervals));

        auto searchNonUsedEarly = [&mapIntervals](std::multimap<int, int>::iterator& itNext) {
            while (itNext != end(mapIntervals) && itNext->second == 0)
                ++itNext;
        };

        auto checkToShortestInterval = [&mapIntervals](std::multimap<int, int>::iterator& itNext) {
            auto itTMP = itNext;
            while (++itTMP != end(mapIntervals) && itTMP->first < itNext->second) {
                if (itTMP->second != 0 && itTMP->second < itNext->second)
                    itNext = itTMP;
            }
        };

        size_t emploees{};
        auto itStart = begin(mapIntervals);

        while (itStart != end(mapIntervals)) {
            if (itStart->second != 0) {
                ++emploees; // if non-used meet is exist

                auto itPrev = itStart;
                auto itNext = mapIntervals.upper_bound(itPrev->second); // search next meet

                while (itNext != end(mapIntervals)) {
                    if (itNext->second == 0) // if meet already used search next non-used meet
                        searchNonUsedEarly(itNext);

                    if (itNext == end(mapIntervals)) // if there are no more unused meetings
                        break;
                    else
                        checkToShortestInterval(itNext); // search next and shortest meet

                    itPrev->second = 0; // mark meet as used
                    itPrev = itNext;
                    itNext = mapIntervals.upper_bound(itPrev->second); // search next meet
                }

                itPrev->second = 0; // mark meet as used
            }

            ++itStart;
        }

        return emploees;
    }

    double LoadTruck(size_t truckCapacity, const std::vector<std::pair<size_t, size_t>>& goods) {
        std::multimap<double, std::pair<size_t, size_t>> mapGoodsByUnitCost;

        for (auto good : goods)
            mapGoodsByUnitCost.emplace((double)good.second / good.first, good);

        double totalCost{};

        for (auto it = rbegin(mapGoodsByUnitCost); it != rend(mapGoodsByUnitCost); ++it) {
            if (int(truckCapacity - it->second.first) > 0) {
                truckCapacity -= it->second.first;
                totalCost += it->second.second;
            }
            else {
                totalCost += (double)truckCapacity / it->second.first * it->second.second;
                break;
            } 
        }

        return totalCost;
    }

}

