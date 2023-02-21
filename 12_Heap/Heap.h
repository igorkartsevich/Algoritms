#pragma once
#include <vector>
#include <cmath>

class Heap {
	
public:

    struct TruckCoordinate {
        int x;
        int y;

        bool operator<(const TruckCoordinate& other) const {
            double dist1 = std::sqrt(std::pow(x, 2) + std::pow(y, 2));
            double dist2 = std::sqrt(std::pow(other.x, 2) + std::pow(other.y, 2));
            return dist1 < dist2;
        }

        bool operator==(const TruckCoordinate& other) const {
            return x == other.x && y == other.y;
        }
    };
	
	static void buildHeapFromArray(const std::vector<int>& checks) {
		
    }

    static std::vector<TruckCoordinate> kClosestTrucks(const std::vector<TruckCoordinate>& truckCoordinateList, int k) {
        return std::vector<TruckCoordinate>{};
    }

    static std::vector<int> unloadingTruck(int n, const std::vector<int>& times) {
        return std::vector<int>{};
    }
};

