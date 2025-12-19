// Coin Change II

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
    int solve(int i, vector<int> &c, int t, 
    vector<vector<int>> &dp)
    {
        if(i<0)
        {
            return 0;
        }
        if(t==0)
        {
            return dp[i][t]= 1;
        }

        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }

        int dont = solve(i-1,c,t,dp);
        int take = 0 ;
        if(c[i]<=t)
        {
            take = solve(i,c,t-c[i],dp);
        }

        return dp[i][t] = dont+take;
    }
    int change(int t, vector<int>& c) {
        int n = c.size();
        vector<vector<int>> dp(n, vector<int> (t+1,-1));

        return solve(n-1,c,t,dp);
    }
};


class Tabulation {
public:
    
    int change(int t, vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (t+1,0));

        for(int i=0; i<n; i++)
        {
            dp[i][0] = 1;
        }
        for(int j=0; j<=t; j++)
        {
            if(j%v[0]==0)
            {
                dp[0][j] = 1;
            }
        }
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=t; j++)
            {
                int dont = dp[i-1][j];
                int take =  0;
                if(v[i]<=j)
                {
                    take = dp[i][j-v[i]];
                }

                dp[i][j] = (long long)take+dont;
            }
        }

        return dp[n-1][t];
    }
};