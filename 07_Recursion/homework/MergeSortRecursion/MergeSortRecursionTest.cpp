#include "MergeSortRecursion.h"
#include <iostream>
#include <string>
#include <cassert>
#include <vector>

static bool isSorted(ListNode *head) {
  if (!head || !head->next)
    return true;
  return (head->val <= head->next->val && isSorted(head->next));
}

static int getListLength(ListNode *node) {
  if (!node)
    return 0;
  return 1 + getListLength(node->next);
}

void merge2sortedTest() {
  std::cout << "Merge 2 sorted LinkedList" << std::endl;
  ListNode l1(1);
  l1.next = new ListNode(2);
  l1.next->next = new ListNode(4);
  l1.next->next->next = new ListNode(6);
  l1.next->next->next->next = new ListNode(8);

  ListNode l2(1);
  l2.next = new ListNode(3);
  l2.next->next = new ListNode(4);

  ListNode l3(5);

  std::vector<std::pair<ListNode *, ListNode *>> vals{
       {nullptr, &l3}, {nullptr, nullptr}, {&l1, &l2}};
  std::vector<int> res = { 1, 0, 8};
  for (size_t i = 0; i < res.size(); ++i) {
    auto actual =
        MergeSortRecursion::mergeTwoLists(vals[i].first, vals[i].second);
    assert(isSorted(actual));
    assert(res[i] == getListLength(actual));
  }
}

void merge3sortedTest() {
  std::cout << "Merge 3 sorted LinkedList" << std::endl;

  ListNode l1(1);
  l1.next = new ListNode(2);
  l1.next->next = new ListNode(4);

  ListNode l2(1);
  l2.next = new ListNode(3);
  l2.next->next = new ListNode(4);

  ListNode l3(2);
  l3.next = new ListNode(4);
  l3.next->next = new ListNode(6);

  ListNode l4(1);
  ListNode l5(5);

  std::vector<std::vector<ListNode *>> vals{{&l1, &l2, &l3},
                                            {nullptr, &l5, nullptr},
                                            {&l4, &l5, nullptr},
                                            {nullptr, nullptr, nullptr}};
  std::vector<int> res = {9, 1, 2, 0};
  for (size_t i = 0; i < res.size(); ++i) {
    auto actual =
        MergeSortRecursion::mergeThreeLists(vals[i][0], vals[i][1], vals[i][2]);
    assert(isSorted(actual));
    assert(res[i] == getListLength(actual));
  }
}

int main() {
  merge2sortedTest();
  merge3sortedTest();
  std::cout << "All tests for DLList passed successfully! Congrats";
  return 0;
}
