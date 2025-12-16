// Longest Increasing Subsequence (LIS)

#include <bits/stdc++.h>
using namespace std;

/* -------------------- 1. Memoization (Top-Down DP) -------------------- */
class Memoization {
public:
    int solve(int i, int pre, vector<int>& v, int n, vector<vector<int>>& dp) {
        if (i == n) return 0;

        if (dp[i][pre + 1] != -1)
            return dp[i][pre + 1];

        int notTake = solve(i + 1, pre, v, n, dp);
        int take = 0;

        if (pre == -1 || v[i] > v[pre]) {
            take = 1 + solve(i + 1, i, v, n, dp);
        }

        return dp[i][pre + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, -1, v, n, dp);
    }
};

/* -------------------- 2. Tabulation (Bottom-Up DP) -------------------- */
class Tabulation {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int pre = i - 1; pre >= -1; pre--) {
                int notTake = dp[i + 1][pre + 1];
                int take = 0;

                if (pre == -1 || v[i] > v[pre]) {
                    take = 1 + dp[i + 1][i + 1];
                }

                dp[i][pre + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};

/* -------------------- 3. Space Optimized DP (1D LIS) -------------------- */
class SpaceOptimized {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (v[j] < v[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

/* -------------------- 4. Optimal O(N log N) Approach -------------------- */
// ---------------------- Binary Search ----------------------
class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        vector<int> temp;
        int n = v.size();
        temp.push_back(v[0]);
        for(int i=1; i<n; i++)
        {
            if(v[i]>temp.back())
            {
                temp.push_back(v[i]);
            }
            else
            {
                int id = lower_bound(temp.begin(), temp.end(), v[i])-temp.begin();
                temp[id] = v[i];
            }
        }

        return temp.size();
    }
};