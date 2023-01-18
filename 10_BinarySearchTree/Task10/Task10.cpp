// Task10.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "BST.h"
#include "..\TestTask10\_BST.h"
#include <vector>

namespace Homework::BST {

	Node* Homework::BST::FromList(const std::vector<Receipt>& elements) {
		return HomeworkCheck::BST::FromList(elements);
	}

	std::vector<Receipt> FromNode(Node* root) {
		return HomeworkCheck::BST::FromNode(root);
	}

	double GetAmount(Node* root, size_t receiptNumber) {
		return HomeworkCheck::BST::GetAmount(root, receiptNumber);
	}

	bool CheckTree(Node* root) {
		return HomeworkCheck::BST::CheckTree(root);
	}

	Node* Delete(Node* root, size_t receipt) {
		return HomeworkCheck::BST::Delete(root, receipt);
	}

	Receipt GetNext(Node* root, const Receipt& receipt) {
		return HomeworkCheck::BST::GetNext(root, receipt);
	}


}