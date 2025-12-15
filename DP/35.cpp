// 123. Best Time to Buy and Sell Stock III

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

    int solve(int i, int buy,int t,int n, vector<int>& p, vector<vector<vector<int>>>& dp) {
        if (i == n || t==0) {
            return 0;
        }
        if (dp[i][buy][t] != -1) {
            return dp[i][buy][t];
        }

        if (buy == 1) {
            // we can buy
            return dp[i][buy][t] = max(0 + solve(i + 1, 1,t, n, p, dp),
                                    -p[i] + solve(i + 1, 0,t, n, p, dp));
        } else {
            // we can sell
            return dp[i][buy][t] = max(0 + solve(i + 1, 0,t, n, p, dp),
                                    p[i] + solve(i + 1, 1,t-1, n, p, dp));
        }
    }

public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0,1,2,n,p,dp);
    }
};

class Tabulation {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i=n-1; i>=0; i--)
        {
            for(int t=2; t>0; t--)
            {
                dp[i][1][t] = max(dp[i+1][1][t], -p[i]+dp[i+1][0][t]);
                dp[i][0][t] = max(dp[i+1][0][t], p[i]+dp[i+1][1][t-1]); 
            }
                   
        }

        return dp[0][1][2];
    }
};