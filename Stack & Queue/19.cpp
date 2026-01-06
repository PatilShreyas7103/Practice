// Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack
Time: O(n)
Space: O(n)

Idea:
- Push opening brackets onto the stack.
- For every closing bracket, the stack top must be the matching opening bracket.
- If mismatch or stack is empty → invalid.
- At the end, stack must be empty.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) return false;

                char t = st.top();
                st.pop();

                bool ok1 = (ch == ')' && t == '(');
                bool ok2 = (ch == '}' && t == '{');
                bool ok3 = (ch == ']' && t == '[');

                if (!ok1 && !ok2 && !ok3) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};