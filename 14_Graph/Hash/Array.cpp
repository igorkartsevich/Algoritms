#include "Array.h"

bool Array::canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
	std::vector<std::vector<bool>> matrix(numCourses, std::vector<bool>(numCourses, false));

	for (auto& pair : prerequisites)
		if (matrix[pair[1]][pair[0]])
			return false;
		else 
			matrix[pair[0]][pair[1]] = true;

	return true;
}
