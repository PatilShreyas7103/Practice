// 💻 Program: Merge Two Sorted Linked Lists — Iterative and Recursive Approaches

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

// ---------------------------------------------------------------
// 🧩 Approach 1: Iterative Merge (O(n + m) Time, O(1) Space)
// ---------------------------------------------------------------
class IterativeSolution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* p = list1;
        ListNode* q = list2;

        while (p && q) {
            if (p->val < q->val) {
                tail->next = p;
                p = p->next;
            } else {
                tail->next = q;
                q = q->next;
            }
            tail = tail->next;
        }

        if (p) tail->next = p;
        if (q) tail->next = q;

        return dummy->next;
    }
};

// ---------------------------------------------------------------
// ⚡ Approach 2: Recursive Merge (O(n + m) Time, O(n + m) Stack Space)
// ---------------------------------------------------------------
class RecursiveSolution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};