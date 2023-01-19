#pragma once
#include "..\Solution10\Node.h"
#include <vector>
#include <algorithm>

namespace HomeworkCheck {

	using namespace std;
	using Homework::Receipt;
	using Homework::Node;

	Node* FromList(const vector<Receipt>& elements);

	vector<Receipt> FromNode(Node* root);
	
	size_t MaxDepth(Homework::Node* root);

	bool IsBST(Node* root);

	double GetAmount(Node* root, size_t receiptNumber);

	bool CheckTree(Node* root);

	Node* Delete(Node* root, size_t receipt);

	Receipt GetNext(Node* root, const Receipt& receipt);
}