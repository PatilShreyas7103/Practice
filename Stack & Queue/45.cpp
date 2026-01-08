// Delete Middle Element of a Stack

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Recursion
Time: O(n)
Space: O(n) (recursion stack)

Idea:
- Use recursion to reach the middle of the stack.
- Count elements using a counter.
- When the middle is reached, pop it.
- While returning from recursion, push the elements back.
*/
class Solution {
public:
    void solve(stack<int>& st, int cnt, int n) {
        // base case: middle element
        if (cnt == (n + 1) / 2) {
            st.pop();
            return;
        }

        int val = st.top();
        st.pop();

        solve(st, cnt - 1, n);

        st.push(val);
    }

    void deleteMid(stack<int>& st) {
        int n = st.size();
        solve(st, n, n);
    }
};