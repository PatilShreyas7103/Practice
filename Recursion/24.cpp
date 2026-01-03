// K-th Permutation Sequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* =========================
       APPROACH 1: BRUTE FORCE
       Generate all permutations
       Time: O(n! * n)
       Space: O(n!)
       ========================= */

    void solveBrute(int i, int n,
                    vector<int> &curr,
                    vector<vector<int>> &res,
                    vector<int> &vis,
                    vector<int> &nums) {

        if (i == n) {
            res.push_back(curr);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;

            vis[j] = 1;
            curr.push_back(nums[j]);

            solveBrute(i + 1, n, curr, res, vis, nums);

            curr.pop_back();
            vis[j] = 0;
        }
    }

    string getPermutationBrute(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);

        vector<vector<int>> res;
        vector<int> curr;
        vector<int> vis(n, 0);

        solveBrute(0, n, curr, res, vis, nums);

        vector<int> kth = res[k - 1];
        string ans = "";
        for (int x : kth) {
            ans += to_string(x);
        }
        return ans;
    }

    /* =========================
       APPROACH 2: OPTIMAL
       Factorial based selection
       Time: O(n^2)
       Space: O(n)
       ========================= */

    string getPermutationOptimal(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        vector<int> fact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i;
        }

        k--; // convert to 0-based index
        string ans = "";

        for (int i = n; i >= 1; i--) {
            int idx = k / fact[i - 1];
            ans += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
            k %= fact[i - 1];
        }

        return ans;
    }
};