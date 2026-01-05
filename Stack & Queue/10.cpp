// Remove K Digits

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Monotonic Stack (Greedy)
Time: O(n)
Space: O(n)

Idea:
Remove digits greedily to make the number smallest by maintaining
a monotonic increasing stack.
*/
class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;

        for (char ch : s) {
            while (!st.empty() && st.top() > ch && k > 0) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};