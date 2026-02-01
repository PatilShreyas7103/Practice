// Swap Nodes in Pairs

#include <bits/stdc++.h>
using namespace std;

/*
Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*------------------------------------------------------*/
/*
Approach 1 (Value Swapping – NOT Preferred):
- Traverse the list in pairs.
- Swap values of every two adjacent nodes.
- Works, but modifies data instead of structure.
*/

class ValueSwap {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;

        while (temp && temp->next) {
            swap(temp->val, temp->next->val);
            temp = temp->next->next;
        }

        return head;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
/*
Approach 2 (Pointer Swapping – Preferred):
- Use a dummy node to handle head changes.
- Swap links of each adjacent pair.
- Modifies structure, not data.
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur && cur->next) {
            ListNode* nextPair = cur->next->next;
            ListNode* second = cur->next;

            // swap
            second->next = cur;
            cur->next = nextPair;
            prev->next = second;

            // move forward
            prev = cur;
            cur = nextPair;
        }

        return dummy.next;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/