#include "BTree.h"
#include "Node.h"
#include <string>
#include <queue>

void BTree::add(int key) {
	if (key < 0) return;
	auto currentNode = root;

	while (true) {
		if (currentNode->isFullyLoaded())
			currentNode = currentNode->redoNode(currentNode);

		if (currentNode->isRoot()) root = currentNode;

		if (currentNode->isLeaf()) {
			currentNode->addNewKey(key);
			return;
		}

		currentNode = currentNode->getNextNode(key);
	}
}

bool BTree::contains(int key) {
	if (key < 0) return false;
	auto currentNode = root;

	while (true) {
		if (currentNode->getIndexByKey(key) < 0)
			return true;
		else if (currentNode->isLeaf())
			return false;
		else
			currentNode = currentNode->getNextNode(key);
	}
}

std::vector<int> BTree::getSorted() {



	return {};
}