#include "ContactBook.h"
#include <queue>
#include <stack>

void ContactBook::add(Contact s) {
	if (this->contains(s.name)) return;

	auto currentNode = root;
	for (auto& key : s.name)
		currentNode = (!currentNode->nextNode[(int)key])
			? currentNode->addNewNode(key)
			: currentNode->getNextNode(key);

	currentNode->phoneNumber = s.number;
	return;
}

bool ContactBook::contains(const std::string& name) {
	auto currentNode = root;
	for (auto& ch : name) {
		if (currentNode->nextNode[(int)ch])
			currentNode = currentNode->nextNode[(int)ch];
		else
			return false;
	}
	return (currentNode->phoneNumber.length() > 0);
}

int ContactBook::count_starts_with(const std::string& pref) {
	int counter{};
	std::queue<Node*> nodeQueue;
	auto subTreeRoot = root->getSubTreeRoot(pref);
	
	if (!subTreeRoot) return 0;
	
	nodeQueue.push(subTreeRoot);
	while (true) {
		auto nodes = nodeQueue.front()->nextNode;
		nodeQueue.pop();

		for (auto& node : nodes)
			if (node) {
				nodeQueue.push(node);
				counter += node->phoneNumber.length() > 0;
			}

		if (nodeQueue.empty()) return counter;
	}
}

std::vector<Contact> ContactBook::starts_with(const std::string& pref) {
	int counter{};
	std::vector<Contact> result;

	std::stack<Node*> nodeStack;
	std::stack<std::string> nameStack;

	auto currentNode = root->getSubTreeRoot(pref);
	if (!currentNode) return{};

	auto nameTMP = pref;
	while (true) {
		for (int i{ 255 }; i != 0; --i)
			if (currentNode->nextNode[i]) {
				nodeStack.push(currentNode->nextNode[i]);
				nameStack.push(nameTMP + char(i));
			}

		if (nodeStack.empty()) return result;

		currentNode = nodeStack.top();
		nodeStack.pop();

		nameTMP = nameStack.top();
		nameStack.pop();

		if (currentNode->phoneNumber.length() > 0)
			result.push_back(Contact(nameTMP, currentNode->phoneNumber));
	}
}

ContactBook::Node* ContactBook::Node::getSubTreeRoot(const std::string& pref) {
	auto currentNode = this;

	for (int i{}; i < pref.length(); ++i) {
		if (currentNode->nextNode[(int)pref[i]])
			currentNode = currentNode->getNextNode(pref[i]);
		else return nullptr;
	}

	return currentNode;
}

ContactBook::Node* ContactBook::Node::getNextNode(char key) {
	return this->nextNode[(int)key];
}

ContactBook::Node* ContactBook::Node::addNewNode(char key)
{
	this->nextNode[(int)key] = new Node();
	return this->nextNode[(int)key];
}
