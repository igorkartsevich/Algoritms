#include "SimpleGraph.h"
#include <stack>
#include <queue>
#include <unordered_map>

Employee* getEmployeeById(int id, std::vector<Employee*>& employees) {
	for (int i{}; i < employees.size(); ++i)
		if (employees[i]->id == id)
			return employees[i];
	return nullptr;
};

void countImportance(Employee* employee, std::vector<Employee*>& employees, int& importanceSum) {
	importanceSum += employee->importance;

	for (auto& sub : employee->subordinates)
		countImportance(getEmployeeById(sub, employees), employees, importanceSum);

	return;
}

int SimpleGraph::getImportance(std::vector<Employee*> employees, int id) {
	auto employee = getEmployeeById(id, employees);
	if (!employee) return 0;

	int importanceSum{};
	countImportance(employee, employees, importanceSum);

	return importanceSum;
}

//*****************************************

bool isExist(std::unordered_map<std::string, int>& map, Node* const node) {
	return map.find(node->val) != map.end();
}

void addNewNode(std::unordered_map<std::string, int>& map, Node* const node) {
	map[node->val] = map.size();
}

void getClone(std::vector<Node*>& graphCopy, std::unordered_map<std::string, int>& map, Node* const node) {
	auto nodeClone = new Node(node->val);

	if (map.find(nodeClone->val) == map.end()) {
		graphCopy.push_back(nodeClone);
		addNewNode(map, nodeClone);
	}
	else return;

	for (auto& n : node->neighbors) {
		getClone(graphCopy, map, n);
		nodeClone->neighbors.push_back(n);
	}
}

Node* SimpleGraph::cloneGraphVK(Node* node) {
	std::unordered_map<std::string, int> nodesIndexMap;
	std::vector<Node*> graphCopy;
	
	getClone(graphCopy, nodesIndexMap, node);

	return graphCopy[0];
}
