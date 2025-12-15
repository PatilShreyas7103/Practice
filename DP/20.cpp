// Unbounded Knapsack

#include <bits/stdc++.h>
using namespace std;

/* ===================== MEMOIZATION (Top-Down) ===================== */
class SolutionMemo {
private:
    int solve(int i, int w, vector<int>& val, vector<int>& wt,
              vector<vector<int>>& dp) {
        if (i == 0) {
            return (w / wt[0]) * val[0];
        }

        if (dp[i][w] != -1)
            return dp[i][w];

        int notTake = solve(i - 1, w, val, wt, dp);
        int take = INT_MIN;

        if (w >= wt[i]) {
            take = val[i] + solve(i, w - wt[i], val, wt, dp);
        }

        return dp[i][w] = max(take, notTake);
    }

public:
    int knapSack(vector<int>& val, vector<int>& wt, int w) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        return solve(n - 1, w, val, wt, dp);
    }
};

/* ===================== TABULATION (Bottom-Up) ===================== */
class SolutionTab {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int w) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(w + 1, 0));

        // Base case
        for (int j = 0; j <= w; j++) {
            dp[0][j] = (j / wt[0]) * val[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= w; j++) {
                int notTake = dp[i - 1][j];
                int take = INT_MIN;

                if (wt[i] <= j) {
                    take = val[i] + dp[i][j - wt[i]];
                }

                dp[i][j] = max(take, notTake);
            }
        }

        return dp[n - 1][w];
    }
};