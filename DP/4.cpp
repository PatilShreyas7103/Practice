// Frog Jump with K Distance

#include <bits/stdc++.h>
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
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class FrogJumpKMemoization {
public:
    int solve(int index, vector<int> &heights, vector<int> &dp, int k) {
        if (index == 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int minCost = INT_MAX;

        for (int jump = 1; jump <= k; jump++) {
            if (index - jump >= 0) {
                int cost = solve(index - jump, heights, dp, k)
                           + abs(heights[index] - heights[index - jump]);
                minCost = min(minCost, cost);
            }
        }

        return dp[index] = minCost;
    }

    int minCost(vector<int> &heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return solve(n - 1, heights, dp, k);
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class FrogJumpKTabulation {
public:
    int minCost(vector<int> &heights, int k) {
        int n = heights.size();
        vector<int> dp(n, 0);

        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            int minCost = INT_MAX;

            for (int jump = 1; jump <= k; jump++) {
                if (i - jump >= 0) {
                    int cost = dp[i - jump]
                               + abs(heights[i] - heights[i - jump]);
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[n - 1];
    }
};

/* -------------------- Space Optimized DP -------------------- */
/*
NOTE:
True O(1) space optimization is NOT possible here because
we need the last k states. Best possible optimization is O(k).
*/
class FrogJumpKSpaceOptimized {
public:
    int minCost(vector<int> &heights, int k) {
        int n = heights.size();
        deque<int> dp;  // stores last k dp values

        dp.push_back(0); // dp[0]

        for (int i = 1; i < n; i++) {
            int minCost = INT_MAX;
            int size = dp.size();

            for (int j = 1; j <= min(k, size); j++) {
                int cost = dp[size - j]
                           + abs(heights[i] - heights[i - j]);
                minCost = min(minCost, cost);
            }

            dp.push_back(minCost);
            if ((int)dp.size() > k)
                dp.pop_front();
        }

        return dp.back();
    }
};