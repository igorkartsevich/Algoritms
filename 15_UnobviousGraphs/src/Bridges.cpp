#include "Bridges.h"
#include <iostream>

void Bridges::getAllBridgesTo_TestSet(const std::map<std::string, std::list<std::string>>& project) {
	TestSet.clear();
	for (auto& island : project)
		for (auto& next : project.find(island.first)->second) {
			bridge = Bridge(island.first, next);
			TestSet.emplace(bridge.toForward);
		}
	return;
}

void Bridges::deleteBridgeFrom_TestSet(Bridge& bridge) {
	TestSet.erase(TestSet.find(bridge.toForward));
	TestSet.erase(TestSet.find(bridge.toReverse));
	return;
}

bool Bridges::is_bridgeAlredyPassed(Bridge& bridge) {
	return TestSet.find(bridge.toForward) == end(TestSet);
}

void Bridges::getBackBridgeTo_TestSet(Bridge& bridge) {
	TestSet.emplace(bridge.toForward);
	TestSet.emplace(bridge.toReverse);
	return;
}

bool Bridges::is_bridgeLast() {
	return TestSet.empty();
}

bool Bridges::checkProject(std::string currIsland, const std::map<std::string, std::list<std::string>>& project) {
	auto nextIslands = project.find(currIsland)->second;
	
	if (nextIslands.size() > 1) {
		for (auto& next : nextIslands) {
			bridge = Bridge(currIsland, next);

			if (!is_bridgeAlredyPassed(bridge)) {
				deleteBridgeFrom_TestSet(bridge);
				checkProject(next, project);

			}
		}
	}

	if (is_bridgeLast()) return true;
	
	getBackBridgeTo_TestSet(bridge);
	return false;
}

bool Bridges::isProjectSuccess(const std::map<std::string, std::list<std::string>>& project) {
	Bridges projectToTest;

	for (auto& startIsland : project) {
		projectToTest.getAllBridgesTo_TestSet(project);
		if (projectToTest.checkProject(startIsland.first, project))
			return true;
	}

	return false;
}
