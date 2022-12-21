#include "HuffmanCode.h"
#include <unordered_map>
#include <algorithm>
#include <queue>

namespace HomeworkCheck::HuffmanCode {

	using namespace std;

	struct Node {
		char ch = '\0';
		size_t count;
		Node* zero = nullptr;
		Node* one = nullptr;
		Node(char _ch, size_t _count) :ch(_ch), count(_count) {}
		Node(size_t _count, Node* _zero, Node* _one) :count(_count), zero(_zero), one(_one) {}
		~Node() {
			if (zero != nullptr) delete zero;
			if (one != nullptr) delete one;
		}
		bool IsLeaf() { return !zero && !one; }
	};

	template<typename Node*>
	struct less {
		bool operator ()(const Node* l, const Node* r) {
			return l->count < r->count;
		}
	};

	bool operator <(const Node& l, const Node& r) {
		return l.count < r.count;
	}

	void Encode(Node* root, string str, unordered_map<char, string>& hash) {
		if (!root) return;
		if (root->IsLeaf())
			hash.insert({ root->ch,str.length() > 0 ? str : "1" });
		Encode(root->zero, str += "0", hash);
		Encode(root->one, str += "1", hash);
	}

	unsigned __int64 EncodeHuffman(const std::string& text) {
		if (!text.length()) return 0;
		unordered_map<char, size_t> table;
		for_each(text.begin(), text.end(), [&](auto it) {
			if (table.find(it) == table.end())
				table[it] = 1;
			else ++table[it];
			});
		auto cmp = [](Node* l, Node* r) {return l->count < r->count; };
		priority_queue < Node*, vector<Node*>, decltype(cmp) > qu(cmp);
		for_each(table.begin(), table.end(), [&qu](auto it) {
			qu.push(new Node(it.first, it.second));
			});
		while (qu.size() > 1) {
			auto left = qu.top();
			qu.pop();
			auto right = qu.top();
			qu.pop();
			qu.push(new Node(left->count + right->count, left, right));
		}
		unordered_map<char, string> hash;
		Encode(qu.top(), "", hash);
		delete qu.top();
		string ret = "";
		for_each(text.begin(), text.end(), [&](auto it) {
			ret += hash[it];
			});
		return stoull(ret, nullptr, 2);
	}

}