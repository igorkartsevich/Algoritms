#include "WorkPlanner.h"
#include "..\TestTask9\WorkPlanner.h"
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
        if(intervals.size() == 0) return 0;
        
        std::multimap<int, int> mapInterval(begin(intervals), end(intervals));

        auto searchNotUsedYet = [&](std::multimap<int, int>::iterator& itNext) {
            while (itNext != end(mapInterval) && itNext->second == 0)
                ++itNext;
        };

        auto checkToIntervalBetter = [&](std::multimap<int, int>::iterator& itNext) {
            auto itTMP = itNext;
            while (++itTMP != end(mapInterval) && itTMP->first < itNext->second) {
                if (itTMP->second != 0 && itTMP->second < itNext->second)
                    itNext = itTMP;
            }
        };

        size_t emploees{};
        auto itStart = begin(mapInterval);

        while (itStart != end(mapInterval)) {
            if (itStart->second != 0) {
                ++emploees;
                std::cout << "emploees N" << emploees << std::endl;
                std::cout << itStart->first << " " << itStart->second << std::endl;

                auto itPrev = itStart;
                auto itNext = mapInterval.upper_bound(itPrev->second);

                while (itNext != end(mapInterval)) {
                    if (itNext->second == 0)
                        searchNotUsedYet(itNext);

                    if (itNext == end(mapInterval))
                        break;
                    else
                        checkToIntervalBetter(itNext);

                    std::cout << itNext->first << " " << itNext->second << std::endl;
                    itPrev->second = 0;
                    itPrev = itNext;
                    itNext = mapInterval.upper_bound(itPrev->second);
                }

                itPrev->second = 0;
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

