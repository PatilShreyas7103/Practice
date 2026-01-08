// Longest Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based Index Tracking
Time: O(n)
Space: O(n)

Idea:
- Use a stack to store indices.
- Push -1 initially to handle base for valid substring.
- On '(' → push index.
- On ')' → pop once:
    - If stack is not empty, compute length = i - st.top()
    - Else, push current index as new base.
- Track maximum length found.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                st.pop();
                if (!st.empty()) {
                    ans = max(ans, i - st.top());
                } else {
                    st.push(i);
                }
            } else {
                st.push(i);
            }
        }
        return ans;
    }
};