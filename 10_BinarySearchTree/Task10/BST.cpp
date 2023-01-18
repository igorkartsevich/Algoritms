#include "BST.h"

namespace HomeworkCheck::BST {

	using namespace std;
	using Homework::BST::Receipt;
	using Homework::BST::Node;

	bool IsLeaf(Node* it) {
		return !it->left && !it->right;
	}

	Node* MakeBST(const vector<Receipt>& el, size_t l, size_t r, Node* parent) {
		if (l + 1 > r) return nullptr;
		else if (l + 1 == r) return new Node(el[l], parent);
		else {
			size_t m = (l + r) / 2;
			Node* top = new Node(el[m], parent);
			top->left = MakeBST(el, l, m, top);
			top->right = MakeBST(el, m + 1, r, top);
			return top;
		}
	}

	Node* FromList(const vector<Receipt>& elements) {
		vector<Receipt> el = elements;
		sort(el.begin(), el.end(), [](Receipt l, Receipt r) {
			return l.receiptNumber < r.receiptNumber; });
		return MakeBST(el, 0, el.size(), nullptr);
	}

	size_t MaxDepth(Node* root) {
		if (!root) return 0;
		size_t l = MaxDepth(root->left);
		size_t r = MaxDepth(root->right);
		return l > r ? l + 1 : r + 1;
	}

	bool IsBSTSubTree(Node* root, size_t minVal, size_t maxVal) {
		if (!root) return true;
		else if (root->x.receiptNumber<minVal || root->x.receiptNumber>maxVal) return false;
		else return IsBSTSubTree(root->left, minVal, root->x.receiptNumber - 1) &&
			IsBSTSubTree(root->right, root->x.receiptNumber + 1, maxVal);
	}

	bool IsBST(Node* root) {
		return IsBSTSubTree(root, 0, SIZE_MAX);
	}

	void PushVector(vector<Receipt>& ret, Node* root) {
		if (!root) return;
		PushVector(ret,root->left);
		ret.push_back(root->x);
		PushVector(ret, root->right);
	}

	vector<Receipt> FromNode(Node* root) {
		vector<Receipt> ret;
		PushVector(ret,root);
		return ret;
	}

	Node* Find(Node* root, size_t receipt) {
		if (!root) return nullptr;
		if (receipt == root->x.receiptNumber) return root;
		Node* next = receipt < root->x.receiptNumber ? root->left : root->right;
		return Find(next, receipt);
	}


	double GetAmount(Node* root, size_t receiptNumber) {
		Node* it = Find(root, receiptNumber);
		return !it ? 0.0 : it->x.amount;
		if (!it) return 0.0;
	}

	bool CheckTree(Node* root) {
		if (!root) return true;
		if ((root->left && root->x.receiptNumber <= root->left->x.receiptNumber) ||
			(root->right && root->x.receiptNumber >= root->right->x.receiptNumber)) return false;
		else return CheckTree(root->left) && CheckTree(root->right);
	}

	Node* Min(Node* root) {
		return !root->left ? root : Min(root->left);
	}

	Node* DeleteNode(Node** root, size_t receipt) {
		if (!*root) return nullptr;
		if (receipt < (*root)->x.receiptNumber)
			(*root)->left = DeleteNode(&((*root)->left), receipt);
		else if (receipt > (*root)->x.receiptNumber)
			(*root)->right = DeleteNode(&((*root)->right), receipt);
		else if ((*root)->left && (*root)->right) {
			(*root)->x = Min((*root)->right)->x;
			(*root)->right = DeleteNode(&((*root)->right), (*root)->x.receiptNumber);
		}
		else {
			if ((*root)->left)
				*root = (*root)->left;
			else if ((*root)->right)
				*root = (*root)->right;
			else *root = nullptr;
		}
		return *root;
	}
	
	Node* Delete(Node* root, size_t receipt) {
		return DeleteNode(&root, receipt);
	}

	Receipt _GetNext(Node* it) {
		if (it->right) return Min(it->right)->x;
		Node* p = it->parent;
		while (p && it == p->right) {
			it = p;
			p = p->parent;
		}
		return !p ? Receipt{}:p->x;
	}

	Receipt GetNext(Node* root, const Receipt& receipt) {
		Node* it = Find(root, receipt.receiptNumber);
		return _GetNext(it);
	}
}
