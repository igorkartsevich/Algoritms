#pragma once
#include <map>
#include <list>
#include <string>
#include <unordered_set>

class Bridges {
public:
	static bool isProjectSuccess(const std::map<std::string, std::list<std::string>>& project);

private:
	struct Bridge {
		std::string toForward;
		std::string toReverse;
		Bridge(std::string firstIsland, std::string secondIsland) {
			toForward = firstIsland + "-" + secondIsland;
			toReverse = secondIsland + "-" + firstIsland;
		}
		Bridge() : Bridge("", "") {}
	};

	std::unordered_multiset<std::string> bridgesToPassSet;

	bool checkProject(std::string currIsland, const std::map<std::string, std::list<std::string>>& project);
	void getAllBridgesTo_PassSet(const std::map<std::string, std::list<std::string>>& project);
	void deleteBridgeFrom_PassSet(Bridge& bridge);
	bool is_bridgeAlredyPassed(Bridge& bridge);
	void getBackBridgeTo_PassSet(Bridge& bridge);
};
