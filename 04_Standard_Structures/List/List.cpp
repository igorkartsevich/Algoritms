#include "List.h"

void List::push_front(int x) {
    Node* node = new Node(x);
    node->next = begin;
    begin = node;
}

// This function could be useful for debugging and testing.
void List::print() {
    Node* n = begin;
    while (n != nullptr) {
        std::cout << n->x << " ";
        n = n->next;
    }
    std::cout << std::endl;
}

// This function should return copy of the list where every second element is removed.
// Initial list should not be changed.
// E.g. if we run copyEverySecond on list [1, 2, 3, 4, 5, 6, 7, 100, 120, 162, 0, 1]
// new list with values [1, 3, 5, 7, 120, 0] should be returned.
List List::copyEverySecond() {
    /* TODO IMPLEMENT THIS */
    int counter{};
    Node* node = begin;
    std::vector<int> tmp;
    while (node != nullptr) {
        if (counter % 2 == 0) {
            tmp.push_back(node->x);
        }
        ++counter;
        node = node->next;
    }

    List l;
    for (int i = (int)tmp.size() - 1; i >= 0; --i)
        l.push_front(tmp[i]);
    return l;
}

// Returns number of elements in list
int List::getSize() {
    /* TODO IMPLEMENT THIS */
    int counter{};
    Node* node = begin;
    while (node != nullptr) {
        ++counter;
        node = node->next;
    }
    return counter;
}

// This function converts our list to an array. New array is created with values the same as in list.
std::vector<int> List::toArray() {
    /* TODO IMPLEMENT THIS */
    std::vector<int> array;

    Node* node = begin;

    while (node != nullptr) {
        array.push_back(node->x);
        node = node->next;
    }

    return array;
}

// This function removes elements x.next from the list
// O(1) time is expected
void List::removeAfter(Node* x) {
    /* TODO IMPLEMENT THIS */
    Node* node = begin;
    Node* nodeTMP = nullptr;

    while (node != nullptr) {
        if (node == x)
            break;
        else node = node->next;
    }

    if (node->next == nullptr) return;

    nodeTMP = node->next->next;
    node->next = nodeTMP;
}

// This function inserts new element with value val right after the element x.
// O(1) time is expected
void List::insertAfter(Node* x, int val) {
    /* TODO IMPLEMENT THIS */
    Node* node = begin;
    while (node != nullptr) {
        if (node = x)
            break;
        else node = node->next;
    }
    Node* node_new = new Node(val);
    node_new->next = node->next;
    node->next = node_new;
}

// This function removes all elements from the list that are divisible by x.
// E.g. list {1, 2, 3, 4, 4, 10, 7}  after filterDivisible(2) would look like {1, 3, 7}.
// O(N) time is expected.
void List::filterDivisible(int x) {
    /* TODO IMPLEMENT THIS */
    Node* node = begin;
    Node* nodeTMP = begin->next;
    bool is_beginCorrect = (begin->x % x != 0);

    while (nodeTMP != nullptr) {
        if (nodeTMP->x % x != 0) {
            if (!is_beginCorrect) {
                begin = nodeTMP;
                is_beginCorrect = true;
            }
            node->next = nodeTMP;
            node = nodeTMP;
        }
        nodeTMP = nodeTMP->next;
    }

    node->next = nullptr;
    if (!is_beginCorrect) begin = nullptr;
}

// This function returns Node from the list by index. O(N) time is expected.
List::Node* List::getAt(int index) {
    /* TODO IMPLEMENT THIS */
    Node* node = begin;
    int counter{};
    while (node != nullptr) {
        if (counter == index)
            return node;
        node = node->next;
        ++counter;
    }
    return nullptr;
}