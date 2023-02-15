#include "Tree.h"
#include "TestNode.h"
#include <iostream>
#include <cassert>
#include <algorithm>

int maxDepth(Node* node) {
    if (!node)
        return 0;
    else {
        //std::vector<int> depths;
        std::vector<int> depths = {0}; 
        for (auto& n : node->v) {
            depths.emplace_back(maxDepth(n));
        }
        //return 1 + depths.size() != 0 ? *std::max_element(depths.begin(), depths.end()) : 0;
        return depths.size() != 0 ? 1 + *std::max_element(depths.begin(), depths.end()) : 0;
    }
}

int getRandomNumber(int min, int max) {
    //return min + rand() % max;
    return min + rand() % (max - min);
}

void treeGen(TestNode* root, int maxChild, int maxDepth, int currentDepth, std::vector<TestNode*>& set) {
    if (currentDepth == maxDepth) return;
    int child = getRandomNumber(0, maxChild);
    TestNode *testNode = new TestNode(currentDepth);
    root->v.push_back(testNode);
    testNode->setParent(root);
    set.push_back(testNode);
    currentDepth++;
    for (int i = 0; i < child; i++) {
        treeGen(testNode, maxChild, maxDepth, currentDepth, set);
    }
}

TestNode* treeCreator(int maxChild, int maxDepth, std::vector<TestNode*>& set) { //std::vector<TestNode*> set
    TestNode* testNode = new TestNode(0);
    set.push_back(testNode);
    treeGen(testNode, maxChild, maxDepth, 1, set);
    return testNode;
}

void testDepth() {
    std::cout << "Tree depth" << std::endl;
    assert(0 == Tree::fromList(nullptr));
    TestNode test(0);
    assert(1 == Tree::fromList(&test));

    auto node = treeCreator(2, 5, std::vector<TestNode*>());
    assert(Tree::fromList(node) == maxDepth(node));

    node = treeCreator(10, 10, std::vector<TestNode*>());
    assert(maxDepth(node) == Tree::fromList(node));

    node = treeCreator(10, 8, std::vector<TestNode*>());
    assert(maxDepth(node), Tree::fromList(node));
}

void buildTree(int minDepth) {
   std::cout << "Build tree #" << minDepth <<std::endl;
   std::vector<TestNode*> set;
    auto testNode = treeCreator(10, minDepth, set);
    auto depth = maxDepth(testNode); 
    for (size_t i = 0; i < set.size(); ++i) {
        //set[i]->setId(++i);
        set[i]->setId(i + 1); 
    }
    std::vector<int> links(set.size());
    for (int i = 0; i < links.size(); i++) {
        //set[i]->getParent();
        if (!set[i]->getParent()) 
            links[i] = -1;
        else
            links[i] = set[i]->getParent()->getId();
    }
    std::vector<Virus> arr;
    for (auto& item : set) {
        arr.push_back(item->getVirus());
    }
    assert(depth == maxDepth(Tree::fromList(links, arr)));
}

void currentDepth(int minDepth) {
    std::cout << "allOnCurrDepth. Build tree #" << minDepth << std::endl;
    std::vector<TestNode*> set;
    auto testNode = treeCreator(10, minDepth, set);
    std::vector<TestNode*> currDepth;
    for (auto& cur : set) {
        if (cur->getCurrentDepth() == minDepth - 1) {
            currDepth.push_back(cur);
        }
    }

    auto userLst = Tree::allOnCurrDepth(testNode, minDepth - 1);
    for (auto& cur : currDepth) {
        assert(std::find(userLst.begin(), userLst.end(), cur) != userLst.end());
    }
    for (auto& cur : userLst) {
        assert(std::find(userLst.begin(), userLst.end(), cur) != userLst.end());
    }
}

void lcaTest(int minDepth) {
    std::cout << "LCA. Build #" << minDepth << std::endl;
    std::vector<TestNode*> list;
    auto testNode = treeCreator(10, minDepth, list); 
    auto first = list[0];
    auto second = list[list.size() - 1];

    std::vector<TestNode*> firstParents;
    TestNode* node = first;
    while (true) {
        firstParents.push_back(node);
        if (!node->getParent()) { 
            break; 
        }
        node = node->getParent();
    }

    std::vector<TestNode*> secondParents;
    node = second;
    while (true) {
        secondParents.push_back(node);
        if (!node->getParent()) break;
        node = node->getParent();
    }
    auto newFirst = std::remove_if(firstParents.begin(), firstParents.end(),
        [&secondParents](TestNode* val) {return std::find(secondParents.begin(), secondParents.end(), val) != secondParents.end(); });
    firstParents.erase(newFirst, firstParents.end());
    auto ans = firstParents.size() > 0 ? *std::min_element(firstParents.begin(), firstParents.end(), 
        [](TestNode* a, TestNode* b) {return a->getCurrentDepth() < b->getCurrentDepth(); }) : testNode;
    assert(ans == Tree::lca(first, second));
}

int main() {
    testDepth();
    for (auto &minDepth : { 5, 6, 7, 8, 9 }) {        
        buildTree(minDepth);
        currentDepth(minDepth);
        //lcaTest(minDepth);
    }
  std::cout << "All tests passed successfully! Congrats";
  return 0;
}