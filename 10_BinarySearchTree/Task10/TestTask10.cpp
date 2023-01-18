#include "BST.h"
#include "..\Lib\Lib.h"
#include "..\Solution\\BST.h"
#include <algorithm>
#include <map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace hw = Homework::BST;
namespace bm = HomeworkCheck::BST;

using Homework::BST::Receipt;
using Homework::BST::Node;

using Test = vector<vector<bm::Receipt>>;

namespace TestTask10
{
	TEST_CLASS(TestTask10)
	{
	private:
		Test GenerateTest() {
			Test ret(100);
			generate(ret.begin(), ret.end(), [] {
				vector<bm::Receipt> out(RND.range<size_t>(0, 1000));
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

	public:

		TEST_METHOD(FromList)
		{
			auto test = GenerateTest();
			for_each(test.begin(), test.end(), [](auto it) {
				Node* ans = hw::FromList(it);
				Node* benchMark = bm::FromList(it);
				Assert::AreEqual(bm::MaxDepth(ans), bm::MaxDepth(benchMark));
				Assert::AreEqual(bm::IsBST(ans), true);
				delete ans;
				delete benchMark;
				});
		}

		TEST_METHOD(FromNode) {
			auto test = GenerateTest();
			for_each(test.begin(), test.end(), [](auto it) {
				Node* root = hw::FromList(it);
				sort(it.begin(), it.end(), [](auto l, auto r) {
					return l.receiptNumber < r.receiptNumber;
					});
				auto ans = hw::FromNode(root);
				Assert::AreEqual(it == ans, true);
				delete root;
				});
		}

		TEST_METHOD(GetAmount) {
			auto test = GenerateTest();
			for_each(test.begin(), test.end(), [](auto it) {
				Node* root = hw::FromList(it);
				Receipt ctrl = it[RND.range<size_t>(0, it.size() - 1)];
				double ans = hw::GetAmount(root, ctrl.receiptNumber);
				Assert::AreEqual(ctrl.amount, ans);
				delete root;
				});
		}

		TEST_METHOD(CheckTree) {
			auto test = GenerateTest();
			for_each(test.begin(), test.end(), [](auto it) {
				if (it.size() > 2) {
					Node* root = hw::FromList(it);
					Assert::IsTrue(hw::CheckTree(root));
					root->left->x.receiptNumber = SIZE_MAX;
					Assert::IsFalse(hw::CheckTree(root));
				}
				});
		}

		TEST_METHOD(_Delete) {
			auto test = GenerateTest();
			for_each(test.begin(), test.end(), [](auto it) {
				Node* root = hw::FromList(it);
				sort(it.begin(), it.end(), [](auto l, auto r) {
					return l.receiptNumber < r.receiptNumber;
					});
				if (root) {
					size_t out = RND.range<size_t>(0, it.size() - 1);
					Receipt del = it[out];
					it.erase(it.begin() + out);
					root = Delete(root, del.receiptNumber);
					auto ctrl = hw::FromNode(root);
					Assert::AreEqual(it == ctrl, true);
					delete root;
				}
				});
		}

		TEST_METHOD(GetNext) {
			auto test = GenerateTest();
			for_each(test.begin(), test.end(), [](auto it) {
				if (it.size() > 1) {
					Node* root = hw::FromList(it);
					sort(it.begin(), it.end(), [](auto l, auto r) {
						return l.receiptNumber < r.receiptNumber;
						});
					if (root) {
						size_t t = RND.range<size_t>(0, it.size() - 2);
						Receipt prev = it[t];
						Receipt next = it[t + 1];
						Receipt answ = hw::GetNext(root, prev);
						Assert::AreEqual(next==answ,true);
						delete root;
					}
				}
				});
		}
	};
}
