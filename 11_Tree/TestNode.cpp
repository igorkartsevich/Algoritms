#include "TestNode.h"

int TestNode::getId() {
    return m_id;
};

TestNode* TestNode::getParent() {
    return parent;
};

void TestNode::setId(int id) {
    this->m_id = id;
}

void TestNode::setParent(TestNode* parent) {
    this->parent = parent;
}

int TestNode::getCurrentDepth() {
    return m_currentDepth;
}