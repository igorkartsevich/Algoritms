#include "TreeSolution.h"
#include "TestNode.h"
#include <stack>
#include <queue>

//***************************************************

int Tree::fromList(Node* root) {
    if (root == nullptr) return 0;
    
    struct ToRemember {
        Node* nodeToRememder;
        int currentDepth;
        ToRemember(Node* _node, int _depth) : nodeToRememder(_node), currentDepth(_depth) {};
    };

    std::stack<ToRemember> stackToRemeber;
    int maxDepth{ 1 }, currentDepth{ 1 };
    auto currentNode = root;

    while(true){
        if (!currentNode->v.empty()) {
            if(++currentDepth > maxDepth) ++maxDepth;

            for (auto i = 1; i < currentNode->v.size(); ++i)
                stackToRemeber.push(ToRemember(currentNode->v[i], currentDepth));

            currentNode = currentNode->v[0];
        }
        else {
            if (stackToRemeber.empty()) return maxDepth;

            else {
                currentNode = stackToRemeber.top().nodeToRememder;
                currentDepth = stackToRemeber.top().currentDepth;
                stackToRemeber.pop();
            }
        }
    }
}

//***************************************************

Node* Tree::fromList(const std::vector<int>& index, std::vector<Virus>& elements) {
    auto size = index.size();
    std::vector<Node*> treeTMP(size, nullptr);
    
    for (int i{}; i < size; ++i) {
        treeTMP[i] = new Node(elements[i]);
        if (index[i] > 0)
            treeTMP[index[i] - 1]->v.push_back(treeTMP[i]);
    }

    std::vector<Node*> tree;
    for (auto& node : treeTMP)
        if (!node->v.empty()) tree.push_back(node);

    return tree[0];
}

//***************************************************

std::vector<Node*> Tree::allOnCurrDepth(Node* root, int generation) {
    std::vector<Node*> vectorGeneration;
    if (root == nullptr) return vectorGeneration;

    struct ToRemember {
        Node* node;
        int generation;
        ToRemember(Node* _node, int _generation) : node(_node), generation(_generation) {};
    };

    Node* currentNode = root;
    std::queue<ToRemember> queueToRemember;
    int currentGeneration{0};

    while (true) {
        if (!currentNode->v.empty()) {
            if (++currentGeneration < generation) {
                for (int i{ 1 }; i < currentNode->v.size(); ++i)
                    queueToRemember.push(ToRemember(currentNode->v[i], currentGeneration));
                currentNode = currentNode->v[0];
                continue;
            }
            else
                for (auto& node : currentNode->v)
                    vectorGeneration.emplace_back(node);
        }

        if (queueToRemember.empty()) return vectorGeneration;
        else {
            currentNode = queueToRemember.front().node;
            currentGeneration = queueToRemember.front().generation;
            queueToRemember.pop();
        }
    }

    return vectorGeneration;
}

//***************************************************

Node* Tree::lca(TestNode* first, TestNode* second) { //Node* Tree::lca(Node* first, Node* second)
    auto node1 = first;
    auto node2 = second;
    int node1Depth = first->getCurrentDepth();
    int node2Depth = second->getCurrentDepth();

    if (node1Depth < node2Depth)
        for (int i{}; i < node2Depth - node1Depth; ++i)
            node2 = node2->getParent();
    else
        for (int i{}; i < node1Depth - node2Depth; ++i)
            node1 = node1->getParent();

    while (node1 != node2) {
        node1 = node1->getParent();
        node2 = node2->getParent();
    }

    return node1;
}
