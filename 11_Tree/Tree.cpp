#include "Tree.h"
#include <stack>

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

static std::vector<Node*> allOnCurrDepth(Node* root, int generation) {
    return {};
}

static Node* lca(Node* first, Node* second) {
    return nullptr;
}
