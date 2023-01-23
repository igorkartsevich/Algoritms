#include "BST.h"
#include "..\Task10\BST.h"
#include <vector>
#include <stack>
#include <algorithm>

namespace Homework {

	using Homework::Receipt;
	using Homework::Node;

	Node* makeBST(Node* root, std::vector<Receipt>& receipts, int left, int right) {
		if (left == right) return root;

		int middle = left + (right - left) / 2;
		Receipt newReceipt = receipts[middle];

		if (root == nullptr) root = new Node(newReceipt);
		else {
			auto currentNode = root;
			while (true) {
				if (newReceipt.receiptNumber < currentNode->x.receiptNumber) {
					if (currentNode->left == nullptr) {
						currentNode->left = new Node(newReceipt);
						break;
					}
					else
						currentNode = currentNode->left;
				}
				else if (newReceipt.receiptNumber > currentNode->x.receiptNumber) {
					if (currentNode->right == nullptr) {
						currentNode->right = new Node(newReceipt);
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

	void bypassBST_Vertical(const Node* root, std::vector<Receipt>& receipts) {
		if (root == nullptr) return;

		auto currentNode = root;
		std::stack<Node*> nodeStack;

		while (true) {
			receipts.push_back(currentNode->x);

			if (currentNode->left != nullptr)
				nodeStack.push(currentNode->left);

			if (currentNode->right != nullptr)
				currentNode = currentNode->right;
			else {

				if (nodeStack.empty()) return;
				currentNode = nodeStack.top();
				nodeStack.pop();
			}
		}
	}
	std::vector<Receipt> FromNode(Node* root) {
		std::vector<Receipt> receipts;
		bypassBST_Vertical(root, receipts);

		std::sort(begin(receipts), end(receipts), [](Receipt rec1, Receipt rec2) {
			return (rec1.receiptNumber < rec2.receiptNumber);
			});

		return receipts;
	}

	double GetAmount(Node* root, size_t receiptNumber) {
		return {};
	}

	bool CheckTree(Node* root) {
		return {};
	}

	Node* Delete(Node* root, size_t receipt) {
		return {};
	}

	Receipt GetNext(Node* root, const Receipt& receipt) {
		return {};
	}

}