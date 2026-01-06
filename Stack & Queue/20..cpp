// Min Stack

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack of Pair (value, current minimum)
Time: O(1) for all operations
Space: O(n)

Idea:
- Store {value, minimum till this point} in stack.
- getMin() is always available at stack top.
*/
class MinStackPair {
public:
    stack<pair<int,int>> st;

    MinStackPair() {}

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int mn = min(val, st.top().second);
            st.push({val, mn});
        }
    }

    void pop() {
        if (!st.empty()) st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

/*
Approach 2: Space Optimized (Encoding Technique)
Time: O(1) for all operations
Space: O(1) extra (only one stack)

Idea:
- Store modified values when a new minimum appears.
- If pushed value < current min:
    push (2*val - min) and update min.
- During pop/top, decode when needed.
*/
class MinStackEncoded {
public:
    stack<long long> st;
    long long mn;

    MinStackEncoded() {
        mn = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            mn = val;
            st.push(val);
        } else {
            if (val < mn) {
                st.push(2LL * val - mn);
                mn = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long t = st.top();
        st.pop();

        if (t < mn) {
            mn = 2LL * mn - t;
        }
    }

    int top() {
        long long t = st.top();
        if (t < mn) {
            return (int)mn;
        }
        return (int)t;
    }

    int getMin() {
        return (int)mn;
    }
};