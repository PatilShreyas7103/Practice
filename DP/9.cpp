// Unique Paths II 
#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class UniquePathsII_Memoization {
public:
    int solve(int r, int c,
              vector<vector<int>> &grid,
              vector<vector<int>> &dp) {
        if (r < 0 || c < 0) return 0;
        if (grid[r][c] == 1) return 0;
        if (r == 0 && c == 0) return 1;

        if (dp[r][c] != -1)
            return dp[r][c];

        int up = solve(r - 1, c, grid, dp);
        int left = solve(r, c - 1, grid, dp);

        return dp[r][c] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class UniquePathsII_Tabulation {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (grid[0][0] == 1)
            return 0;

        // First column
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) break;
            dp[i][0] = 1;
        }

        // First row
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) break;
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

/* -------------------- Space Optimized DP -------------------- */
class UniquePathsII_SpaceOptimized {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0), curr(n, 0);

        if (grid[0][0] == 1)
            return 0;

        prev[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    curr[j] = 0;
                } else if (j == 0) {
                    curr[j] = prev[j];
                } else {
                    curr[j] = curr[j - 1] + prev[j];
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};