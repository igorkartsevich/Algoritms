#include "MergeSortRecursion.h"
#include <algorithm>
#include <limits>

ListNode* begin = nullptr;

ListNode* MergeSortRecursion::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr && l2 == nullptr)
		return nullptr;

	else {
		int l1_val = (l1 == nullptr) ? INT_MAX : l1->val;
		int l2_val = (l2 == nullptr) ? INT_MAX : l2->val;

		int min = std::min(l1_val, l2_val);
		(min == l1_val) ? l1 = l1->next : l2 = l2->next;

		ListNode* node = new ListNode(min, mergeTwoLists(l1, l2));
		if (begin == nullptr) begin = node;
	}
}

ListNode* MergeSortRecursion::mergeThreeLists(ListNode* l1, ListNode* l2, ListNode* l3)
{
	if (l1 == nullptr && l2 == nullptr && l3 == nullptr)
		return nullptr;

	else {
		int l1_val = (l1 == nullptr) ? INT_MAX : l1->val;
		int l2_val = (l2 == nullptr) ? INT_MAX : l2->val;
		int l3_val = (l3 == nullptr) ? INT_MAX : l3->val;
		
		int min = std::min(l1_val, std::min(l2_val, l3_val));
		(min == l1_val) ? l1 = l1->next
						 : (min == l2_val) ? l2 = l2->next : l3 = l3->next;

		ListNode* node = new ListNode(min, mergeThreeLists(l1, l2, l3));
		if (begin == nullptr) begin = node;
	}
}
