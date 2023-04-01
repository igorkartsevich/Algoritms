#pragma once
#include "Contact.h"
#include <vector>

// Этот класс должен быть реализован при помощи бора (trie)
class ContactBook {
public:

    class Node {
    public:
        std::vector<Node*> nextNode{ 256 };
        std::string phoneNumber;
        Node() {
            for (int i = 0; i < 256; ++i) {
                nextNode[i] = nullptr;
            }
        }
        Node* getNextNode(char key);
        Node* addNewNode(char key);
        Node* getSubTreeRoot(const std::string& pref);
    };

    Node* root;

    ContactBook() {
        root = new Node();
    }

    ~ContactBook() {
        delete root;
    }

    // Добавляет имя нового контакта в адресную книгу
    void add(Contact s);

    // Возвращает true, если контакт с именем name есть в книге
    bool contains(const std::string& name);

    // Возвращает количество контактов, добавленных в адресную книгу, имена которых начинаются с pref
    int count_starts_with(const std::string& pref);

    // Возвращает все контакты, имена которых начинаются с преффикса pref
    std::vector<Contact> starts_with(const std::string& pref);
};
