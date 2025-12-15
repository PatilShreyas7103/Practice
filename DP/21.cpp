// Rod Cutting Problem

#include <bits/stdc++.h>
using namespace std;

/* ===================== MEMOIZATION (Top-Down) ===================== */
class SolutionMemo {
private:
    int solve(int i, int w, vector<int>& p, vector<vector<int>>& dp) {
        if (i == 0) {
            return w * p[0];
        }

        if (dp[i][w] != -1)
            return dp[i][w];

        int notTake = solve(i - 1, w, p, dp);
        int take = INT_MIN;

        if (w >= i + 1) {
            take = p[i] + solve(i, w - (i + 1), p, dp);
        }

        return dp[i][w] = max(take, notTake);
    }

public:
    int cutRod(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n - 1, n, p, dp);
    }
};

/* ===================== TABULATION (Bottom-Up) ===================== */
class SolutionTab {
public:
    int cutRod(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j * p[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                int notTake = dp[i - 1][j];
                int take = INT_MIN;

                if (j >= i + 1) {
                    take = p[i] + dp[i][j - (i + 1)];
                }

                dp[i][j] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};