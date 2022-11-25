#pragma once
#include "ListNode.h"

class MergeSortRecursion {
public:
    MergeSortRecursion() {};
    virtual ~MergeSortRecursion() {};

    // Task #1
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    // Task #2
    static ListNode* mergeThreeLists(ListNode* l1, ListNode* l2, ListNode* l3);
};
