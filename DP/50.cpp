// Partition Array for Maximum Sum 

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
    int solve(int i, int n, vector<int> &v, int k, vector<int> &dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int mx = 0;
        int len = 0;
        int ans = 0;

        for(int j=i; j<min(i+k,n); j++)
        {
            len++;
            mx = max(mx, v[j]);
            int key = mx*len + solve(j+1,n,v,k,dp);
            ans=max(ans, key);
        }

        return dp[i] =  ans;
    }

    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n, -1);
        return solve(0,n,v,k,dp);
    }
};

class Tabulation {
public:
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--)
        {
            int mx = 0;
            int len = 0;
            int ans = 0;

            for(int j=i; j<min(i+k,n); j++)
            {
                len++;
                mx = max(mx, v[j]);
                int key = mx*len + dp[j+1];
                ans=max(ans, key);
            }
            dp[i] = ans;
        }

        return dp[0];
    }
};