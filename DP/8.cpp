// Unique Paths
#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class UniquePathsMemoization {
public:
    int solve(int row, int col, vector<vector<int>> &dp) {
        if (row == 0 || col == 0)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] =
            solve(row - 1, col, dp) + solve(row, col - 1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class UniquePathsTabulation {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

/* -------------------- Space Optimized DP -------------------- */
class UniquePathsSpaceOptimized {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1), curr(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                curr[j] = curr[j - 1] + prev[j];
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};