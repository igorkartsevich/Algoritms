#include "BTree.h"
#include "Node.h"
#include <stack>

void BTree::add(int key) {
	if (key < 0) return;
	auto currentNode = root;

	while (true) {
		if (currentNode->isFullyLoaded())
			currentNode = currentNode->redoNode(currentNode);

		if (currentNode->isRoot())
			root = currentNode;

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
		
		if (currentNode->isLeaf())
			return false;
		
		currentNode = currentNode->getNextNode(key);
	}
}

std::vector<int> BTree::getSorted() {
	std::vector<int> result;

	struct Stack {
		Node* node;
		int nextNodeIndex;
		Stack(Node* _node, int _index) : node(_node), nextNodeIndex(_index) {}
	};

	std::stack<Stack> nodeStack;
	nodeStack.push(Stack(root, 0));

	while (true) {
		if (nodeStack.top().node->isLeaf()) { // if the node is leaf, load all keys to result 
			auto keyList = nodeStack.top().node->getKeyList();
			for (int i{}; i < nodeStack.top().node->getKeyCounter(); ++i)
				result.push_back(keyList[i]);
		}
		else { // if is not leaf
			// if nextNodeIndex is in the ChildrenList add new node in Stack
			if (nodeStack.top().nextNodeIndex < nodeStack.top().node->getChildrenCounter()) { 
				auto nextNode = nodeStack.top().node->getChildrenList()[nodeStack.top().nextNodeIndex++];
				nodeStack.push(Stack(nextNode, 0));
				continue;
			}
		}

		// if the node is fully used, go back to the level above
		nodeStack.pop();
		
		// if tree's nodes is over
		if (nodeStack.empty()) return result;
		
		// if nextNodeIndex of the top node is in ChildrenList, load node's key to result
		if (nodeStack.top().nextNodeIndex < nodeStack.top().node->getChildrenCounter()) 
			result.push_back(nodeStack.top().node->getKeyList()[nodeStack.top().nextNodeIndex - 1]);
		
	}
}

int BTree::getMaxHeight() {
	int height{};
	auto currentNode = root;
	
	while (!currentNode->isLeaf()) {
		++height;
		currentNode = currentNode->getChildrenList()[0];
	}

	return height;
}