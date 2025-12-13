// Triangle

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
    int solve(int r, int c, vector<vector<int>> &v, vector<vector<int>> &dp)
    {
        if(r<0 || c<0 || c>r)
        {
            return INT_MAX;
        }

        if(r==0)
        {
            return dp[r][c] = v[0][0];
        }

        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }

        int f1 = solve(r-1,c,v,dp);
        int f2 = solve(r-1,c-1,v,dp);

        return dp[r][c] = v[r][c]+ min(f1,f2);
    }
    int minimumTotal(vector<vector<int>>& v) {
        int m = v.size();

        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int> (m, -1));
        for(int i=0; i<m; i++)
        {
            ans=min(ans, solve(m-1,i,v,dp));
        }

        return ans;
    }
};

class Tabulation {
public:

    int minimumTotal(vector<vector<int>>& v) {
        int m = v.size();

        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int> (m, INT_MAX));

        dp[0][0] = v[0][0];
        for(int i=1; i<m; i++)
        {
            dp[i][0] = dp[i-1][0]+v[i][0];
        }

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<=i; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1])+v[i][j];
            }
        }

        for(int i=0; i<m; i++)
        {
            ans=min(ans, dp[m-1][i]);
        }

        return ans;
    }
};