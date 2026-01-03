// Permutations II 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int,int> cnt;

    void solve(int n, vector<int> &ans) {
        if (ans.size() == n) {
            res.push_back(ans);
            return;
        }

        for (auto &it : cnt) {
            int val = it.first;
            int &freq = it.second;

            if (freq == 0) continue;

            freq--;
            ans.push_back(val);

            solve(n, ans);

            ans.pop_back();
            freq++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int x : nums) cnt[x]++;

        vector<int> ans;
        solve(nums.size(), ans);

        return res;
    }
};