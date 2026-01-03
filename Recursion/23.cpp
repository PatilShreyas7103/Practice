// Permutations

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int n,
               vector<int> &ans,
               vector<vector<int>> &res,
               vector<int> &vis,
               vector<int> &v) {

        if (i == n) {
            res.push_back(ans);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;

            vis[j] = 1;
            ans.push_back(v[j]);

            solve(i + 1, n, ans, res, vis, v);

            ans.pop_back();
            vis[j] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> res;
        vector<int> ans;
        vector<int> vis(n, 0);

        solve(0, n, ans, res, vis, v);
        return res;
    }
};