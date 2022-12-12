#include "pch.h"
#include "framework.h"
#include "WorkPlanner.h"
#include "HuffmanCode.h"
#include "..\TestTask9\_WorkPlanner.h"
#include "..\TestTask9\_HuffmanCode.h"

namespace Homework::WorkPlanner {

	size_t FindMaximumIncome(const std::vector<size_t>& workRates, size_t k) {
		return HomeworkCheck::WorkPlanner::FindMaximumIncome(workRates, k);
	}

	size_t FindMinimumManagers(const std::vector<std::pair<std::time_t, std::time_t>>& intervals) {
		return HomeworkCheck::WorkPlanner::FindMinimumManagers(intervals);
	}

	double LoadTruck(size_t truckCapacity, const std::vector<std::pair<size_t, size_t>>& goods) {
		return HomeworkCheck::WorkPlanner::LoadTruck(truckCapacity,goods);
	}

}

namespace Homework::HuffmanCode {

	unsigned __int64 EncodeHuffman(const std::string& text) {
		return HomeworkCheck::HuffmanCode::EncodeHuffman(text);
	}

}