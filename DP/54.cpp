// 0/1 Knapsack problem

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
    int solve(int i, int t, vector<int> &val, 
    vector<int> &wt, vector<vector<int>> &dp)
    {
        if(i<0)
        {
            return 0;
        }
        
        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }
        int dont = solve(i-1,t,val,wt,dp);
        int take = 0;
        if(t>=wt[i])
        {
            take = val[i]+solve(i-1,t-wt[i],val,wt,dp);
        }
        
        return dp[i][t] = max(take,dont);
    }
    int knapsack(int cap, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (cap+1,-1));
        return solve(n-1,cap,val,wt,dp);
    }
};

class Tabulation {
  public:

    int knapsack(int cap, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int> (cap+1,0));
        for(int i=1; i<=n; i++)
        {
            for(int t=0; t<=cap; t++)
            {
                int dont = dp[i-1][t];
                int take = 0;
                if(t>=wt[i-1])
                {
                    take = val[i-1]+dp[i-1][t-wt[i-1]];
                }
                
                dp[i][t] = max(take,dont);
            }
        }
        
        return dp[n][cap];
    }
};