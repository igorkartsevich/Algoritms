#pragma once
#include <vector>
#include <string>

// Определение сотрудника.
struct Employee {
    int id;
    int importance;
    std::vector<int> subordinates;
};

// Определение Node.
struct Node {
    std::string val;
    std::vector<Node*> neighbors;
    Node() {
        val = "";
    }
    Node(const std::string& _val) {
        val = _val;
    }
    Node(const std::string& _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class SimpleGraph {
public:
    // Task #1
    static int getImportance(std::vector<Employee*>& employees, int id);

    // Task #2
    static Node* cloneGraphVK(Node* node);
};

