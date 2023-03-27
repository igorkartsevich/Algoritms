#pragma once
#include <vector>
#include <unordered_set>

const int t = 2;

class Node {
private:
	Node* parentNode;
	std::vector<Node*> childrenList;
	int childrenCounter;
	std::vector<int> keyList;
	int keyCounter;

public:
	Node()
		: parentNode(nullptr),
		  childrenList(2 * t, nullptr),
		  childrenCounter{},
		  keyList(2 * t - 1, 0),
		  keyCounter{}
	{}

	~Node() {}

	bool isFullyLoaded() const;
	bool isRoot() const;
	bool isLeaf() const;

	void addNewKey(const int key);
	int getIndexByKey(const int key);
	Node* getNextNode(const int key);
	void splitNode(const int indexSplit, const int end, Node* leftNode, Node* rightNode);
	Node* redoNode(Node* currentNode);

	std::vector<int> getKeyList() const;
	int getKeyCounter() const;

	std::vector<Node*> getChildrenList() const;
	int getChildrenCounter() const;
};