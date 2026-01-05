// Next Greater Element II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int val = v[i % n];

            while (!st.empty() && st.top() <= val) {
                st.pop();
            }

            if (i < n) {
                ans[i] = st.empty() ? -1 : st.top();
            }

            st.push(val);
        }

        return ans;
    }
};