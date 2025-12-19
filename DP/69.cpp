// Perfect Squares

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

class Memoization {
public:
    int solve(int t, vector<int> &dp)
    {
        if(t==0)
        {
            return dp[t] = 0;
        }
        if(dp[t]!=-1)
        {
            return dp[t];
        }
        int k = t;
        for (int s  = 1; s * s <= t; s++) {
            k = min(k, 1 + solve(t-s*s,dp));
        }

        return dp[t] = k;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);

        return solve(n,dp);
    }
};

class Tabulation {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int target = 1; target <= n; target++) {
            for (int s = 1; s * s <= target; s++) {
                dp[target] = min(dp[target], 1 + dp[target - s * s]);
            }
        }

        return dp[n];
    }
};