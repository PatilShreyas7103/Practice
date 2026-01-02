// Subsets II

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Using Set (Brute Force + Deduplication)
Time: O(2^n * log(2^n))
Space: O(2^n)
*/
class SolutionSet {
public:
    void solve(int n, vector<int> &v,
               vector<int> ans, set<vector<int>> &st) {
        if (n < 0) {
            st.insert(ans);
            return;
        }

        // exclude current element
        solve(n - 1, v, ans, st);

        // include current element
        ans.push_back(v[n]);
        solve(n - 1, v, ans, st);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());

        set<vector<int>> st;
        vector<int> ans;
        solve(v.size() - 1, v, ans, st);

        vector<vector<int>> res;
        for (auto &it : st) {
            res.push_back(it);
        }
        return res;
    }
};

/*
Approach 2: Optimized Backtracking (Preferred)
Time: O(2^n)
Space: O(n) recursion stack
*/
class SolutionOptimized {
public:
    void solve(int idx, vector<int>& v,
               vector<int>& ans, vector<vector<int>>& res) {

        res.push_back(ans);

        for (int i = idx; i < v.size(); i++) {
            // skip duplicates at the same recursion level
            if (i > idx && v[i] == v[i - 1]) {
                continue;
            }

            ans.push_back(v[i]);
            solve(i + 1, v, ans, res);
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());

        vector<vector<int>> res;
        vector<int> ans;
        solve(0, v, ans, res);
        return res;
    }
};