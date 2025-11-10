// 💻 Program: Merge K Sorted Linked Lists — Two Approaches

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
// 🧩 Approach 1: Sequential Merge (O(k * n) Time, O(1) Extra Space)
// ---------------------------------------------------------------
class SequentialMergeSolution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* p = a;
        ListNode* q = b;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (p && q) {
            if (p->val < q->val) {
                tail->next = p;
                p = p->next;
            } else {
                tail->next = q;
                q = q->next;
            }
            tail = tail->next;
        }

        if (p)
            tail->next = p;
        if (q)
            tail->next = q;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return nullptr;
        if (n == 1)
            return lists[0];

        ListNode* mergedList = lists[0];
        for (int i = 1; i < n; i++) {
            mergedList = merge(mergedList, lists[i]);
        }

        return mergedList;
    }
};

// ---------------------------------------------------------------
// ⚡ Approach 2: Min-Heap / Priority Queue (O(n log k) Time, O(k) Space)
// ---------------------------------------------------------------
class MinHeapSolution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Push the head of each list into the priority queue
        for (auto node : lists) {
            if (node)
                pq.push(node);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // Extract the smallest node and add its next node into the queue
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();

            tail->next = top;
            tail = tail->next;

            if (top->next)
                pq.push(top->next);
        }

        return dummy->next;
    }
};