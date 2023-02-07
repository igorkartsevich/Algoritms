#pragma once

#include "Node.h"
#include "Virus.h"
#include <vector>

class Node {

public:
    Node() {};

    Node(Virus virus) : m_virus(virus) {}

    virtual ~Node() {}

    Virus getVirus();

    std::vector<Node*> v;

protected:
    Virus m_virus;

};
