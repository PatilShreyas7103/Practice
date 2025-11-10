// 💻 Program: Reverse a Linked List Between Left and Right Positions

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rev(ListNode* head, int l, int r)
    {
        ListNode* p = NULL;
        ListNode* curr = head;
        int k = r - l + 1;

        while (curr)
        {
            if (k == 0)
            {
                break;
            }
            ListNode* f = curr->next;
            curr->next = p;
            p = curr;
            curr = f;
            k--;
        }

        return p;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* t = head;
        ListNode* p = NULL;
        ListNode* save = head;
        for (int i = 1; i <= right; i++)
        {
            save = save->next;
        }
        for (int i = 1; i < left; i++)
        {
            p = t;
            t = t->next;
        }

        ListNode* r = rev(t, left, right);
        if (p)
        {
            p->next = r;
        }
        else
        {
            t->next = save;
            return r;
        }
        t->next = save;

        return head;
    }
};