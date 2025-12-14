// Minimum Subset Sum Difference 
#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class MinSubsetDiffMemoization {
public:
    bool solve(int index, int target,
               vector<int> &nums,
               vector<vector<int>> &dp) {
        if (target == 0)
            return true;

        if (index == 0)
            return nums[0] == target;

        if (dp[index][target] != -1)
            return dp[index][target];

        bool notTake = solve(index - 1, target, nums, dp);
        bool take = false;

        if (nums[index] <= target)
            take = solve(index - 1, target - nums[index], nums, dp);

        return dp[index][target] = (take || notTake);
    }

    int minimumDifference(vector<int> &nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int ans = INT_MAX;
        for (int s1 = target; s1 >= 0; s1--) {
            if (solve(n - 1, s1, nums, dp)) {
                ans = abs(sum - 2 * s1);
                break;
            }
        }
        return ans;
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class MinSubsetDiffTabulation {
public:
    int minimumDifference(vector<int> &nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base cases
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[i - 1][t];
                bool take = (nums[i] <= t) ? dp[i - 1][t - nums[i]] : false;
                dp[i][t] = take || notTake;
            }
        }

        int ans = INT_MAX;
        for (int s1 = target; s1 >= 0; s1--) {
            if (dp[n - 1][s1]) {
                ans = abs(sum - 2 * s1);
                break;
            }
        }
        return ans;
    }
};