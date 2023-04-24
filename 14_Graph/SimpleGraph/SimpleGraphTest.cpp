#include "SimpleGraph.h"
#include <cassert>
#include <iostream>
#include <set>
#include <queue>

std::string BFS(Node* start)
{
    std::set<std::string> seen; //std::set<Node*> seen
    std::queue<Node*> queue;
    std::string result = "";

    seen.insert(start->val); //seen.insert(start)
    queue.push(start);

    while (!queue.empty())
    {
        auto current = queue.front();
        queue.pop();
        result += current->val;

        for (int i{}; i < current->neighbors.size(); ++i) {
            if (seen.count(current->neighbors[i]->val) == 0) {
                seen.insert(current->neighbors[i]->val);
                queue.push(current->neighbors[i]);
            }
        }

        /*auto i = current->neighbors.begin();
        while (++i != current->neighbors.end())
        {
            auto next = i;
            if (0 == seen.count(*next))
            {
                seen.insert(*next);
                queue.push(*next);
            }
        }*/
    }
    return result;
}

void getImportanceTest(const std::vector<Employee*>& employees, int id, int importance)
{
    std::cout << "Get importance of employee" << std::endl;
    auto actual = SimpleGraph::getImportance(employees, id);
    auto expected = importance;

    assert(expected == actual);
}

void cloneGraphVKTest(Node* node)
{
    std::cout << "Help Ivan copy VK Graph" << std::endl;
    auto actual = BFS(SimpleGraph::cloneGraphVK(node));
    auto expected = BFS(node);

    assert(expected == actual);
}

int main(){
    {
        std::vector<Employee*> vec;
        vec.emplace_back(new Employee{1, 5, {2, 3}});
        vec.emplace_back(new Employee{2, 3, {}});
        vec.emplace_back(new Employee{3, 3, {}});
        getImportanceTest(vec, 1, 11);
        for (auto& ptr: vec){
            delete ptr;
        }
    }

    {
        std::vector<Employee*> vec;
        vec.emplace_back(new Employee{4, 15, {5}});
        vec.emplace_back(new Employee{5, 10, {6}});
        vec.emplace_back(new Employee{6, 5, {}});
        getImportanceTest(vec, 4, 30);
        for (auto& ptr: vec){
            delete ptr;
        }
    }

    auto ak1 = new Node("Ivan");
    auto ak2 = new Node("Maria");
    auto ak3 = new Node("Kate");
    auto ak4 = new Node("Peter");
    auto ak5 = new Node("Anna");
    auto ak6 = new Node("Emma");

    ak1->neighbors = {ak2, ak3};
    ak2->neighbors = {ak1, ak4};
    ak3->neighbors = {ak1, ak4};
    ak4->neighbors = {ak2, ak3, ak5, ak6};
    ak5->neighbors = {ak4};
    ak6->neighbors = {ak4};

    cloneGraphVKTest(ak1);
    cloneGraphVKTest(ak2);
    cloneGraphVKTest(ak3);
    cloneGraphVKTest(ak4);
    cloneGraphVKTest(ak5);
    cloneGraphVKTest(ak6);
    
    return 0;
}
