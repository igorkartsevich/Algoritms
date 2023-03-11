#pragma once
#include <vector>

class Node {
private:
	bool isEnd;
	std::vector<Node*> nextNodeVec;

public:
	Node(bool _isEnd) : isEnd(_isEnd), nextNodeVec(10, nullptr) {}
	Node() : Node(false) {}

	Node* getNextNode(Node* node, int index);
	Node* makeNextNode(Node* node, int index);
	void markNodeLikeEnd(Node* node);
	bool checkToEnd(Node* node);
};