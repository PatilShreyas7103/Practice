// Infix to Postfix Conversion

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based Operator Precedence
Time: O(n)
Space: O(n)

Idea:
- Operands are added directly to the result.
- '(' is pushed to stack.
- ')' pops until '(' is found.
- Operators pop from stack while top has higher or equal precedence.
*/

class Solution {
public:
    int prec(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string result;

        for (char c : s) {
            // Operand
            if (isalnum(c)) {
                result.push_back(c);
            }
            // Opening bracket
            else if (c == '(') {
                st.push(c);
            }
            // Closing bracket
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result.push_back(st.top());
                    st.pop();
                }
                if (!st.empty()) st.pop(); // remove '('
            }
            // Operator
            else {
                while (!st.empty() && prec(c) <= prec(st.top())) {
                    result.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};