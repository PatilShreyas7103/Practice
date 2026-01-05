// Sum of Subarray Minimums

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int sumSubarrayMins(vector<int>& v) {
        int n = v.size();
        int mod = 1e9 + 7;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int mn = INT_MAX;
            for (int j = i; j < n; j++) {
                mn = min(mn, v[j]);
                sum = (sum + mn) % mod;
            }
        }
        return sum;
    }
};

/*
Approach 2: Monotonic Stack (PSE + NSE)
Time: O(n)
Space: O(n)
*/
class SolutionStack {
public:
    int mod = 1e9 + 7;

    vector<int> findnse(vector<int>& v) {
        int n = v.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] >= v[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findpse(vector<int>& v) {
        int n = v.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] > v[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& v) {
        int n = v.size();
        vector<int> nse = findnse(v);
        vector<int> pse = findpse(v);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long l = i - pse[i];
            long long r = nse[i] - i;
            ans = (ans + (l * r % mod) * v[i] % mod) % mod;
        }
        return ans;
    }
};