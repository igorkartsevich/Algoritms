#pragma once

#include "Virus.h"
#include "Node.h"
#include <vector>

class Tree {
public:
    Tree() {}
    virtual ~Tree() {}

    static int fromList(Node* root);

    static Node* fromList(const std::vector<int>& index, std::vector<Virus>& elements);

    static std::vector<Node*> allOnCurrDepth(Node* root, int generation);

    //static Node* lca(Node* first, Node* second);
};
