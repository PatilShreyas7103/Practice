// 🧩 Delete Node from Singly Linked List (With and Without Head)
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class implementing both deletion methods
class Solution {
public:
    // Case 1️⃣: Delete node when only pointer to that node is given (LeetCode-style)
    void deleteNode(ListNode* node) {
        if (!node || !node->next) return;  // can't delete last node
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }

    // Case 2️⃣: Delete node when head pointer is given
    void deleteNodeWithHead(ListNode*& head, int value) {
        if (!head) return;

        // If head itself is to be deleted
        if (head->val == value) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Traverse to find the node before the target
        ListNode* current = head;
        while (current->next && current->next->val != value) {
            current = current->next;
        }

        // Node not found
        if (!current->next) return;

        ListNode* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Utility: print linked list
    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
};

// 🧪 Example Driver Code
int main() {
    // Create linked list: 10 -> 20 -> 30 -> 40 -> NULL
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    Solution sol;
    cout << "Original List:\n";
    sol.printList(head);

    // Case 1: Delete node when head is given
    cout << "\nDeleting node with value 20 (using head)...\n";
    sol.deleteNodeWithHead(head, 20);
    sol.printList(head);

    // Case 2: Delete node when only pointer to node is given (LeetCode style)
    cout << "\nDeleting node (pointer given to 30)...\n";
    ListNode* node = head->next; // pointer to node 30
    sol.deleteNode(node);
    sol.printList(head);

    return 0;
}