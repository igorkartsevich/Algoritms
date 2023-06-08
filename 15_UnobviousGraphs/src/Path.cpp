#include "Path.h"

int Path::shortestPathDuration(const std::vector<std::vector<int>>& inMap)
{
	Path path(inMap.size(), inMap[0].size());
	
	path.setNewNodeTo_nodesByMinDuration(Path::Coordinate(0, 0), inMap[0][0]);
	path.setNewNodeTo_mapToProcess(Path::Coordinate(0, 0), inMap[0][0]);

	while (true) {
		Path::Coordinate currNode = path.getCurrNode();
		std::vector<Path::Coordinate> nextNodesVector = path.getNextNodesVector(currNode);

		for (auto& nextNode : nextNodesVector) {
			auto currNodeDuration = path.getNodeDurationFrom_mapToProcess(currNode);
			auto nextStepDuration = inMap[nextNode.x][nextNode.y];
			auto nextNodeDuration = path.getNodeDurationFrom_mapToProcess(nextNode);

			if (currNodeDuration + nextStepDuration < nextNodeDuration) {
				nextNodeDuration = currNodeDuration + nextStepDuration;
				path.setNewNodeTo_mapToProcess(nextNode, nextNodeDuration);

				if (path.is_nodeLast(nextNode))
					return path.getLastNodeDuration();
				else
					path.setNewNodeTo_nodesByMinDuration(nextNode, nextNodeDuration);
			}
		}
	}
}

std::vector<Path::Coordinate> Path::getNextNodesVector(const Path::Coordinate& node) {
	std::vector<Path::Coordinate> nextNodes;

	if (node.x > 0)
		nextNodes.push_back(Path::Coordinate(node.x - 1, node.y));
	if (node.y > 0)
		nextNodes.push_back(Path::Coordinate(node.x, node.y - 1));
	if (node.x < xRange)
		nextNodes.push_back(Path::Coordinate(node.x + 1, node.y));
	if (node.y < yRange)
		nextNodes.push_back(Path::Coordinate(node.x, node.y + 1));

	return nextNodes;
}

void Path::setNewNodeTo_nodesByMinDuration(const Path::Coordinate& node, int nodeDuration) {
	nodesMultyMapByDuration.emplace(nodeDuration, Path::Coordinate(node.x, node.y));
	return;
}

void Path::setNewNodeTo_mapToProcess(const Path::Coordinate& node, int nodeDuration) {
	mapToProcess[node.x][node.y] = nodeDuration;
	return;
}

int Path::getNodeDurationFrom_mapToProcess(const Path::Coordinate& node) {
	return mapToProcess[node.x][node.y];
}

Path::Coordinate Path::getCurrNode() {
	Path::Coordinate node = begin(nodesMultyMapByDuration)->second;
	nodesMultyMapByDuration.erase(nodesMultyMapByDuration.begin());
	return node;
}

int Path::getLastNodeDuration() {
	return mapToProcess[xRange][yRange];
}

bool Path::is_nodeLast(const Path::Coordinate& node) {
	return node.x == xRange && node.y == yRange;
}
