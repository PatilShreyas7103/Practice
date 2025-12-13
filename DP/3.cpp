// Frog Jump (Minimum Cost) 
#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class FrogJumpMemoization {
public:
    int solve(int index, vector<int> &heights, vector<int> &dp) {
        if (index == 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int oneStep = solve(index - 1, heights, dp)
                      + abs(heights[index] - heights[index - 1]);

        int twoStep = INT_MAX;
        if (index > 1) {
            twoStep = solve(index - 2, heights, dp)
                      + abs(heights[index] - heights[index - 2]);
        }

        return dp[index] = min(oneStep, twoStep);
    }

    int minCost(vector<int> &heights) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return solve(n - 1, heights, dp);
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class FrogJumpTabulation {
public:
    int minCost(vector<int> &heights) {
        int n = heights.size();
        vector<int> dp(n, 0);

        dp[0] = 0;
        dp[1] = abs(heights[1] - heights[0]);

        for (int i = 2; i < n; i++) {
            int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            dp[i] = min(oneStep, twoStep);
        }

        return dp[n - 1];
    }
};

/* -------------------- Space Optimized DP -------------------- */
class FrogJumpSpaceOptimized {
public:
    int minCost(vector<int> &heights) {
        int n = heights.size();
        if (n == 1) return 0;

        int prev2 = 0; // dp[i-2]
        int prev1 = abs(heights[1] - heights[0]); // dp[i-1]

        for (int i = 2; i < n; i++) {
            int oneStep = prev1 + abs(heights[i] - heights[i - 1]);
            int twoStep = prev2 + abs(heights[i] - heights[i - 2]);
            int curr = min(oneStep, twoStep);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};