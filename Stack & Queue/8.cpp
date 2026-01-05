// Asteroid Collision
#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Monotonic Stack Simulation
Time: O(n)
Space: O(n)
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        int n = v.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            bool destroyed = false;

            while (!st.empty() && v[i] < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(v[i])) {
                    st.pop();
                    continue;
                } 
                else if (abs(st.top()) == abs(v[i])) {
                    st.pop();
                }
                destroyed = true;
                break;
            }

            if (!destroyed) {
                st.push(v[i]);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};