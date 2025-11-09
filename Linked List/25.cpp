// 💻 Program: Reverse Nodes in k-Group in a Singly Linked List

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class
class IterativeSolution {
public:
    // Helper function to reverse 'k' nodes of the list
    ListNode* reverseGroup(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current && k > 0) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            k--;
        }

        return prev; // new head after reversal
    }

    // Main function to reverse nodes in groups of size 'k'
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1)
            return head;

        ListNode* dummy = new ListNode(-1);
        ListNode* resultTail = dummy; // to build the final list
        ListNode* current = head;

        while (current) {
            ListNode* groupStart = current;
            ListNode* groupEnd = current;
            bool hasKNodes = true;

            // Check if there are at least k nodes remaining
            for (int i = 0; i < k; i++) {
                if (groupEnd == nullptr) {
                    hasKNodes = false;
                    break;
                }
                groupEnd = groupEnd->next;
            }

            if (!hasKNodes) {
                // If remaining nodes are less than k, keep them as is
                resultTail->next = current;
                break;
            }

            // Reverse the k nodes and connect
            ListNode* reversedHead = reverseGroup(groupStart, k);
            resultTail->next = reversedHead;

            // Move the tail pointer to the end of the reversed section
            resultTail = groupStart;
            current = groupEnd;
        }

        return dummy->next;
    }
};

// Solution class
class RecusiveSolution {
public:
    // Helper function to reverse exactly 'k' nodes starting from 'head'
    ListNode* reverseKNodes(ListNode* head, int k, ListNode** nextGroupHead) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        int count = 0;

        while (current && count < k) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            count++;
        }

        *nextGroupHead = current; // store pointer to the next group’s start
        return prev;              // return new head of the reversed group
    }

    // Main recursive function to reverse nodes in groups of k
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        // Step 1: Check if there are at least k nodes ahead
        ListNode* temp = head;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        // If less than k nodes, do not reverse
        if (count < k)
            return head;

        // Step 2: Reverse the first k nodes
        ListNode* nextGroupHead = nullptr;
        ListNode* newHead = reverseKNodes(head, k, &nextGroupHead);

        // Step 3: Recursively reverse the remaining list
        head->next = reverseKGroup(nextGroupHead, k);

        // Return new head after reversal
        return newHead;
    }
};