// Sliding Window Maximum

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n * k)
Space: O(1)

Idea:
For every window of size k, iterate and find the maximum.
*/
class SolutionBruteForce {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = v.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            int mx = INT_MIN;
            for (int j = i; j < i + k; j++) {
                mx = max(mx, v[j]);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};

/*
Approach 2: Deque (Monotonic Queue)
Time: O(n)
Space: O(k)

Idea:
Maintain a deque of indices in decreasing order of values.
The front of the deque always stores the index of the maximum
element for the current window.
*/
class SolutionDeque {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = v.size();
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // Remove indices out of current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && v[dq.back()] <= v[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Window formed
            if (i >= k - 1) {
                ans.push_back(v[dq.front()]);
            }
        }
        return ans;
    }
};