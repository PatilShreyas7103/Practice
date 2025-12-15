// Best Time to Buy and Sell Stock II 

#include <bits/stdc++.h>
using namespace std;

/* ===================== MEMOIZATION (Top-Down) ===================== */
class SolutionMemo {
private:
    int solve(int i, int buy, vector<int>& v, int n,
              vector<vector<int>>& dp) {
        if (i == n) return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy) {
            return dp[i][buy] = max(
                solve(i + 1, buy, v, n, dp),
                -v[i] + solve(i + 1, !buy, v, n, dp)
            );
        } else {
            return dp[i][buy] = max(
                solve(i + 1, buy, v, n, dp),
                v[i] + solve(i + 1, !buy, v, n, dp)
            );
        }
    }

public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, v, n, dp);
    }
};

/* ===================== TABULATION (Bottom-Up) ===================== */
class SolutionTab {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[i][buy] = max(
                        dp[i + 1][buy],
                        -v[i] + dp[i + 1][!buy]
                    );
                } else {
                    dp[i][buy] = max(
                        dp[i + 1][buy],
                        v[i] + dp[i + 1][!buy]
                    );
                }
            }
        }

        return dp[0][1];
    }
};