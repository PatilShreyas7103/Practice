// Linked List Cycle Detection

#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ----------- Approach 1: Using Hash Set -----------
class SolutionHashSet {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode* t = head;

        while(t)
        {
            if(st.find(t) != st.end())
            {
                return true;
            }
            st.insert(t);
            t = t->next;
        }

        return false;
    }
};

// ----------- Approach 2: Two Pointers (Floyd’s Cycle-Finding Algorithm) -----------
class SolutionTwoPointers {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
        {
            return false;
        }
        if(head->next == head)
        {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

// Optionally, add your test cases and main() function below.
