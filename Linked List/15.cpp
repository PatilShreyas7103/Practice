// Remove nth node from end

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    // Original length-counting approach
    ListNode* removeNthFromEndLength(ListNode* head, int n) {
        int len = 0;
        ListNode* t = head;

        while(t)
        {
            len++;
            t = t->next;
        }

        int pos = len-n;

        if(pos==0)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        t = head;
        int cnt = 1;
        while(cnt!=pos)
        {
            cnt++;
            t = t->next;
        }
        ListNode* temp = t->next;
        t->next = t->next->next;
        delete temp;
        return head;
    }

    // Slow and fast pointer approach
    ListNode* removeNthFromEndTwoPointers(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
