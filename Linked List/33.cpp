// 💻 Program: Remove All Duplicates from Sorted Linked List — Two Approaches

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
// 🧩 Approach 1: Pointer-based Comparison (O(n) Time, O(1) Space)
// ---------------------------------------------------------------
class PointerComparisonSolution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (curr) {
            bool leftUnique = true, rightUnique = true;

            if (prev && prev->val == curr->val)
                leftUnique = false;

            if (next && next->val == curr->val)
                rightUnique = false;

            if (leftUnique && rightUnique) {
                tail->next = curr;
                tail = tail->next;
            }

            prev = curr;
            curr = next;
            if (next)
                next = next->next;
        }

        tail->next = nullptr;

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

// ---------------------------------------------------------------
// ⚡ Approach 2: Frequency Map (O(n) Time, O(n) Space)
// ---------------------------------------------------------------
class FrequencyMapSolution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        map<int, int> freq;
        ListNode* temp = head;

        // Step 1: Count occurrences
        while (temp) {
            freq[temp->val]++;
            temp = temp->next;
        }

        // Step 2: Rebuild list with unique nodes
        temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (temp) {
            if (freq[temp->val] == 1) {
                tail->next = temp;
                tail = tail->next;
            }
            temp = temp->next;
        }

        ListNode* ans = dummy->next;
        tail->next = nullptr;
        delete dummy;
        return ans;
    }
};