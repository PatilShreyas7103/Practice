// Coin Change (LeetCode 322)

#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e8;

/* ===================== MEMOIZATION (Top-Down) ===================== */
class SolutionMemo {
private:
    int solve(int i, int t, vector<int>& c, vector<vector<int>>& dp) {
        if (i == 0) {
            if (t % c[0] == 0) return t / c[0];
            return INF;
        }

        if (dp[i][t] != -1) return dp[i][t];

        int dont = solve(i - 1, t, c, dp);
        int take = INF;
        if (t >= c[i]) {
            take = 1 + solve(i, t - c[i], c, dp);
        }

        return dp[i][t] = min(take, dont);
    }

public:
    int coinChange(vector<int>& c, int t) {
        int n = c.size();
        vector<vector<int>> dp(n, vector<int>(t + 1, -1));

        int ans = solve(n - 1, t, c, dp);
        return (ans >= INF ? -1 : ans);
    }
};

/* ===================== TABULATION (Bottom-Up) ===================== */
class SolutionTab {
public:
    int coinChange(vector<int>& c, int t) {
        int n = c.size();
        vector<vector<int>> dp(n, vector<int>(t + 1, INF));

        // Base case
        for (int j = 0; j <= t; j++) {
            if (j % c[0] == 0)
                dp[0][j] = j / c[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= t; j++) {
                int dont = dp[i - 1][j];
                int take = INF;
                if (j >= c[i]) {
                    take = 1 + dp[i][j - c[i]];
                }
                dp[i][j] = min(take, dont);
            }
        }

        return (dp[n - 1][t] >= INF ? -1 : dp[n - 1][t]);
    }
};