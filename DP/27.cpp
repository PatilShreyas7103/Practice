// 1312. Minimum Insertion Steps to Make a String Palindrome

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
    int solve(string p, string q, int i, int j, 
    vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(p[i]==q[j])
        {
            // can take
            return dp[i][j] = 1+solve(p,q,i-1,j-1,dp);
        }
        else
        {
            return dp[i][j] = max(solve(p,q,i-1,j,dp), solve(p,q,i,j-1,dp));
        }
    }

    int minInsertions(string q) {
        string p = q;
        reverse(p.begin(), p.end());
        int n = q.length();

        vector<vector<int>> dp(n, vector<int> (n,-1));
        return n-solve(p,q,n-1,n-1,dp);
    }
};

class Tabulation {
public:
    int minInsertions(string p) {
        string q = p;
        reverse(q.begin(), q.end());
        int n = q.length();

        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(p[i-1]==q[j-1])
                {
                    // take
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return n-dp[n][n];
    }
};