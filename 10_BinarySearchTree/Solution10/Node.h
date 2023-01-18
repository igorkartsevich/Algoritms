#pragma once

#include "Receipt.h"


namespace Homework::BST {

	struct Node {
		Receipt x;
		Node* left = nullptr;
		Node* right = nullptr;
		Node* parent;
		Node(const Receipt& rec, Node* _parent) :x(rec), parent(_parent) {}
		~Node() {
			if (left) delete left;
			if (right) delete right;
		}
	};

}