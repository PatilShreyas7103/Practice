// Postfix to Prefix Conversion

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based Conversion
Time: O(n)
Space: O(n)

Idea:
- Traverse postfix expression from left to right.
- If operand → push as string.
- If operator → pop two operands (op1, op2),
  form "operator + op1 + op2" and push back.
- Final stack top is the prefix expression.
*/
class Solution {
public:
    string postfixToPrefix(string postfix) {
        stack<string> st;

        for (char c : postfix) {
            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                st.push(string(1, c) + op1 + op2);
            }
        }
        return st.top();
    }
};