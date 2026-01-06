// Daily Temperatures

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n^2)
Space: O(1)

Idea:
For each day, look ahead to find the first warmer temperature
and count the number of days.
*/
class SolutionBruteForce {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            bool found = false;

            for (int j = i + 1; j < n; j++) {
                cnt++;
                if (v[j] > v[i]) {
                    found = true;
                    break;
                }
            }

            if (found) ans.push_back(cnt);
            else ans.push_back(0);
        }
        return ans;
    }
};

/*
Approach 2: Monotonic Stack (Next Greater Element Index)
Time: O(n)
Space: O(n)

Idea:
- Maintain a stack of indices with decreasing temperatures.
- For each index, find the next index with a greater temperature.
- Answer is the difference of indices.
*/
class SolutionStack {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        vector<int> nge(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] <= v[i]) {
                st.pop();
            }
            if (st.empty()) {
                nge[i] = i;
            } else {
                nge[i] = st.top();
            }
            st.push(i);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(nge[i] - i);
        }
        return ans;
    }
};