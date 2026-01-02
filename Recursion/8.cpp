// Generate All Subsets (Power Set)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, vector<int> &v, vector<int> ans, vector<vector<int>> &res) {
        if (n < 0) {
            res.push_back(ans);
            return;
        }

        // exclude current element
        solve(n - 1, v, ans, res);

        // include current element
        ans.push_back(v[n]);
        solve(n - 1, v, ans, res);
    }

    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> res;
        vector<int> ans;
        solve(v.size() - 1, v, ans, res);
        return res;
    }
};