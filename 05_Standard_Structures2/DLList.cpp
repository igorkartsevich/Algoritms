#include "DLList.h"

void DLList::push_front(int x)
{
	Node* newNode = new Node(x);

	if (size == 0)
		begin = end = newNode;
	else {
		newNode->next = begin;
		begin->prev = newNode;
		begin = newNode;
	}

	++size;
}

void DLList::push_back(int x)
{
	Node* newNode = new Node(x);

	if (size == 0)
		begin = end = newNode;
	else {
		newNode->prev = end;
		end->next = newNode;
		end = newNode;
	}

	++size;
}

void DLList::print() {
	if (begin == nullptr) throw DLListEmpty_Exception();

    Node* n = begin;
    while (n != nullptr) {
        std::cout << n->x << " ";
        n = n->next;
    }
    std::cout << std::endl;
}

int DLList::getSize()
{
	return size;
}

std::vector<int> DLList::toArray()
{
	std::vector<int> res(size);

	if (begin == nullptr) throw DLListEmpty_Exception();

	int counter{};
	Node* node = begin;

	while (node != nullptr) {
		res[counter] = node->x;
		node = node->next;
		++counter;
	}

	return res;
}

void DLList::remove(Node* x)
{
	if (x == nullptr) throw WrongNodeInArgument_Exception();
	if (begin == nullptr) throw DLListEmpty_Exception();

	Node* node = begin;
	while (node != x)
		node = node->next;
	
	if (node == nullptr) throw NodeIsNotFound_Exception();

	if (size == 1)
		begin = end = nullptr;
	else {
		if (node->next == nullptr) {
			node->prev->next = nullptr;
			end = node->prev;
		}
		else if (node->prev == nullptr) {
			node->next->prev = nullptr;
			begin = node->next;
		}
		else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
	}
	
	--size;
}

int DLList::pop_front()
{
	if (begin == nullptr) throw DLListEmpty_Exception();

	int res{ begin->x };

	if (size == 1)
		begin = end = nullptr;
	else {
		Node* node = begin->next;
		node->prev = nullptr;
		begin = node;
	}

	--size;
	return res;
}

int DLList::pop_back()
{
	if (end == nullptr) throw DLListEmpty_Exception();

	int res{ end->x };

	if (size == 1)
		begin = end = nullptr;
	else {
		Node* node = end->prev;
		node->next = nullptr;
		end = node;
	}

	--size;
	return res;
}

void DLList::insertAfter(Node* x, int val)
{
	if (x == nullptr) throw WrongNodeInArgument_Exception();
	if (begin == nullptr) throw DLListEmpty_Exception();

	Node* node = begin;
	while (node != x)
		node = node->next;

	if (node == nullptr) throw NodeIsNotFound_Exception();

	Node* newNode = new Node(val);
	if (node->next != nullptr) {
		node->next->prev = newNode;
		newNode->next = node->next;
	}
	else
		end = newNode;

	newNode->prev = node;
	node->next = newNode;
	++size;
}

DLList::Node* DLList::getAt(int index)
{
	if (begin == nullptr) throw DLListEmpty_Exception();

	int counter{};
	Node* node = begin;
	while (counter++ < index)
		node = node->next;

	if (node == nullptr) throw NodeIsNotFound_Exception();

	return node;
}

DLList DLList::fromArray(const std::vector<int>& a) {
	DLList l;
	for (int i = 0; i < a.size(); ++i) {
		l.push_back(a[i]);
	}
	return l;
}

const char* DLListEmpty_Exception::what() const noexcept
{
	return "ERROR! DLList is empty.";
}

const char* NodeIsNotFound_Exception::what() const noexcept
{
	return "ERROR! Node is not found.";
}

const char* WrongNodeInArgument_Exception::what() const noexcept
{
	return "ERROR! Wrong node is in argument.";
}
