// Largest Rectangle in Histogram

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n^2)
Space: O(1)

Idea:
For every subarray, find the minimum height and calculate area.
*/
class SolutionBruteForce {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int mn = INT_MAX;
            for (int j = i; j < n; j++) {
                mn = min(mn, v[j]);
                ans = max(ans, mn * (j - i + 1));
            }
        }
        return ans;
    }
};

/*
Approach 2: Previous Smaller + Next Smaller (Two Pass Stack)
Time: O(n)
Space: O(n)

Idea:
For each bar, expand left and right until a smaller bar is found.
*/
class SolutionPSE_NSE {
public:
    vector<int> nse(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] >= v[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] >= v[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        vector<int> ps = pse(v);
        vector<int> ns = nse(v);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, v[i] * (ns[i] - ps[i] - 1));
        }
        return ans;
    }
};

/*
Approach 3: Single Pass Monotonic Stack
Time: O(n)
Space: O(n)

Idea:
Maintain increasing stack of indices. 
Compute area when current height breaks the monotonic order.
*/
class SolutionSinglePassStack {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};