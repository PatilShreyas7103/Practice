// Combinations 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int num, int n, int k,
               vector<int> &ans,
               vector<vector<int>> &res) {

        if (k == 0) {
            res.push_back(ans);
            return;
        }

        if (num > n) {
            return;
        }

        // Pruning: not enough numbers left
        if ((n - num + 1) < k) {
            return;
        }

        // Take current number
        ans.push_back(num);
        solve(num + 1, n, k - 1, ans, res);
        ans.pop_back();

        // Do not take current number
        solve(num + 1, n, k, ans, res);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ans;
        solve(1, n, k, ans, res);
        return res;
    }
};