// Basic Calculator 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: One-Pass Stack Evaluation
Time: O(n)
Space: O(n)

Idea:
- Maintain a running result `res` and current `sign`.
- Use a stack to save previous result and sign when '(' is encountered.
- On ')', resolve the sub-expression using stack.
- Handles:
  ✓ operator precedence
  ✓ left associativity
  ✓ unary minus
  ✓ spaces
*/
class Solution {
public:
    int calculate(string s) {
        long long res = 0;      // current result
        long long num = 0;      // current number
        int sign = 1;           // +1 or -1
        stack<long long> st;    // stores previous result and sign

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                // store previous result and sign
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')') {
                res += sign * num;
                num = 0;

                int prevSign = st.top(); st.pop();
                long long prevRes = st.top(); st.pop();

                res = prevRes + prevSign * res;
            }
            // ignore spaces
        }

        res += sign * num;
        return res;
    }
};