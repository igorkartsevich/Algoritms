#include "SimpleGraph.h"
#include <queue>

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

Node* SimpleGraph::cloneGraphVK(Node* node) {


	return nullptr;
}
