// 1092. Shortest Common Supersequence 

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
    int solve(int i, int j, string a, string b, vector<vector<int>> &dp)
    {
        if(i==0 || j==0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(a[i-1]==b[j-1])
        {
            return dp[i][j] = 1+ solve(i-1,j-1,a,b,dp);
        }
        else
        {
            return dp[i][j] =  max(solve(i-1,j,a,b,dp), solve(i,j-1,a,b,dp));
        }
    }
    string shortestCommonSupersequence(string a, string b) {
        int m = a.length();
        int n  = b.length();

        vector<vector<int>> dp(m+1, vector<int> (n+1,-1));  
        int lcs = solve(m,n,a,b,dp);
        int i = m;
        int j = n;
        string ans = "";

        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                ans+= a[i-1];
                i--;
                j--;
            }
            else 
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    ans+=a[i-1];
                    i--;
                }
                else
                {
                    ans+= b[j-1];
                    j--;
                }
            }
        }
        while(i>0)
        {
            ans+=a[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=b[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

class Tabulation {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m = a.length();
        int n  = b.length();

        vector<vector<int>> dp(m+1, vector<int> (n+1,0));  
        // int lcs = solve(m,n,a,b,dp);
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int i = m;
        int j = n;
        string ans = "";

        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                ans+= a[i-1];
                i--;
                j--;
            }
            else 
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    ans+=a[i-1];
                    i--;
                }
                else
                {
                    ans+= b[j-1];
                    j--;
                }
            }
        }
        while(i>0)
        {
            ans+=a[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=b[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};