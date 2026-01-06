// Infix to Prefix Conversion

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Infix → Prefix using Stack
Time: O(n)
Space: O(n)

Idea:
1. Reverse the infix expression.
2. Swap '(' with ')'.
3. Convert the modified infix to postfix.
4. Reverse the postfix to get prefix.
*/

class Solution {
public:
    bool isOperator(char c) {
        return (!isalnum(c));
    }

    int getPriority(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        if (c == '^') return 3;
        return 0;
    }

    string infixToPostfix(string infix) {
        infix = "(" + infix + ")";
        stack<char> st;
        string output;

        for (char c : infix) {
            if (isalnum(c)) {
                output.push_back(c);
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    output.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && isOperator(st.top())) {
                    if (c == '^') {
                        if (getPriority(c) <= getPriority(st.top())) {
                            output.push_back(st.top());
                            st.pop();
                        } else break;
                    } else {
                        if (getPriority(c) < getPriority(st.top())) {
                            output.push_back(st.top());
                            st.pop();
                        } else break;
                    }
                }
                st.push(c);
            }
        }
        return output;
    }

    string infixToPrefix(string infix) {
        reverse(infix.begin(), infix.end());

        for (char &c : infix) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }

        string postfix = infixToPostfix(infix);
        reverse(postfix.begin(), postfix.end());
        return postfix;
    }
};