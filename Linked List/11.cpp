// Linked List Cycle Start Detection

#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ----------- Approach 1: Floyd's Cycle Detection (Two Pointers) -----------
class SolutionTwoPointers {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
        {
            return NULL;
        }
        if(head->next == head)
        {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
            {
                cycle = true;
                break;
            }
        }

        if(!cycle)
        {
            return NULL;
        }
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

// ----------- Approach 2: Using Hash Set -----------
class SolutionHashSet {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode* t = head;

        while(t)
        {
            if(st.find(t) != st.end())
            {
                return t;
            }
            st.insert(t);
            t = t->next;
        }

        return NULL;
    }
};

// Optionally, add your test cases and main() function below.
