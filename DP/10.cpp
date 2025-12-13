// Minimum Path Sum 
#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class MinPathSumMemoization {
public:
    int solve(int r, int c,
              vector<vector<int>> &grid,
              vector<vector<int>> &dp) {
        if (r < 0 || c < 0)
            return 1e9;   // large value to block invalid paths

        if (r == 0 && c == 0)
            return grid[0][0];

        if (dp[r][c] != -1)
            return dp[r][c];

        int up = solve(r - 1, c, grid, dp);
        int left = solve(r, c - 1, grid, dp);

        return dp[r][c] = grid[r][c] + min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class MinPathSumTabulation {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] +
                           min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};

/* -------------------- Space Optimized DP -------------------- */
class MinPathSumSpaceOptimized {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 0), curr(n, 0);

        prev[0] = grid[0][0];

        for (int j = 1; j < n; j++)
            prev[j] = prev[j - 1] + grid[0][j];

        for (int i = 1; i < m; i++) {
            curr[0] = prev[0] + grid[i][0];
            for (int j = 1; j < n; j++) {
                curr[j] = grid[i][j] +
                          min(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};