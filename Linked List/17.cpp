// 148. Sort List
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Iterative merge of two sorted lists
    ListNode* mergeIterative(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }

    // Get middle of the list
    ListNode* getMiddle(ListNode* head) {
        if (!head) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge sort implementation for linked list using iterative merge
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = getMiddle(head);
        ListNode* second = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        return mergeIterative(left, right);
    }

    // Brute force approach using vector and sorting
    ListNode* sortListBruteForce(ListNode* head) {
        if (!head) return nullptr;

        vector<int> vals;
        ListNode* curr = head;
        while (curr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }

        sort(vals.begin(), vals.end());

        curr = head;
        int i = 0;
        while (curr) {
            curr->val = vals[i++];
            curr = curr->next;
        }
        return head;
    }
};
