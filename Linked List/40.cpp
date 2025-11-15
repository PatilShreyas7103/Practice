// 💻 Program: Swap Nodes in Pairs — Iterative and Recursive Approaches

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
// 🧩 Approach 1: Iterative Swapping (O(n) Time, O(1) Space)
// ---------------------------------------------------------------
class IterativeSolution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move pointers forward
            prev = first;
            head = first->next;
        }

        return dummy->next;
    }
};

// ---------------------------------------------------------------
// ⚡ Approach 2: Recursive Swapping (O(n) Time, O(n) Stack Space)
// ---------------------------------------------------------------
class RecursiveSolution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;

        return newHead;
    }
};