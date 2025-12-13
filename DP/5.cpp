// House Robber 
#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class HouseRobberMemoization {
public:
    int solve(int index, vector<int> &nums, vector<int> &dp) {
        if (index == 0)
            return nums[0];

        if (index == 1)
            return max(nums[0], nums[1]);

        if (dp[index] != -1)
            return dp[index];

        int take = nums[index] + solve(index - 2, nums, dp);
        int notTake = solve(index - 1, nums, dp);

        return dp[index] = max(take, notTake);
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class HouseRobberTabulation {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int take = nums[i] + dp[i - 2];
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }
};

/* -------------------- Space Optimized DP -------------------- */
class HouseRobberSpaceOptimized {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int prev2 = nums[0];                 // dp[i-2]
        int prev1 = max(nums[0], nums[1]);   // dp[i-1]

        for (int i = 2; i < n; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;
            int curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};