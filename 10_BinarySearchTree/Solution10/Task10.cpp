#include "BST.h"
#include "..\Task10\BST.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

namespace Homework {

	using Homework::Receipt;
	using Homework::Node;

	Node* makeBST(Node* root, std::vector<Receipt>& receipts, int left, int right) {
		if (left == right) return root;

		int middle = left + (right - left) / 2;
		Receipt newReceipt = receipts[middle];

		if (root == nullptr) root = new Node(newReceipt, nullptr);
		else {
			auto currentNode = root;
			while (true) {
				if (newReceipt.receiptNumber < currentNode->x.receiptNumber) {
					if (currentNode->left == nullptr) {
						currentNode->left = new Node(newReceipt, currentNode);
						break;
					}
					else
						currentNode = currentNode->left;
				}
				else if (newReceipt.receiptNumber > currentNode->x.receiptNumber) {
					if (currentNode->right == nullptr) {
						currentNode->right = new Node(newReceipt, currentNode);
						break;
					}
					else
						currentNode = currentNode->right;
				}
			}
		}

		makeBST(root, receipts, left, middle);
		makeBST(root, receipts, middle + 1, right);
	}
	Node* Homework::FromList(const std::vector<Receipt>& elements) {
		if (elements.empty()) return nullptr;

		auto tmpVector = elements;
		std::sort(begin(tmpVector), end(tmpVector), [](Receipt rec1, Receipt rec2) {
			return (rec1.receiptNumber < rec2.receiptNumber);
			});

		return makeBST(nullptr, tmpVector, 0, tmpVector.size());
	}

	void bypassBST_LnR(Node* node, std::vector<Receipt>& receipts) {
		if (node == nullptr) return;

		bypassBST_LnR(node->left, receipts);
		receipts.push_back(node->x);
		bypassBST_LnR(node->right, receipts);
	}
	std::vector<Receipt> FromNode(Node* root) {
		if (root == nullptr) return{};

		std::vector<Receipt> receipts;
		bypassBST_LnR(root, receipts);
		
		return receipts;
	}

	double GetAmount(const Node* root, size_t receiptNumber) {
		auto currentNode = root;
		while (true) {
			if (receiptNumber < currentNode->x.receiptNumber) {
				if (currentNode->left == nullptr)
					return 0.0;
				else
					if (receiptNumber == currentNode->left->x.receiptNumber)
						return currentNode->left->x.amount;
					else
						currentNode = currentNode->left;
			}
			else {
				if (currentNode->right == nullptr)
					return 0.0;
				else
					if (receiptNumber == currentNode->right->x.receiptNumber)
						return currentNode->right->x.amount;
					else
						currentNode = currentNode->right;
			}
		}
	}

	bool CheckTree(const Node* root) {
		if (root == nullptr) return false;
		auto currentNode = root;
		std::queue<Node*> nodeQueue;

		while (true) {
			if (currentNode->left != nullptr)
				if (currentNode->left->x.receiptNumber < currentNode->x.receiptNumber)
					nodeQueue.push(currentNode->left);
				else
					return false;

			if (currentNode->right != nullptr)
				if (currentNode->right->x.receiptNumber > currentNode->x.receiptNumber)
					currentNode = currentNode->right;
				else
					return false;
			else {
				if (nodeQueue.empty()) return true;
				currentNode = nodeQueue.front();
				nodeQueue.pop();
			}
		}
	}

	Node* searchNodeToDelete(Node* node, size_t receiptNumber) {
		if (node == nullptr) return nullptr;
		if (receiptNumber == node->x.receiptNumber) return node;

		(receiptNumber < node->x.receiptNumber)
			? searchNodeToDelete(node->left, receiptNumber)
			: searchNodeToDelete(node->right, receiptNumber);
	}
	Node* Delete(Node* root, size_t receiptNumber) {
		auto nodeToDelete = searchNodeToDelete(root, receiptNumber);

		if (nodeToDelete->left == nullptr && nodeToDelete->right == nullptr) { //leaf
			(nodeToDelete->x.receiptNumber < nodeToDelete->parent->x.receiptNumber)
				? nodeToDelete->parent->left = nullptr
				: nodeToDelete->parent->right = nullptr;
			delete[] nodeToDelete;
		}
		else if (nodeToDelete->left != nullptr && nodeToDelete->right != nullptr) { // left child + 
			
		}
		else if (nodeToDelete->left != nullptr) { // only left child
			(nodeToDelete->x.receiptNumber < nodeToDelete->parent->x.receiptNumber)
				? nodeToDelete->parent->left = nodeToDelete->left
				: nodeToDelete->parent->right = nodeToDelete->left;
			delete[] nodeToDelete;
		}
		else { // only right child
			(nodeToDelete->x.receiptNumber < nodeToDelete->parent->x.receiptNumber)
				? nodeToDelete->parent->left = nodeToDelete->right
				: nodeToDelete->parent->right = nodeToDelete->right;
			delete[] nodeToDelete;
		}
			
		

		return nullptr;
	}

	Receipt GetNext(Node* root, const Receipt& receipt) {
		return {};
	}

}