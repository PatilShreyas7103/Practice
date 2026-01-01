// Sort a Stack Using Recursion

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insert(stack<int> &st, int temp) {
        if (st.empty() || st.top() <= temp) {
            st.push(temp);
            return;
        }

        int val = st.top();
        st.pop();
        insert(st, temp);
        st.push(val);
    }

    void solve(stack<int> &st) {
        if (st.empty()) return;

        int temp = st.top();
        st.pop();
        solve(st);
        insert(st, temp);
    }

    void sortStack(stack<int> &st) {
        solve(st);
    }
};