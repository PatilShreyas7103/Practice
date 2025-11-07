// Reverse Linked List

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

// ----------- Approach 1: Iterative -----------
class SolutionIterative {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr)
        {
            ListNode* fow = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fow;
        }

        return prev;
    }
};

// ----------- Approach 2: Recursive -----------
class SolutionRecursive {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
};

// Optionally, add your test cases and main() function below.
