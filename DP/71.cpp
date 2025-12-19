// 494. Target Sum

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

class BruteForceSolution {

public:
    int solve(int i,vector<int> &v, int sum, int t)
    {
        if(i<0)
        {
            return sum==t;
        }

        int pos = solve(i-1,v,sum+v[i],t);
        int neg = solve(i-1,v,sum-v[i],t);

        return pos+neg;
    }
    int findTargetSumWays(vector<int>& v, int t) {
        int n = v.size();

        return solve(n-1,v,0,t);
    }
};

class Memoization {
public:
    int solve(int i, vector<int> &v, int t, int total, int sum,
    vector<vector<int>> &dp)
    {
        if(i<0)
        {
            return sum==t;
        }

        if(dp[i][sum+total]!=-1)
        {
            return dp[i][sum+total];
        }

        int pos = solve(i-1,v,t,total,sum+v[i],dp);
        int neg = solve(i-1,v,t,total,sum-v[i],dp);

        return dp[i][sum+total]= pos+neg;
    }
    int findTargetSumWays(vector<int>& v, int t) {
        int n = v.size();

        int total = accumulate(v.begin(), v.end(),0);
        vector<vector<int>> dp(n+1, vector<int> (2*total+1,-1));
        return solve(n-1,v,t,total,0,dp);
    }
};

