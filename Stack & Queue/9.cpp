// Sum of Subarray Ranges

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Monotonic Stack (Contribution Technique)
Time: O(n)
Space: O(n)

Idea:
Total Range Sum = (Sum of all subarray maximums) - (Sum of all subarray minimums)

For each element:
- Count how many subarrays where it acts as minimum
- Count how many subarrays where it acts as maximum
*/
class SolutionStack {
public:
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

    vector<int> findnge(vector<int>& v) {
        int n = v.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] <= v[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findpge(vector<int>& v) {
        int n = v.size();
        vector<int> pge(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] < v[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    long long subArrayRanges(vector<int>& v) {
        int n = v.size();

        vector<int> nse = findnse(v);
        vector<int> pse = findpse(v);
        vector<int> nge = findnge(v);
        vector<int> pge = findpge(v);

        long long maxi = 0, mini = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            mini += leftMin * rightMin * v[i];

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            maxi += leftMax * rightMax * v[i];
        }

        return maxi - mini;
    }
};