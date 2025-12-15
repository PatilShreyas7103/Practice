// 714. Best Time to Buy and Sell Stock with Transaction Fee

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

class Solution {
public:
    int solve(int i, int buy, vector<int> &v, int n,
    vector<vector<int>> &dp, int f)
    {
        if(i==n)
        {
            return 0;
        }

        if(dp[i][buy]!=-1)
        {
            return dp[i][buy];
        }

        if(buy)
        {
            return dp[i][buy] = max(solve(i+1,buy,v,n,dp,f), -v[i]+solve(i+1,!buy,v,n,dp,f));
        }
        else
        {
            return dp[i][buy] = max(solve(i+1,buy,v,n,dp,f), v[i]-f+solve(i+1,!buy,v,n,dp,f));
        }
    }
    int maxProfit(vector<int>& v, int f) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return solve(0,1,v,n,dp,f);
    }
};


class Solution {
public:

    int maxProfit(vector<int>& v, int f) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=1; j>=0; j--)
            {
                if(j==1)
                {
                    // buy
                    dp[i][j] = max(dp[i+1][j], -v[i]+dp[i+1][!j]);
                }   
                else
                {
                    // sell
                    dp[i][j] = max(dp[i+1][j], v[i]-f+dp[i+1][!j]);
                }
            }
        }

        return dp[0][1];
    }
};