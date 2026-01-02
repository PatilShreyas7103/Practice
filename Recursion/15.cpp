// Combination Sum III

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int num, vector<vector<int>> &res,
               vector<int> ans, int k, int t) {

        if (k == 0) {
            if (t == 0) {
                res.push_back(ans);
            }
            return;
        }

        if (num > 9 || num > t) {
            return;
        }

        // don't take current number
        solve(num + 1, res, ans, k, t);

        // take current number
        ans.push_back(num);
        solve(num + 1, res, ans, k - 1, t - num);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ans;
        solve(1, res, ans, k, n);
        return res;
    }
};