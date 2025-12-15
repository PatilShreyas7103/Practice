// 72. Edit Distance

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
    int solve(int i, int j, string a, string b,
    vector<vector<int>> &dp)
    {
        if(i<0)
        {
            return j+1;
        }
        if(j<0)
        {
            return i+1;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(a[i]==b[j])
        {
            return dp[i][j] =  solve(i-1,j-1,a,b,dp);
        }
        else
        {
            int ins = solve(i,j-1,a,b,dp);
            int del = solve(i-1,j,a,b,dp);
            int rep = solve(i-1,j-1,a,b,dp);
            return dp[i][j] =  1+ min(ins,min(del,rep));
        }
    }
    int minDistance(string a, string b) {
        int m = a.size();
        int n = b.size();

        vector<vector<int>> dp(m, vector<int> (n,-1));

        return solve(m-1,n-1,a,b,dp);
    }
};

class Tabulation {
public:
    int minDistance(string a, string b) {
        int m = a.size();
        int n = b.size();

        vector<vector<int>> dp(m+1, vector<int> (n+1,0));

        for(int i=0; i<=m; i++)
        {
            dp[i][0] = i;
        }
        for(int i=0; i<=n; i++)
        {
            dp[0][i] = i;
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1+ min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        return dp[m][n];
    }
};