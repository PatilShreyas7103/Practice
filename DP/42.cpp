// 1048. Longest String Chain

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


class Solution {
public:
    bool validate(string s, string t)
    {
        if(s.length()+1!=t.length())
        {
            return false;
        }
        int i = 0;
        int j = 0;
        int n = s.length();
        while(i<n && j<n+1)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(j-i>1)
        {
            return false;
        }
        
        return true;
    }
    int longestStrChain(vector<string>& v) {
        int n = v.size();
        vector<int> dp(n,1);
        vector<pair<int,string>> p;
        for(auto it: v)
        {
            int len = it.length();
            p.push_back({len,it});
        }
        sort(p.begin(), p.end());
        int mx = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(validate(p[j].second,p[i].second))
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i] = 1+dp[j];
                    }
                }
            }
            mx = max(mx, dp[i]);
        }

        return mx;
    }
};