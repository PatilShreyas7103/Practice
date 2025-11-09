// 💻 Program: Rotate Right a Singly Linked List by k positions

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 1;
        if (!head) {
            return head;
        }

        ListNode* t = head;
        while (t->next) {
            len++;
            t = t->next;
        }
        if (k % len == 0) {
            return head;
        }
        k %= len;
        t->next = head;

        int pos = len - k;
        int cnt = 1;
        t = head;
        while (cnt != pos) {
            t = t->next;
            cnt++;
        }
        head = t->next;
        t->next = NULL;

        return head;
    }
};
