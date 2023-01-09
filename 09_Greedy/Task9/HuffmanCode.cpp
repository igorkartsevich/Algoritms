#include "HuffmanCode.h"
#include "..\TestTask9\HuffmanCode.h"
#include <map>
#include <queue>

namespace TaskHuffmanCode {

    class Node {
    public:
        Node(int inWeight)
            : weight(inWeight), left(nullptr), right(nullptr) {}

        Node(Node* inLeft, Node* inRight)
            : weight(inLeft->weight + inRight->weight), left(inLeft), right(inRight) {}

        int getCharCode() {
            return weight;
        }
        Node* getNextLeft() {
            return left;
        }
        Node* getNextRight() {
            return right;
        }

    private:
        int weight;
        Node* left;
        Node* right;
    };

    void makeHuffmanTree(Node*& root, const std::string& text) {
        int base[256] = { 0 };
        for (const auto& ch : text)
            ++base[(int)ch];
        
        


    }

    void makeCoding(Node*& const inRoot, std::string& codeRecord, const std::string& text) {
        for (const auto& ch : text) {
            Node* root = inRoot;

            if (root->getNextRight() == nullptr) {
                codeRecord += "1";
                continue;
            }
            else {
                while (root->getNextRight() != nullptr) {
                    if (root->getNextLeft()->getCharCode() == (int)ch) {
                        codeRecord += "0";
                        break;
                    }
                    else {
                        codeRecord += "1";
                        root = root->getNextRight();
                    }
                }
            }
            return;
        }
    }

    unsigned __int64 EncodeHuffman(const std::string& text) {
        if (text.length() == 0) return 0;

        Node* root = nullptr;
        makeHuffmanTree(root, text);

        std::string codeRecord = "";
        makeCoding(root, codeRecord, text);

        return std::stoull(codeRecord, nullptr, 2);
    }
}