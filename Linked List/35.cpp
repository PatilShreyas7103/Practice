// 💻 Program: 2130. Maximum Twin Sum of a Linked List — Three Approaches

#include <bits/stdc++.h>
using namespace std;
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ---------------------------------------------------------------
// 🧩 Approach 1: Using Stack (O(n) Time, O(n) Space)
// ---------------------------------------------------------------
class StackSolution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        while (temp) {
            st.push(temp->val);
            temp = temp->next;
        }

        int ans = 0;
        temp = head;
        while (!st.empty()) {
            int k = st.top();
            int sum = k + temp->val;
            ans = max(ans, sum);
            temp = temp->next;
            st.pop();
        }

        return ans;
    }
};

// ---------------------------------------------------------------
// ⚡ Approach 2: Using Vector (O(n) Time, O(n) Space)
// ---------------------------------------------------------------
class VectorSolution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* temp = head;

        while (temp) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        int ans = 0;
        int i = 0, j = values.size() - 1;
        while (i < j) {
            ans = max(ans, values[i] + values[j]);
            i++;
            j--;
        }

        return ans;
    }
};

// ---------------------------------------------------------------
// ⚙️ Approach 3: Reverse Second Half (O(n) Time, O(1) Space)
// ---------------------------------------------------------------
class ReverseHalfSolution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        if (!head) return 0;

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Step 2: Reverse the second half
        ListNode* secondHalf = reverseList(slow->next);
        slow->next = nullptr;

        // Step 3: Calculate maximum twin sum
        ListNode* firstHalf = head;
        int ans = 0;
        while (secondHalf) {
            ans = max(ans, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return ans;
    }
};