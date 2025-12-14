// Count Subsets with Sum K

#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class PerfectSumMemoization {
public:
    int solve(int index, int target,
              vector<int> &nums,
              vector<vector<int>> &dp) {

        if (index == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;   // {} and {0}
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        if (dp[index][target] != -1)
            return dp[index][target];

        int notTake = solve(index - 1, target, nums, dp);
        int take = 0;

        if (nums[index] <= target)
            take = solve(index - 1, target - nums[index], nums, dp);

        return dp[index][target] = take + notTake;
    }

    int perfectSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, target, nums, dp);
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class Tabulation {
  public:
    int perfectSum(vector<int>& v, int t) {
        // code here
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (t+1,0));
        
        for(int i=0; i<n; i++)
        {
            dp[i][0] = 1;
        }
        if(v[0]<=t)
        {
            dp[0][v[0]] += 1;
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=t; j++)
            {
                int dont = dp[i-1][j];
                int take = 0;
                if(j-v[i]>=0)
                {
                    take = dp[i-1][j-v[i]];
                }
                
                dp[i][j] = take+dont;
            }
        }
        return dp[n-1][t];
    }
};