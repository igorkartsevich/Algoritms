#include "HuffmanCode.h"
#include "..\TestTask9\HuffmanCode.h"
#include <map>

namespace Homework::HuffmanCode {

    class Node {
    public:
        Node(int inCharCode)
            : CharCode(inCharCode), left(nullptr), right(nullptr) {}

        Node(Node* inLeft, Node* inRight)
            : CharCode(inLeft->CharCode + inRight->CharCode), left(inLeft), right(inRight) {}

        int getCharCode() {
            return CharCode;
        }
        Node* getNextLeft() {
            return left;
        }
        Node* getNextRight() {
            return right;
        }

    private:
        int CharCode;
        Node* left;
        Node* right;
    };

    void makeBase(std::multimap<int, int>& baseByFrequency, const std::string& text) {
        int base[256] = { 0 };
        for (const auto& ch : text)
            ++base[(int)ch];

        for (size_t i{}; i < 256; ++i)
            if (base[i] != 0)
                baseByFrequency.emplace(base[i], i);
    }

    void makeHuffmanCode(Node*& root, const std::multimap<int, int>& baseByFrequency, std::multimap<int, int>::iterator it, Node* nodeRight) {
        while (++it != end(baseByFrequency)) {
            Node* nodeLeft = new Node(it->second);
            root = new Node(nodeLeft, nodeRight);
            nodeRight = root;
        }
    }

    void makeCoding(Node*& const inRoot, std::string& codeRecord, const std::string& text) {
        for (const auto& ch : text) {
            Node* root = inRoot;

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
    }

    unsigned __int64 EncodeHuffman(const std::string& text) {
        std::multimap<int, int> baseByFrequency;
        makeBase(baseByFrequency, text);

        Node* root = nullptr;
        Node* rightNode = new Node(begin(baseByFrequency)->second);
        makeHuffmanCode(root, baseByFrequency, begin(baseByFrequency), rightNode);

        std::string codeRecord = "";
        makeCoding(root, codeRecord, text);

        return std::stoull(codeRecord, nullptr, 2);
    }
}