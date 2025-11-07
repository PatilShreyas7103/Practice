// Odd even linked list

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
    ListNode* oddEvenList(ListNode* head) {
        if(head== NULL || head->next==NULL || head->next->next==NULL)
        {
            return head;
        }

        ListNode* h1 = head;
        ListNode* h2 = head->next;
        ListNode* temp = h1;

        while(temp->next)
        {
            ListNode* save = temp->next;
            temp->next = temp->next->next;
            temp = save;
        }

        ListNode* dumm = h1;
        while(dumm->next)
        {
            dumm = dumm->next;
        }
        dumm->next = h2;

        return h1;
    }
};
