// 💻 Program: 143. Reorder List — Reverse and Merge Approaches

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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ---------------------------------------------------------------
// 🧩 Approach 1: Reverse Second Half + Merge (O(n) Time, O(1) Space)
// ---------------------------------------------------------------
class ReverseAndMergeSolution {
public:
    // Helper to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    // Reorder list as: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 ...
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        // Step 1: Find middle of the list
        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Step 2: Reverse the second half
        ListNode* secondHalf = reverseList(slow->next);
        slow->next = nullptr;

        // Step 3: Merge both halves alternately
        ListNode* first = head;
        ListNode* second = secondHalf;

        while (first && second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            if (!temp1) break;

            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};

// ---------------------------------------------------------------
// ⚡ Approach 2: Using Stack (O(n) Time, O(n) Space)
// ---------------------------------------------------------------
class StackSolution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        // Step 1: Push all nodes into stack
        stack<ListNode*> st;
        ListNode* temp = head;
        int len = 0;
        while (temp) {
            st.push(temp);
            temp = temp->next;
            len++;
        }

        // Step 2: Reorder using stack (take nodes from both ends)
        temp = head;
        for (int i = 0; i < len / 2; i++) {
            ListNode* tailNode = st.top();
            st.pop();

            tailNode->next = temp->next;
            temp->next = tailNode;
            temp = temp->next->next;
        }

        // Step 3: Set last node's next to NULL
        temp->next = nullptr;
    }
};