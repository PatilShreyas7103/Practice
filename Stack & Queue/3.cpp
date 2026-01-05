// Next Smaller Element
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& b) {
        int n = b.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            int val = b[i];
            while (!st.empty() && st.top() >= val) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(val);
        }

        return ans;
    }
};