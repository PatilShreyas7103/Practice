// 931. Minimum Falling Path Sum

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
    int solve(int r, int c, vector<vector<int>> &v, int n
    , vector<vector<int>> &dp)
    {
        if(r<0 || c<0 || c>=n)
        {
            return 1e9;
        }

        if(r==0)
        {
            return dp[r][c] = v[r][c];
        }

        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }

        int f1 = solve(r-1,c,v,n,dp);
        int f2 = solve(r-1,c-1,v,n,dp);
        int f3 = solve(r-1,c+1,v,n,dp);    

        int mn = min({f1,f2,f3});

        return dp[r][c] = mn+v[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size();
        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int> (n,-1));

        for(int i=0; i<n; i++)
        {
            ans=min(ans, solve(n-1,i,v,n,dp));
        }

        return ans;
    }
};

class Tabulation {
public:

    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size();
        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int> (n,INT_MAX));

        for(int i=0; i<n; i++)
        {
            dp[0][i] = v[0][i];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int f1 = dp[i-1][j];
                int f2 = INT_MAX;
                if(j<n-1)
                {
                    f2 = dp[i-1][j+1];
                }
                int f3 = INT_MAX;
                if(j>0)
                {
                    f3 = dp[i-1][j-1];
                }
                dp[i][j] = v[i][j]+min({f1,f2,f3});
            }
        }

        for(int i=0; i<n; i++)
        {
            ans=min(ans, dp[n-1][i]);
        }

        return ans;
    }
};