#include "Node.h"

bool Node::isFullyLoaded() const {
	return this->keyCounter == this->keyList.size();
}

bool Node::isRoot() const {
	return !this->parentNode;
}

bool Node::isLeaf() const {
	return this->childrenCounter == 0;
}

void Node::addNewKey(const int key) {
	this->keyList[this->keyCounter++] = key;
	std::qsort(this->keyList.data(), this->keyCounter, sizeof(int),
		[](const void* key1, const void* key2) {
			auto arg1 = *(const int*)key1;
			auto arg2 = *(const int*)key2;
			return (arg1 < arg2) ? -1 : (arg1 > arg2) ? 1 : 0;
		});
	return;
}

int Node::getIndexByKey(const int key) {
	int left = 0;
	int right = this->keyCounter - 1;
	
	while (left <= right) {
		int middle = (left + right) >> 1;
		if (key < this->keyList[middle])
			right = middle - 1;
		else if (key > this->keyList[middle])
			left = middle + 1;
		else
			return -(middle + 1); // return negative sigh if the node was found, (middle + 1) - for index = 0 and negative sign
	}
	return left;
}

Node* Node::getNextNode(const int key) {
	int index = this->getIndexByKey(key);
	return this->childrenList[index];
}

void Node::splitNode(const int indexSplit, const int end, Node* leftNode, Node* rightNode) {
	for (int i{}; i < end; ++i) {
		if (i < indexSplit) {
			leftNode->keyList[i] = this->keyList[i];
			++leftNode->keyCounter;
		}
		else if (i > indexSplit) {
			rightNode->keyList[i - (indexSplit + 1)] = this->keyList[i];
			++rightNode->keyCounter;
		}
	}

	if (this->childrenCounter == 0) return;

	for (int i{}; i <= end; ++i) {
		if (i <= indexSplit) {
			leftNode->childrenList[i] = this->childrenList[i];
			leftNode->childrenList[i]->parentNode = leftNode;
			++leftNode->childrenCounter;
		}
		else if (i > indexSplit) {
			rightNode->childrenList[i - (indexSplit + 1)] = this->childrenList[i];
			rightNode->childrenList[i - (indexSplit + 1)]->parentNode = rightNode;
			++rightNode->childrenCounter;
		}
	}

	return;
}

Node* Node::redoNode(Node* currentNode) {
	int indexSplit = currentNode->keyCounter >> 1;
	
	Node* prevNode = (currentNode->isRoot()) ? new Node() : currentNode->parentNode;
	prevNode->addNewKey(currentNode->keyList[indexSplit]);
	prevNode->childrenCounter += (currentNode->isRoot()) ? 2 : 1;
	int indexInPrev = (prevNode->getIndexByKey(currentNode->keyList[indexSplit]) * -1) - 1; // ...* -1) - 1... for compensation return -(middle + 1) from int Node::getIndexByKey(const int key)

	if (prevNode->keyCounter - 1 > indexInPrev) // if indexInPrev is not last one, move the node which more than indexInPrev one step forward
		for (int i{ keyCounter }; i > indexInPrev; --i)
			std::swap(prevNode->childrenList[i], prevNode->childrenList[i - 1]);

	auto newLeftNode = new Node();
	newLeftNode->parentNode = prevNode;
	prevNode->childrenList[indexInPrev] = newLeftNode;

	auto newRightNode = new Node();
	newRightNode->parentNode = prevNode;
	prevNode->childrenList[indexInPrev + 1] = newRightNode;
	
	currentNode->splitNode(indexSplit, currentNode->keyCounter, newLeftNode, newRightNode);
	delete currentNode;

	return prevNode;
}

std::vector<int> Node::getKeyList() const {
	return this->keyList;
}

int Node::getKeyCounter() const{
	return this->keyCounter;
}

std::vector<Node*> Node::getChildrenList() const {
	return this->childrenList;
}

int Node::getChildrenCounter() const {
	return this->childrenCounter;
}