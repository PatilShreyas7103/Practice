// First Negative Integer in Every Window of Size K

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Sliding Window + Queue
Time: O(n)
Space: O(k)

Idea:
- Use a queue to store indices of negative numbers.
- For each index i:
  - If v[i] is negative, push its index into the queue.
  - Remove indices from the queue that are out of the current window (<= i-k).
  - Once the first window is formed (i >= k-1):
      - If queue is empty → no negative number → push 0.
      - Else → front of queue gives first negative number.
*/
class Solution {
public:
    vector<int> firstNegInt(vector<int>& v, int k) {
        queue<int> q;
        int n = v.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (v[i] < 0) {
                q.push(i);
            }

            if (!q.empty() && q.front() <= i - k) {
                q.pop();
            }

            if (i < k - 1) continue;

            if (q.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(v[q.front()]);
            }
        }
        return ans;
    }
};