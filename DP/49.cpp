// 132. Palindrome Partitioning II

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
    bool palin(int i, int j, string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,int n, string &s, vector<int> &dp)
    {
        if(i==n)
        {
            return  0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans = n;
        for(int j=i; j<n; j++)
        {
            if(palin(i,j,s))
            {
                int cut = 1+ solve(j+1,n,s,dp);
                ans=min(ans, cut);
            }
        }
        return dp[i] =  ans;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return solve(0,n,s,dp) -1;
    }
};

class Tabulation {
public:
    bool palin(int i, int j, string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);

        for(int i=n-1; i>=0; i--)
        {
            int ans = n;
            for(int j=i; j<n; j++)
            {
                if(palin(i,j,s))
                {
                    int cut = 1+ dp[j+1];
                    ans=min(ans, cut);
                }
            }
            dp[i] =  ans;
        }

        return dp[0]-1;
        
    }
};