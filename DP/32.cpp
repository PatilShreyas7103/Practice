// 44. Wildcard Matching

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
    bool perform (string t, int j)
    {
        for(int i=0; i<=j; i++)
        {
            if(t[i]!='*')
            {
                return false;
            }
        }
        return true;
    }

    bool solve(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        else if(j<0 && i>=0)
        {
            return false;
        }
        else if(i<0 && j>=0)
        {
            return perform (t,j);
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            return dp[i][j] = solve(i-1,j-1,s,t,dp);
        }
        else
        {
            if(t[j]=='?')
            {
                return dp[i][j] = solve(i-1,j-1,s,t,dp);
            }
            else if(t[j]=='*')
            {
                return  dp[i][j] = solve(i-1,j,s,t,dp) || solve(i,j-1,s,t,dp);
            }
            else
            {
                return false;
            }
        }
    }
    bool isMatch(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n, vector<int> (m,-1));
        return solve(n-1,m-1,s,t,dp);
        
    }
};

class Tabulation {
public:
    bool isMatch(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++)
        {
            dp[i][0] = false;
        }
        bool f = true;
        for(int j=1; j<=m; j++)
        {
            if(t[j-1]!='*')
            {
                f = false;
            }
            dp[0][j] = f;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m;  j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    if(t[j-1]=='?')
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(t[j-1]=='*')
                    {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[n][m];
    }
};