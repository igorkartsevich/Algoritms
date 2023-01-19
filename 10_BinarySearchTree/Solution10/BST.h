#pragma once

#include <vector>
#include "Node.h"

namespace Homework {

	Node* FromList(const std::vector<Receipt>& elements);

	std::vector<Receipt> FromNode(Node* root);

	double GetAmount(Node* root, size_t receiptNumber);

	bool CheckTree(Node* root);

	Node* Delete(Node* root, size_t receipt);

	Receipt GetNext(Node* root, const Receipt& receipt);
}