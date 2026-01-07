// Baseball Game

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based Simulation
Time: O(n)
Space: O(n)

Idea:
- Use a stack to keep track of valid scores.
- "+" → sum of last two valid scores.
- "D" → double the last valid score.
- "C" → remove the last valid score.
- Otherwise → parse integer (can be negative) and push.
- Sum all values in stack at the end.
*/
class Solution {
public:
    int calPoints(vector<string>& v) {
        stack<int> st;

        for (auto s : v) {
            if (s == "+") {
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                st.push(val2);
                st.push(val1);
                st.push(val1 + val2);
            }
            else if (s == "C") {
                st.pop();
            }
            else if (s == "D") {
                st.push(st.top() * 2);
            }
            else {
                int num = 0;
                int sign = 1;
                for (char ch : s) {
                    if (ch == '-') {
                        sign = -1;
                        continue;
                    }
                    num = num * 10 + (ch - '0');
                }
                st.push(sign * num);
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};