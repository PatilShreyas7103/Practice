// Egg Dropping Problem

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

    int solve(int e, int f, vector<vector<int>> &dp)
    
    {
        if(f==0 || f==1)
        {
            return dp[e][f] = f;
        }
        if(e==1)
        {
            return dp[e][f] = f;
        }
        
        if(dp[e][f]!=-1)
        {
            return dp[e][f];
        }
        
        int mn = INT_MAX;
        for(int i=1; i<=f; i++)
        {
            int temp = 1+max(solve(e-1,i-1,dp), solve(e,f-i,dp));
            mn = min(mn,temp);
        }
        
        return dp[e][f] = mn;
    }
    int eggDrop(int n, int k) {
        // code here
        vector<vector<int>> dp(n+1, vector<int> (k+1,-1));
        return solve(n,k,dp);
    }
};


class Tabualtion {
  public:
    int eggDrop(int e, int f) {
        // code here
        vector<vector<int>> dp(e+1, vector<int> (f+1,-1));
        for(int i=0; i<=e; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int i=0; i<=f; i++)
        {
            dp[1][i] = i;
        }
        
        for(int i=2; i<=e; i++)
        {
            for(int j=2; j<=f; j++)
            {
                int mn = INT_MAX;
                for(int k=1; k<=j; k++)
                {
                    int temp = 1+max(dp[i-1][k-1], dp[i][j-k]);
                    mn = min(mn,temp);
                }
                
                 dp[i][j] = mn;
            }
        }
        
        return dp[e][f];
    }
};