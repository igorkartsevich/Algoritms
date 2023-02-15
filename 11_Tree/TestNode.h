#pragma once
#include "Node.h"

class TestNode : public Node {
private:
    int m_id = -1;
    TestNode* parent = nullptr;
    int m_currentDepth;

public:
    TestNode(int currentDepth) : Node() {
        this->m_currentDepth = currentDepth;
    }
    virtual ~TestNode() {}

    int getId();
    TestNode* getParent();
    void setId(int id);
    void setParent(TestNode* parent);
    int getCurrentDepth();
};