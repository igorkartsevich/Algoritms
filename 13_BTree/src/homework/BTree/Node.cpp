#include "Node.h"

Node* Node::getNextNode(Node* node, int index) {
	return node->nextNodeVec[index];
}

Node* Node::makeNextNode(Node* node, int index) {
	node->nextNodeVec[index] = new Node();
	return node->nextNodeVec[index];
}

void Node::markNodeLikeEnd(Node* node) {
	node->isEnd = true;
	return;
}

bool Node::checkToEnd(Node* node) {
	return node->isEnd;
}