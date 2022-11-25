#pragma once

//Definition for singly-linked list.
class ListNode {
public:
    ListNode(int val) { this->val = val; }
    ListNode(int val, ListNode* next) { this->val = val; this->next = next; }
    virtual ~ListNode() { if (next) { delete next; } };

    int val;
    ListNode* next{nullptr};
};
