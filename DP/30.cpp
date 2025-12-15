// 115. Distinct Subsequences

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

    int solve (int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if(j<0)
        {
            return 1;
        }
        if(i<0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(s[i]==t[j])
        {
            return dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
        }
        else
        {
            return dp[i][j] =  solve(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1,m-1,s,t,dp);
    }
};

class Tabulation {
public:

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 1;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = (long long)dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
};