// 💻 Program: Partition List — Separate Nodes Based on Pivot Value x

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* d1 = new ListNode(-1);
        ListNode* less = d1;
        ListNode* d2 = new ListNode(-1);
        ListNode* more = d2;

        ListNode* t = head;
        while (t)
        {
            if (t->val < x)
            {
                d1->next = t;
                d1 = d1->next;
            }
            else
            {
                d2->next = t;
                d2 = d2->next;
            }
            t = t->next;
        }

        d2->next = NULL;
        d1->next = more->next;

        ListNode* ans = less->next;
        delete less;
        delete more;

        return ans;
    }
};