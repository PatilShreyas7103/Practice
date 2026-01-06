// Prefix to Postfix Conversion

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based Conversion
Time: O(n)
Space: O(n)

Idea:
- Traverse the prefix expression from right to left.
- If operand → push as string.
- If operator → pop two operands (op1, op2),
  form "op1 + op2 + operator" and push back.
- Final stack top is the postfix expression.
*/
class Solution {
public:
    string prefixToPostfix(string prefix) {
        stack<string> st;

        for (int i = prefix.size() - 1; i >= 0; i--) {
            char c = prefix[i];

            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                st.push(op1 + op2 + c);
            }
        }
        return st.top();
    }
};