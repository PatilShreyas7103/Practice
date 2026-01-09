// Minimum Add to Make Parentheses Valid

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based
Time: O(n)
Space: O(n)

Idea:
- Use a stack to store unmatched '('.
- For every ')':
    - If stack is empty → we need an extra '(' → increment count.
    - Else → pop matching '('.
- At the end, remaining '(' in stack need ')'.
- Total additions = extra ')' needed + remaining '('.
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;

        for (char it : s) {
            if (it == ')') {
                if (st.empty()) {
                    cnt++;
                } else {
                    st.pop();
                }
            } else {
                st.push('(');
            }
        }
        return cnt + st.size();
    }
};