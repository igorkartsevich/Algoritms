#pragma once
#include <vector>
#include <unordered_set>

const int t = 2;

class Node {
private:
	Node* parentNode;
	std::vector<Node*> childrenNodes;
	int childrenCounter;
	std::vector<int> keyList;
	int keyCounter;

public:
	Node() : parentNode(nullptr), childrenNodes(2 * t + 1, nullptr),
			 childrenCounter{}, keyList(2 * t), keyCounter{} {}
	
	Node* Node::searchKeys(Node* node, const int key);
};