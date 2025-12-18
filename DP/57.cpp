// 139. Word Break

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
    bool solve(int i, int n, string &s, set<string> &st, vector<int> &dp)
    {
        if(i==n)
        {
            return true;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        for(int j=i; j<n; j++)
        {
            string k = s.substr(i,j-i+1);
            if(st.find(k)!=st.end())
            {
                bool h = solve(j+1,n,s,st,dp);
                if(h)
                {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] =  false;
    }
    bool wordBreak(string s, vector<string>& w) {
        int n = s.length();
        set<string> st;
        for(auto it: w)
        {
            st.insert(it);
        }
        vector<int> dp(n,-1);
        return solve(0,n,s,st,dp);
    }
};

class Tabulation {
public: 
    
    bool wordBreak(string s, vector<string>& w) {
        int n = s.length();
        set<string> st;
        for(auto it: w)
        {
            st.insert(it);
        }
        vector<int> dp(n+1,0);
        dp[n] = 1;

        for(int i=n-1; i>=0; i--)
        {
            bool f = false;
            for(int j=i; j<n; j++)
            {
                string k = s.substr(i,j-i+1);
                if(st.find(k)!=st.end())
                {
                    bool h = dp[j+1];
                    f = f | h;
                }
            }
            dp[i] = f;
        }

        return dp[0];
    }
};