// Print Longest Increasing Subsequence

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
    vector<int> getLIS(vector<int>& v) {
        // Code here
        int n = v.size();

        vector<int> dp(n,1);
        vector<int> par(n,0);
        int last = 0;
        int maxi = 1;
        for(int i=0; i<n; i++)
        {
            par[i] = i;
            for(int j=0; j<i; j++)
            {
                if(v[j]<v[i])
                {
                    if(1+dp[j]>dp[i])
                    {
                        dp[i] = 1+dp[j];
                        par[i] = j;
                    }
                }
            }
            if(dp[i]>maxi)
            {
                maxi = dp[i];
                last = i;
            }
        }
        
        vector<int> ans;
        int id = last;
        int next = par[id];
        ans.push_back(v[id]);
        while(par[id]!=id)
        {
            id = next;
            next = par[next];
            ans.push_back(v[id]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};