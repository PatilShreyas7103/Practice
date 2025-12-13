// House Robber II 

#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class HouseRobberIIMemoization {
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
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: take houses [0 ... n-2]
        vector<int> case1(nums.begin(), nums.end() - 1);
        vector<int> dp1(n - 1, -1);

        // Case 2: take houses [1 ... n-1]
        vector<int> case2(nums.begin() + 1, nums.end());
        vector<int> dp2(n - 1, -1);

        int ans1 = solve(n - 2, case1, dp1);
        int ans2 = solve(n - 2, case2, dp2);

        return max(ans1, ans2);
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class HouseRobberIITabulation {
public:
    int rob(vector<int>& v) {
        int n = v.size();

        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return v[0];
        }
        if(n==2)
        {
            return max(v[0], v[1]);
        }
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);

        vector<int> v1,v2;
        for(int i=0; i<n-1; i++)
        {
            v1.push_back(v[i]);
        }
        for(int i=1; i<n; i++)
        {
            v2.push_back(v[i]);
        }

        dp1[0] = v1[0];
        dp2[0] = v2[0];
        dp1[1] = max(v1[0], v1[1]);
        dp2[1] = max(v2[0], v2[1]);

        for(int i=2; i<n-1; i++)
        {
            int take1 = v1[i]+dp1[i-2];
            int dont1 = dp1[i-1];
            dp1[i] = max(take1,dont1);

            int take2 = v2[i]+dp2[i-2];
            int dont2 = dp2[i-1];
            dp2[i] = max(take2,dont2);
        }

        return max(dp1[n-2], dp2[n-2]);
    }
};

/* -------------------- Space Optimized DP -------------------- */
class HouseRobberIISpaceOptimized {
public:
    int robLinear(vector<int> &nums, int start, int end) {
        int prev2 = 0, prev1 = 0;

        for (int i = start; i <= end; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;
            int curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: exclude last house
        int case1 = robLinear(nums, 0, n - 2);

        // Case 2: exclude first house
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};