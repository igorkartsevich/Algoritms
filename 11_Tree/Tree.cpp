#include "Tree.h"
#include "TestNode.h"
#include <stack>
#include <queue>

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

std::vector<Node*> Tree::allOnCurrDepth(Node* root, int generation) {
    std::vector<Node*> vectorGeneration;
    if (root == nullptr) return vectorGeneration;

    Node* currentNode = root;
    std::queue<Node*> queueNode;
    std::queue<int> queueGeneration;

    int currentGeneration{0};

    while (true) {
        if (!currentNode->v.empty()) {
            if (++currentGeneration < generation) {
                for (int i{ 1 }; i < currentNode->v.size(); ++i) {
                    queueNode.push(currentNode->v[i]);
                    queueGeneration.push(currentGeneration);
                }
                currentNode = currentNode->v[0];
                continue;
            }
            else
                for (auto& node : currentNode->v)
                    vectorGeneration.emplace_back(node);
        }

        if (queueNode.empty()) return vectorGeneration;
        else {
            currentNode = queueNode.front();
            queueNode.pop();
            currentGeneration = queueGeneration.front();
            queueGeneration.pop();
        }
    }

    return vectorGeneration;
}

Node* Tree::lca(TestNode* first, TestNode* second) {

    return nullptr;
}
