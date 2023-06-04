#include "Bridges.h"
#include <iostream>

void Bridges::getAllBridgesTo_PassSet(const std::map<std::string, std::list<std::string>>& project) {
	for (auto& island : project)
		for (auto& next : project.find(island.first)->second) {
			Bridge bridge;
			bridge = Bridge(island.first, next);
			bridgesToPassSet.emplace(bridge.toForward);
		}
	return;
}

void Bridges::deleteBridgeFrom_PassSet(Bridge& bridge) {
	bridgesToPassSet.erase(bridgesToPassSet.find(bridge.toForward));
	bridgesToPassSet.erase(bridgesToPassSet.find(bridge.toReverse));
	return;
}

bool Bridges::is_bridgeAlredyPassed(Bridge& bridge) {
	return bridgesToPassSet.find(bridge.toForward) == end(bridgesToPassSet);
}

void Bridges::getBackBridgeTo_PassSet(Bridge& bridge) {
	bridgesToPassSet.emplace(bridge.toForward);
	bridgesToPassSet.emplace(bridge.toReverse);
	return;
}

bool Bridges::checkProject(std::string currIsland, const std::map<std::string, std::list<std::string>>& project) {
	auto nextIslands = project.find(currIsland)->second;

	Bridge bridge;
	for (auto& next : nextIslands) {
		bridge = Bridge(currIsland, next);

		if (!is_bridgeAlredyPassed(bridge)) {
			deleteBridgeFrom_PassSet(bridge);
			checkProject(next, project);
		}
	}

	if (bridgesToPassSet.empty()) return true;
	
	getBackBridgeTo_PassSet(bridge);
	return false;
}

bool Bridges::isProjectSuccess(const std::map<std::string, std::list<std::string>>& project) {
	for (auto& startIsland : project) {
		Bridges projectToTest;
		projectToTest.getAllBridgesTo_PassSet(project);

		if (projectToTest.checkProject(startIsland.first, project)) return true;
	}

	return false;
}
