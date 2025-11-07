// Palindrome Linked List

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ----------- Approach 1: Reverse Second Half (Optimized) -----------
class SolutionOptimized {
public:
    ListNode* rev(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;

        while(cur) {
            ListNode* fow = cur->next;
            cur->next = prev;
            prev = cur;
            cur = fow;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* save = rev(slow->next);
        ListNode* t = head;

        while(save) {
            if(t->val != save->val) {
                return false;
            }
            save = save->next;
            t = t->next;
        }
        return true;
    }
};

// ----------- Approach 2: Using Stack -----------
class SolutionStack {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* cur = head;

        while(cur) {
            st.push(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(cur) {
            if(cur->val != st.top()) {
                return false;
            }
            st.pop();
            cur = cur->next;
        }
        return true;
    }
};

// ----------- Approach 3: Using Vector -----------
class SolutionVector {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        ListNode* cur = head;

        while(cur) {
            vals.push_back(cur->val);
            cur = cur->next;
        }

        int i = 0;
        int j = vals.size() - 1;
        while(i < j) {
            if(vals[i] != vals[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

// Optionally, add your test cases and main() function below.
