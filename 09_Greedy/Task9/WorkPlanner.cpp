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
        size_t emploees{};

        std::multimap<int, int> mapInterval(begin(intervals), end(intervals));
        auto itStart = begin(mapInterval);

        while (itStart != end(mapInterval)) {
            if (itStart->second != 0) {
                ++emploees;
                
                auto itPrev = itStart;
                while (true) {
                    auto itNext = mapInterval.upper_bound(itPrev->second);

                    if (itNext == end(mapInterval)) {
                        itPrev->second = 0;
                        break;
                    }
                    
                    if (itNext->second == 0)
                        while (itNext->second == 0 && itNext != end(mapInterval))
                            ++itNext;

                    auto itTMP = itNext;
                    ++itTMP;
                    while (itTMP->second != 0 && itTMP->first < itNext->second) {
                        if (itTMP->second < itNext->second)
                            itNext = itTMP;
                        ++itTMP;
                    }

                    itPrev->second = 0;
                    itPrev = itNext;
                }
            }

            ++itStart;
        }

        return emploees;
    }

    double LoadTruck(size_t truckCapacity, const std::vector<std::pair<size_t, size_t>>& goods) {
        using map_type = std::multimap<double, std::pair<size_t, size_t>>;
        map_type mapGoods;

        for (auto good : goods)
            mapGoods.emplace((double)good.second / good.first, good);

        double totalCost{};
        auto it = rbegin(mapGoods);
        while (it != rend(mapGoods)) {
            if (int(truckCapacity - it->second.first) > 0) {
                truckCapacity -= it->second.first;
                totalCost += it->second.second;
                ++it;
            }
            else {
                totalCost += (double)truckCapacity / it->second.first * it->second.second;
                break;
            }
        }

        return totalCost;
    }

}

