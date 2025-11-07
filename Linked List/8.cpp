// Middle of the Linked List

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ----------- Approach 1: Counting Length -----------
class SolutionLength {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* t = head;
        while(t)
        {
            len++;
            t = t->next;
        }

        int mid = len / 2 + 1;
        int cnt = 1;
        t = head;
        while(cnt != mid)
        {
            t = t->next;
            cnt++;
        }

        return t;
    }
};

// ----------- Approach 2: Two Pointers -----------
class SolutionTwoPointers {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

// Optionally, add your test cases and main() function below.
