#pragma once
#include <vector>

class Virus {
public:
    Virus() {};
    virtual ~Virus() {};
};

class Node {
public:
    Node() {};

    Node(Virus virus) {
        this->virus = virus;
    }

    virtual ~Node() {

    }

    Virus getVirus() {
        return virus;
    }

    std::vector<Node*> v;
protected:
    Virus virus;    
};


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
