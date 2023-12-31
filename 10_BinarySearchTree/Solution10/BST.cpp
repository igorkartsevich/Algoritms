#include "BST.h"
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

namespace Homework {

	using Homework::Receipt;
	using Homework::Node;

	Node* searchReceipt(Node* node, size_t receiptNumber);

	//***********************************

	void addNewNode(Node*& node, Receipt& receipt) {
		if (node == nullptr)
			node = new Node(receipt, nullptr);
		else
			(receipt.receiptNumber < node->x.receiptNumber)
			? (node->left != nullptr) ? addNewNode(node->left, receipt) : node->left = new Node(receipt, node)
			: (node->right != nullptr) ? addNewNode(node->right, receipt) : node->right = new Node(receipt, node);
	}

	Node* makeBST(Node* root, std::vector<Receipt>& receipts, int left, int right) {
		if (left == right) return root;

		int middle = left + (right - left) / 2;
		addNewNode(root, receipts[middle]);

		makeBST(root, receipts, left, middle);
		makeBST(root, receipts, middle + 1, right);
	}

	Node* Homework::FromList(const std::vector<Receipt>& elements) {
		if (elements.empty()) return nullptr;

		auto tmpVector = elements;
		std::qsort(&tmpVector[0], elements.size(), sizeof(Receipt), comparator);

		return makeBST(nullptr, tmpVector, 0, tmpVector.size());
	}

	//***********************************

	void bypassBST(Node*& node, std::vector<Receipt>& receipts) {
		if (node == nullptr) return;

		bypassBST(node->left, receipts);
		receipts.push_back(node->x);
		bypassBST(node->right, receipts);
	}

	std::vector<Receipt> FromNode(Node* root) {
		if (root == nullptr) return{};

		std::vector<Receipt> receipts;
		bypassBST(root, receipts);

		return receipts;
	}

	//***********************************

	Node* searchReceipt(Node* node, size_t receiptNumber) {
		if (node == nullptr) return nullptr;
		if (receiptNumber == node->x.receiptNumber) return node;

		(receiptNumber < node->x.receiptNumber)
			? searchReceipt(node->left, receiptNumber)
			: searchReceipt(node->right, receiptNumber);
	}

	double GetAmount(const Node* root, size_t receiptNumber) {
		return (root == nullptr) ? 0.0 : searchReceipt((Node*)root, receiptNumber)->x.amount;
	}

	//***********************************

	bool CheckTree(const Node* root) {
		if (root == nullptr) return false;

		struct ToRemember {
			Node* node;
			std::pair<int, int> range;
			ToRemember(Node* _node, int _left, int _right) : node(_node), range(std::make_pair(_left, _right)) {};
		};

		auto currentNode = (Node*)root;
		std::stack<ToRemember> stackToRemember;
		size_t left{ 0 }, right{ currentNode->x.receiptNumber };

		while(true) {
			if (currentNode->left != nullptr) {
				if (currentNode->right != nullptr)
					stackToRemember.push(ToRemember(currentNode, left, right));

				if (currentNode->left->x.receiptNumber < right) {
					right = currentNode->left->x.receiptNumber;
					currentNode = currentNode->left;
				}
				else return false;
			}
			else {
				if (currentNode->right != nullptr) {
					if (currentNode->right->x.receiptNumber < right) {
						left = currentNode->right->x.receiptNumber;
						currentNode = currentNode->right;
					}
					else return false;
				}
				else {
					if (stackToRemember.empty()) return true;
					else {
						currentNode = stackToRemember.top().node;
						left = stackToRemember.top().range.first;
						right = stackToRemember.top().range.second;
						stackToRemember.pop();
					}
				}
			}
		}
	}

	//***********************************

	Node* Delete(Node* root, size_t receiptNumber) {
		Node* nodeToDelete = searchReceipt(root, receiptNumber);

		auto deleteLeaf = [&](Node* nodeToDelete) {
			if (nodeToDelete->parent == nullptr)
				root = nullptr;
			else
				(nodeToDelete->parent->left == nodeToDelete)
					? nodeToDelete->parent->left = nullptr : nodeToDelete->parent->right = nullptr;
			delete nodeToDelete;
		};

		auto deleteOneChildParent = [&](Node* nodeToDelete) {
			nodeToDelete->x = (nodeToDelete->left != nullptr)
				? nodeToDelete->left->x : nodeToDelete->right->x;
			
			(nodeToDelete->left != nullptr)
				? nodeToDelete->left = nodeToDelete->left->left
				: nodeToDelete->right = nodeToDelete->right->right;
			
			(nodeToDelete->left != nullptr)
				? delete nodeToDelete->left : delete nodeToDelete->right;
		};

		auto deleteTwoChildrenParent = [&](Node* nodeToDelete) {
			if (nodeToDelete->right->left == nullptr) {
				if (nodeToDelete->right->right == nullptr) {
					nodeToDelete->x = nodeToDelete->right->x;
					deleteLeaf(nodeToDelete->right);
				}
				else
					deleteOneChildParent(nodeToDelete);
			}
			else {
				Node* leftMost = nodeToDelete->right->left;
				while (leftMost->left != nullptr) {
					leftMost = leftMost->left;
				}
				nodeToDelete->x = leftMost->x;
				(leftMost->right == nullptr) ? deleteLeaf(leftMost) : deleteOneChildParent(leftMost);
			}
		};

		if (nodeToDelete->left == nullptr && nodeToDelete->right == nullptr)
			deleteLeaf(nodeToDelete);
		else if (nodeToDelete->left != nullptr && nodeToDelete->right != nullptr)
			deleteTwoChildrenParent(nodeToDelete);
		else
			deleteOneChildParent(nodeToDelete);

		return root;
	}

	//***********************************

	Receipt GetNext(Node* root, const Receipt& receipt) {
		Node* currentReceipt = searchReceipt((Node*)root, receipt.receiptNumber);
		Node* nextReceipt = nullptr;

		if (currentReceipt->right == nullptr) {
			nextReceipt = currentReceipt->parent;
			while (nextReceipt != nullptr) {
				if (nextReceipt->x.receiptNumber > receipt.receiptNumber)
					return nextReceipt->x;
				else
					nextReceipt = nextReceipt->parent;
			}
			return {};
		}
		else if (currentReceipt->right->left == nullptr)
			return currentReceipt->right->x;
		else {
			nextReceipt = currentReceipt->right->left;
			while (nextReceipt->left != nullptr)
				nextReceipt = nextReceipt->left;
			return nextReceipt->x;
		}
	}
}