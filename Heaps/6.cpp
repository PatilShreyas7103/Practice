// Merge K Sorted Lists - Heap Approach (Without Comparator)

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

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        using P = pair<int, ListNode*>;

        priority_queue<P, vector<P>, greater<P>> pq;  // min-heap based on first element

        for (auto node : lists)
            if (node) pq.push({node->val, node});

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            auto [value, node] = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next)
                pq.push({node->next->val, node->next});
        }

        tail->next = nullptr;
        return dummy.next;
    }
};