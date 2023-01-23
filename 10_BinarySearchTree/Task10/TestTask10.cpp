#include "BST.h"
#include "..\Lib\Lib.h"
#include "..\Solution10\BST.h"
#include <algorithm>
#include <map>
#include <gtest/gtest.h>

using namespace std;

namespace hw = Homework;
namespace bm = HomeworkCheck;

using Homework::Receipt;
using Homework::Node;

using Test = vector<vector<hw::Receipt>>;

Test GenerateTest() {
	Test ret(100);
	generate(ret.begin(), ret.end(), [] {
		vector<hw::Receipt> out(RND.range<size_t>(0, 1000));
		map<size_t, double> val;
		generate(out.begin(), out.end(), [&] {
			while (true) {
				pair<size_t, double> x{ RND.range<size_t>(0, SIZE_MAX), RND.range<double>(1.0, 1000.0) };
				if (val.insert(x).second) return Receipt{ x.first,x.second };
			}
			return Receipt{};
			});
		return out;
		});
	return ret;
}

TEST(FromList, FromList)
{
	auto test = GenerateTest();
	for_each(test.begin(), test.end(), [](auto it) {
		Node* ans = hw::FromList(it);
		Node* benchMark = bm::FromList(it);
		EXPECT_EQ(bm::MaxDepth(ans), bm::MaxDepth(benchMark));
		EXPECT_EQ(bm::IsBST(ans), true);
		delete ans;
		delete benchMark;
		});
}

TEST(FromNode, FromNode) {
	auto test = GenerateTest();
	for_each(test.begin(), test.end(), [](auto it) {
		Node* root = hw::FromList(it);
		sort(it.begin(), it.end(), [](auto l, auto r) {
			return l.receiptNumber < r.receiptNumber;
			});
		auto ans = hw::FromNode(root);
		EXPECT_EQ(it == ans, true);
		delete root;
		});
}

//TEST(GetAmount, GetAmount) {
//	auto test = GenerateTest();
//	for_each(test.begin(), test.end(), [](auto it) {
//		Node* root = hw::FromList(it);
//		Receipt ctrl = it[RND.range<size_t>(0, it.size() - 1)];
//		double ans = hw::GetAmount(root, ctrl.receiptNumber);
//		EXPECT_EQ(ctrl.amount, ans);
//		delete root;
//		});
//}

//TEST(CheckTree, CheckTree) {
//	auto test = GenerateTest();
//	for_each(test.begin(), test.end(), [](auto it) {
//		if (it.size() > 2) {
//			Node* root = hw::FromList(it);
//			EXPECT_TRUE(hw::CheckTree(root));
//			root->left->x.receiptNumber = SIZE_MAX;
//			EXPECT_FALSE(hw::CheckTree(root));
//		}
//		});
//}

//TEST(_Delete, _Delete) {
//	auto test = GenerateTest();
//	for_each(test.begin(), test.end(), [](auto it) {
//		Node* root = hw::FromList(it);
//		sort(it.begin(), it.end(), [](auto l, auto r) {
//			return l.receiptNumber < r.receiptNumber;
//			});
//		if (root) {
//			size_t out = RND.range<size_t>(0, it.size() - 1);
//			Receipt del = it[out];
//			it.erase(it.begin() + out);
//			root = Delete(root, del.receiptNumber);
//			auto ctrl = hw::FromNode(root);
//			EXPECT_EQ(it == ctrl, true);
//			delete root;
//		}
//		});
//}

//TEST(GetNext, GetNext) {
//	auto test = GenerateTest();
//	for_each(test.begin(), test.end(), [](auto it) {
//		if (it.size() > 1) {
//			Node* root = hw::FromList(it);
//			sort(it.begin(), it.end(), [](auto l, auto r) {
//				return l.receiptNumber < r.receiptNumber;
//				});
//			if (root) {
//				size_t t = RND.range<size_t>(0, it.size() - 2);
//				Receipt prev = it[t];
//				Receipt next = it[t + 1];
//				Receipt answ = hw::GetNext(root, prev);
//				EXPECT_EQ(next == answ, true);
//				delete root;
//			}
//		}
//		});
//}
