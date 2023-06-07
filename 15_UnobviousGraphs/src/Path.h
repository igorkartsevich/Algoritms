#pragma once
#include <vector>
#include <map>
#include <limits>

class Path {
private:
	struct Coordinate {
		int x;
		int y;
		Coordinate(int _x, int _y) : x(_x), y(_y) {}
		Coordinate() : Coordinate(0, 0) {}
	};

	std::vector<std::vector<int>> mapToProcess;
	std::multimap<int, Path::Coordinate> nodesMultyMapByDuration;
	int xRange;
	int yRange;

	std::vector<Path::Coordinate> getNextNodesVector(const Path::Coordinate& node);
	void setNewNodeTo_nodesByMinDuration(const Path::Coordinate& node, int nodeDuration);
	void setNewNodeTo_mapToProcess(const Path::Coordinate& node, int nodeDuration);
	int getNodeDurationFrom_mapToProcess(const Path::Coordinate& node);
	Path::Coordinate getCurrNode();
	bool is_nodeLast(const Path::Coordinate& node);
	int getLastNodeDuration();

public:
	Path(int _xRange, int _yRange) : xRange(_xRange), yRange(_yRange) {
		mapToProcess = std::vector<std::vector<int>>(_xRange, std::vector<int>(_yRange, INT_MAX));
	}

	static int shortestPathDuration(const std::vector<std::vector<int>>& map);
};
