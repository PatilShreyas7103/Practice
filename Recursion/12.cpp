// Combination Sum II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, vector<int>& v, int target,
               vector<int>& ans, vector<vector<int>>& res) {

        if (target == 0) {
            res.push_back(ans);
            return;
        }

        if (idx == v.size() || target < 0) {
            return;
        }

        for (int i = idx; i < v.size(); i++) {
            // skip duplicates at the same recursion level
            if (i > idx && v[i] == v[i - 1]) {
                continue;
            }

            if (v[i] > target) {
                break; // since array is sorted
            }

            ans.push_back(v[i]);
            // move to next index (each number used only once)
            solve(i + 1, v, target - v[i], ans, res);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> ans;

        solve(0, candidates, target, ans, res);
        return res;
    }
};