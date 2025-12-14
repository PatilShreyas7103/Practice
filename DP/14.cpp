// 416. Partition Equal Subset Sum

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

    bool solve(int i, int t, vector<int> &v, 
    vector<vector<int>> &dp)
    {
        if(i<0 || t<0)
        {
            return false;
        }
        if(t==0)
        {
            return dp[i][t] = true;
        }
        
        if(i==0)
        {
            return dp[i][t] = t==v[0];
        }
        
        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }
        
        int dont = solve(i-1,t,v,dp);
        int take = false;
        if(t-v[i]>=0)
        {
            take = solve(i-1,t-v[i],v,dp);
        }
        
        return dp[i][t] = dont || take;
        
    }

    bool canPartition(vector<int>& v) {
        int sum = 0;
        for(auto it: v)
        {
            sum+=it;
        }
        if(sum&1)
        {
            return false;
        }

        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (sum/2+1,-1));
        return solve(n-1,sum/2,v,dp);
    }
};

class Tabulation {
  public:
  
    bool canPartition(vector<int>& v) {
        int sum = 0;
        for(auto it: v)
        {
            sum+=it;
        }
        if(sum&1)
        {
            return false;
        }

        int n = v.size();
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int> (target+1,0));
        
        for(int i=0; i<n; i++)
        {
            dp[i][0] = 1;
        }
        
        if(v[0]<=target)
        {
            dp[0][v[0]] = 1;
        }
        
        for(int i=1; i<n; i++)
        {
            for(int t=1; t<=target; t++)
            {
                int dont = dp[i-1][t];
                int take = 0;
                if(t-v[i]>=0)
                {
                    take = dp[i-1][t-v[i]];
                }
                
                dp[i][t] = dont || take;
            }
        }
        
        return dp[n-1][target];
    }
};