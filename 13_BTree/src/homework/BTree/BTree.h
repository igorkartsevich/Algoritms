#pragma once
#include "Node.h"
#include <vector>

class BTree {
    Node* root;

public:
    BTree() {
        root = new Node();
    }

    // Добавляет число X в дерево
    void add(int key);

    // Проверяет, было ли число X добавлено в дерево
    bool contains(int x);

    // Выводит текущую максимальную глубину дерева
    int getMaxHeight();

    // Возвращает список всех чисел, добавленных в дерево в возрастающем порядке
    std::vector<int> getSorted();
};
