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

int SimpleGraph::getImportance(std::vector<Employee*> employees, int id) {
	if (employees.empty()) return 0;
	if (!getEmployeeById(id, employees)) return 0;

	std::queue<Employee*> employeeQueue;
	employeeQueue.push(getEmployeeById(id, employees));
	int importanceSum{};

	while (!employeeQueue.empty()) {
		importanceSum += employeeQueue.front()->importance;

		for (auto& id : employeeQueue.front()->subordinates)
			if (getEmployeeById(id, employees))
				employeeQueue.push(getEmployeeById(id, employees));
		
		employeeQueue.pop();
	}
	
	return importanceSum;
}

void loadNodesToCopy(std::vector<Node*>& graphCopy, std::unordered_map<std::string, int>& map, Node* const node) {
	std::stack<Node*> stack;
	stack.push(node);

	int currentIndex{};
	while (!stack.empty()) {
		auto currentNode = stack.top();
		stack.pop();

		if (!map.count(currentNode->val)) {
			map[currentNode->val] = currentIndex++;

			graphCopy.push_back(
				new Node(currentNode->val, std::vector<Node*>(currentNode->neighbors.size(), nullptr))
			);

			for (auto& node : currentNode->neighbors)
				stack.push(node);
		}
	}
	return;
}

void loadNeighborsToCopy(std::vector<Node*>& graphCopy, const std::unordered_map<std::string, int>& indexMap, Node* const node) {
	std::stack<Node*> stack;
	stack.push(node);

	while (!stack.empty()) {
		auto currentNode = stack.top();
		stack.pop();

		int indexNode = indexMap.find(currentNode->val)->second; // index in the graphCopy

		for (int i{}; i < currentNode->neighbors.size(); ++i) {
			auto nextNeighbor = currentNode->neighbors[i];
			int indexNeghbor = indexMap.find(nextNeighbor->val)->second;

			graphCopy[indexNode]->neighbors[i] = graphCopy[indexNeghbor]; // load neighbor
		}
		
		for (auto& n : currentNode->neighbors)
			if (!graphCopy[indexMap.find(n->val)->second]->neighbors[0]) // if node's neighbors are not loaded early
				stack.push(n);
	}

	return;
}

Node* SimpleGraph::cloneGraphVK(Node* node) {
	std::unordered_map<std::string, int> nodesIndexMap;
	std::vector<Node*> graphCopy;
	
	loadNodesToCopy(graphCopy, nodesIndexMap, node);

	loadNeighborsToCopy(graphCopy, nodesIndexMap, node);

	return graphCopy[0];
}
