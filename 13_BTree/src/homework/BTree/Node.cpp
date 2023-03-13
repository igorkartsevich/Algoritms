#include "Node.h"

Node* Node::searchKeys(Node* node, const int key) {
	if (!node) return nullptr;
	auto currentNode = node;

	while (currentNode) {
		for (int i{}; i < currentNode->keyCounter; ++i) {
			if (currentNode->keyList[i] == key)
				return currentNode;
			else if (currentNode->keyList[i] > key) {
				currentNode = currentNode->childrenNodes[i];
				break;
			}
		}

		if (key > currentNode->keyList.back())
			currentNode = currentNode->childrenNodes.back();
	}

	return nullptr;
}