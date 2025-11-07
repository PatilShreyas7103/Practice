// Delete the Middle Node of a Linked List

#include <iostream>
using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Method 1: Using slow and fast pointers to find and delete middle node
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        if(head->next->next == nullptr) {
            head->next = nullptr;
            return head;
        }

        ListNode* fast = head->next->next;
        ListNode* slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return head;
    }

    // Method 2: Using length count to find and delete middle node
    ListNode* deleteMiddleCount(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        int length = 0;
        ListNode* temp = head;
        while(temp) {
            length++;
            temp = temp->next;
        }

        int mid = length / 2;
        if(mid == 0) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }

        temp = head;
        for(int i = 1; i < mid; i++) {
            temp = temp->next;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};
