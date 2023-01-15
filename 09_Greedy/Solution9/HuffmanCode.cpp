#include "HuffmanCode.h"
#include "..\Task9\HuffmanCode.h"
#include <map>

namespace TaskHuffmanCode {

    class Node {
    public:
        Node(int inCharCode)
            : charCode(inCharCode), left(nullptr), right(nullptr) {}

        Node(Node* inLeft, Node* inRight)
            : charCode(inLeft->charCode + inRight->charCode), left(inLeft), right(inRight) {}

        int getCharCode() {
            return charCode;
        }
        Node* getNextLeft() {
            return left;
        }
        Node* getNextRight() {
            return right;
        }

    private:
        int charCode;
        Node* left;
        Node* right;
    };

    void getHuffmanTree(Node*& root, const std::string& text) {
        int base[256] = { 0 };
        for (const auto& ch : text)
            ++base[(int)ch];

        std::multimap<size_t, size_t> huffmanTree; 
        for (auto i = 0; i < 256; ++i)
            if (base[i] > 0)
                huffmanTree.emplace(base[i], i); // base[i] - friquency, i - charCode

        auto it = begin(huffmanTree);
        root = new Node(it->second);

        while (++it != end(huffmanTree)) {
            Node* leaf = new Node(it->second); // it->second - charCode
            root = new Node(leaf, root);
        }
    }

    void getHuffmanCode(Node*& inRoot, std::string& codeRecord, const std::string& text) {
        Node* root = inRoot;

        for (const auto& ch : text) {
            if (root->getNextRight() == nullptr) { //if in huffmanTree only one leaf (root is leat)
                codeRecord += "1";
                continue;
            }
            else {
                while (root->getNextRight() != nullptr) { 
                    if (root->getNextLeft()->getCharCode() == (int)ch) { // to left -> '0'
                        codeRecord += "0";
                        break;
                    }
                    else { // to right -> '1'
                        codeRecord += "1";
                        root = root->getNextRight();
                    }
                }
            }
        }

        return;
    }

    unsigned __int64 EncodeHuffman(const std::string& text) {
        if (text.length() == 0) return 0;

        Node* root = nullptr;
        getHuffmanTree(root, text);

        std::string codeRecord = "";
        getHuffmanCode(root, codeRecord, text);

        return std::stoull(codeRecord, nullptr, 2);
    }
}