#pragma once
#include "..\Solution\Node.h"
#include <vector>
#include <algorithm>

namespace HomeworkCheck::BST {

	using namespace std;
	using Homework::BST::Receipt;
	using Homework::BST::Node;

	Node* FromList(const vector<Receipt>& elements);

	vector<Receipt> FromNode(Node* root);
	
	size_t MaxDepth(Node* root);

	bool IsBST(Node* root);

	double GetAmount(Node* root, size_t receiptNumber);

	bool CheckTree(Node* root);

	Node* Delete(Node* root, size_t receipt);

	Receipt GetNext(Node* root, const Receipt& receipt);
}