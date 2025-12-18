// Max Sum Increasing Subsequence

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
    int solve(int i, int last, vector<int> &v, int n,
    vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][last]!=-1)
        {
            return dp[i][last];
        }
        
        int take = 0;
        if(last==0 || v[i]>v[last-1])
        {
            take = v[i] + solve(i+1,i+1,v,n,dp);
        }
        int dont = solve(i+1,last,v,n,dp);
        
        return dp[i][last] =  max(dont,take);
    }
    int maxSumIS(vector<int>& v) {
        // Your code goes here
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return solve(0,0,v,n,dp);
    }
};

class Tabulation {
  public:

    int maxSumIS(vector<int>& v) {
        // Your code goes here
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n; j>=0; j--)
            {
                int take = 0;
                if(j==0 || v[i]>v[j-1])
                {
                    take = v[i] + dp[i+1][i+1];
                }
                int dont = dp[i+1][j];
                
                dp[i][j] =  max(dont,take);
            }
        }
        
        return dp[0][0];
    }
};