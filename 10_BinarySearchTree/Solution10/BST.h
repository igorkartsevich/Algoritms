#pragma once

#include <vector>
#include "Node.h"

namespace Homework {

	Node* FromList(const std::vector<Receipt>& elements);

	std::vector<Receipt> FromNode(Node* root);

	double GetAmount(const Node* root, size_t receiptNumber);

	bool CheckTree(const Node* root);

	Node* Delete(Node* root, size_t receiptNumber);

	Receipt GetNext(Node* root, const Receipt& receipt);
}