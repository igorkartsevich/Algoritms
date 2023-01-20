#include "BST.h"
#include "..\Task10\BST.h"
#include <vector>
#include <stack>
#include <algorithm>

namespace Homework {

	using Homework::Receipt;
	using Homework::Node;

	Node* Homework::FromList(const std::vector<Receipt>& elements) {
		auto size = elements.size();
		if (size == 0) return nullptr;

		Node root(elements[0]);
		
		for (int i{ 1 }; i < size; ++i) {
			Node currentNode = root;
			Node nextNode(elements[i]);

			while (true) {
				auto direction = (nextNode < currentNode)
					? currentNode.left
					: currentNode.right;

				if (direction == nullptr) {
					direction = &nextNode;
					break;
				}
				else
					currentNode = *direction;
			}
		}

		return &root;
	}

	std::vector<Receipt> FromNode(Node* root) {
		std::vector<Receipt> receipts;
		if(root == nullptr) return receipts;

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