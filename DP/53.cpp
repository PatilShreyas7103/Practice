// Cherry Pickup II
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

class MemoizationSolution {
public:
    int m, n;

    int solve(int r, int c1, int c2,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n)
            return 0;

        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int cherries = grid[r][c1];
        if (c1 != c2)
            cherries += grid[r][c2];

        if (r == m - 1)
            return dp[r][c1][c2] = cherries;

        int maxi = 0;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                maxi = max(maxi,
                           solve(r + 1, c1 + i, c2 + j, grid, dp));
            }
        }

        return dp[r][c1][c2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, -1))
        );

        return solve(0, 0, n - 1, grid, dp);
    }
};


class TabulationSolution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[r][c1][c2]
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, 0))
        );

        // Base case: last row
        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = 0; c2 < n; c2++) {
                if (c1 == c2)
                    dp[m - 1][c1][c2] = grid[m - 1][c1];
                else
                    dp[m - 1][c1][c2] = grid[m - 1][c1] + grid[m - 1][c2];
            }
        }

        // Fill DP from bottom to top
        for (int r = m - 2; r >= 0; r--) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int c2 = 0; c2 < n; c2++) {

                    int maxi = 0;

                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            int nc1 = c1 + i;
                            int nc2 = c2 + j;

                            if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                                maxi = max(maxi, dp[r + 1][nc1][nc2]);
                            }
                        }
                    }

                    int cherries = grid[r][c1];
                    if (c1 != c2)
                        cherries += grid[r][c2];

                    dp[r][c1][c2] = cherries + maxi;
                }
            }
        }

        // Robots start at (0,0) and (0,n-1)
        return dp[0][0][n - 1];
    }
};