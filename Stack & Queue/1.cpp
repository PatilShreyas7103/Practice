// Next Greater Element I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mp;
        stack<int> st;

        for(int i = b.size() - 1; i >= 0; i--) {
            int val = b[i];
            while(!st.empty() && st.top() <= val) {
                st.pop();
            }
            mp[val] = st.empty() ? -1 : st.top();
            st.push(val);
        }

        vector<int> ans;
        for(int num : a) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};