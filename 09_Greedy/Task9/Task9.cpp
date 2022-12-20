#include "pch.h"
#include "framework.h"
#include "WorkPlanner.h"
#include "HuffmanCode.h"
#include "..\TestTask9\_WorkPlanner.h"
#include "..\TestTask9\_HuffmanCode.h"
#include <set>
#include <map>
#include <algorithm>
#include <string>

namespace Homework::WorkPlanner {

    size_t FindMaximumIncome(const std::vector<size_t>& workRates, size_t hours) {
        std::multiset<int> ratesSet;
        for (auto rate : workRates)
            ratesSet.emplace(rate);

        size_t profit{};
        std::for_each(rbegin(ratesSet), (hours < ratesSet.size()) ? rbegin(ratesSet) + hours : ratesSet.size(),
            [&profit](int rate) { profit += rate; });

        return profit;
    }

    size_t FindMinimumManagers(const std::vector<std::pair<std::time_t, std::time_t>>& intervals) {
        if(intervals.size() == 0) return 0;

        using map_type = std::map<std::time_t, std::time_t>;
        map_type mapOfIntervals(begin(intervals), end(intervals));

        auto getIterator = [&mapOfIntervals](map_type::iterator it) {
            while (it != end(mapOfIntervals) && it->second == 0)
                ++it;
            return it;
        };

        auto mark_0_usedIntervals = [&mapOfIntervals, getIterator](map_type::iterator it) {
            while (it != end(mapOfIntervals)) {
                auto it_next = getIterator(mapOfIntervals.upper_bound(it->second));
                it->second = 0;
                it = it_next;
            }
        };

        size_t employees{};
        while (true) {
            auto start_it = getIterator(begin(mapOfIntervals));

            if (start_it != end(mapOfIntervals)) {
                ++employees;
                mark_0_usedIntervals(start_it);
            }

            else return employees;;
        }
    }

    double LoadTruck(size_t truckCapacity, const std::vector<std::pair<size_t, size_t>>& goods) {
        using map_type = std::multimap<double, std::pair<size_t, size_t>>;
        map_type mapGoods;

        for (auto good : goods)
            mapGoods.emplace(good.second / good.first, good);

        double cost{};
        auto it = rbegin(mapGoods);
        while (it != rend(mapGoods)) {
            if (int(truckCapacity - it->second.first) > 0) {
                truckCapacity -= it->second.first;
                cost += it->second.second;
                ++it;
            }
            else {
                cost += (double)truckCapacity / it->second.first * it->second.second;
                break;
            }
        }

        return cost;
    }

}

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