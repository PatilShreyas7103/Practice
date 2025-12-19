// Min Cost Climbing Stairs

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
    int solve(int i, vector<int> &cost, int n, vector<int>&dp)
    {
        if(i==n)
        {
            return dp[i] = 0;
        }
        if(i==n-1)
        {
            return dp[i] = cost[i];
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int one = solve(i+1,cost,n,dp);
        int two = solve(i+2,cost,n,dp);

        return dp[i] = min(one,two)+cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n  = cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(0,cost,n,dp),solve(1,cost,n,dp));
    }
};

class Tabulation {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n  = cost.size();
        vector<int> dp(n+1,0);

        dp[n-1] = cost[n-1];

        for(int i=n-2; i>=0; i--)
        {
            int one = dp[i+1];
            int two = dp[i+2];

            dp[i] = min(one,two)+cost[i];
        }    

        return min(dp[0],dp[1]);
    }
};