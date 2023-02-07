#pragma once

#include "Virus.h"
#include "Node.h"
#include <vector>

class Tree {
public:
    Tree() {}
    virtual ~Tree() {}

    static int fromList(Node* root) {
        return -1;
    }

    static Node* fromList(const std::vector<int> &index, std::vector<Virus> &elements) {
        return nullptr;
    }

    static std::vector<Node*> allOnCurrDepth(Node* root, int generation) {
        return {};
    }

    static Node* lca(Node* first, Node* second) {
        return nullptr;
    }
};
