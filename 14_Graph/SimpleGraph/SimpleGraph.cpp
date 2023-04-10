#include "SimpleGraph.h"
#include <queue>

int SimpleGraph::getImportance(std::vector<Employee*>& employees, int id) {
	if (employees.empty()) return 0;

	int importanceSum{};
	std::queue<Employee*> employeeQueue;

	auto getEmployeeById = [&employees](int id) {
		for (int i{}; i < employees.size(); ++i)
			if (employees[i]->id == id)
				return employees[i];
	};

	employeeQueue.push(getEmployeeById(id));
	
	while (!employeeQueue.empty()) {
		importanceSum += employeeQueue.front()->importance;

		for (auto& id : employeeQueue.front()->subordinates)
			employeeQueue.push(getEmployeeById(id));
		
		employeeQueue.pop();
	}
	
	return importanceSum;
}

Node* SimpleGraph::cloneGraphVK(Node* node) {


	return nullptr;
}
