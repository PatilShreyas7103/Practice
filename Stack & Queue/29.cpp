// Evaluate Reverse Polish Notation

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based Evaluation
Time: O(n)
Space: O(n)

Idea:
- Traverse tokens one by one.
- If operand → convert to number and push onto stack.
- If operator → pop two operands, apply operator, push result back.
- Final stack top is the answer.
*/
class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack<long long> st;

        for (string str : v) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                long long op1 = st.top(); st.pop();
                long long op2 = st.top(); st.pop();

                if (str == "+") {
                    st.push(op2 + op1);
                } else if (str == "-") {
                    st.push(op2 - op1);
                } else if (str == "*") {
                    st.push(op2 * op1);
                } else { // "/"
                    st.push(op2 / op1);
                }
            } else {
                long long val = 0;
                int i = 0;
                bool neg = false;

                if (str[0] == '-') {
                    neg = true;
                    i++;
                }

                while (i < str.size()) {
                    val = val * 10 + (str[i] - '0');
                    i++;
                }

                if (neg) val = -val;
                st.push(val);
            }
        }
        return st.top();
    }
};