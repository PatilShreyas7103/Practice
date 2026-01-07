// Check for Redundant Braces

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based Check (Optimal)
Time: O(n)
Space: O(n)

Idea:
- Use a stack to process the expression.
- Push characters until ')' is encountered.
- On ')', check the content inside the brackets:
    - If there is NO operator (+, -, *, /), then braces are redundant.
- Otherwise, pop until '(' and continue.
- Return 1 if redundant braces found, else 0.
*/
class Solution {
public:
    int braces(string A) {
        stack<char> st;

        for (char ch : A) {
            if (ch == ')') {
                bool hasOperator = false;

                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                }

                // pop '('
                if (!st.empty()) st.pop();

                // no operator inside parentheses → redundant
                if (!hasOperator) return 1;
            } 
            else {
                st.push(ch);
            }
        }
        return 0;
    }
};