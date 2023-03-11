#include "BTree.h"
#include <string>
#include <stack>

void BTree::add(int x) {
	if (x < 0) return;

	auto currentNode = root;
	std::string str = std::to_string(x);

	for (auto ch : str) {
		currentNode = (!currentNode->getNextNode(currentNode, ch - 48))
			? currentNode->makeNextNode(currentNode, ch - 48)
			: currentNode->getNextNode(currentNode, ch - 48);
	}
	currentNode->markNodeLikeEnd(currentNode);

	return;
}

bool BTree::contains(int x) {
	if (x < 0) return false;

	auto currentNode = root;
	std::string str = std::to_string(x);

	for (auto ch : str) {
		currentNode = currentNode->getNextNode(currentNode, ch - 48);
		if (!currentNode) return false;
	}

	return currentNode->checkToEnd(currentNode);
}

std::vector<int> BTree::getSorted() {
	
	return {};
}