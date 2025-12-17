// Burst Balloons
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
    int solve(int i, int j, vector<int> &v, vector<vector<int>> &dp)
    {
        if(i>j)
        {
            return dp[i][j] =  0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans = INT_MIN;
        for(int k=i; k<=j; k++)
        {
            int cut = v[i-1]*v[k]*v[j+1] + solve(i,k-1,v,dp) + solve(k+1,j,v,dp);
            ans=max(ans, cut);
        }

        return dp[i][j] =  ans;
    }
    int maxCoins(vector<int>& v) {
        // int n = v.size();
        v.push_back(1);
        v.insert(v.begin(), 1);
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));

        return solve(1,n-2,v,dp);
    }
};

class Solution {
public:

    int maxCoins(vector<int>& v) {
        v.push_back(1);
        v.insert(v.begin(), 1);
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (n,0));

        for(int i=n-2; i>=1; i--)
        {
            for(int j=i; j<=n-2; j++)
            {
                int ans = INT_MIN;
                for(int k=i; k<=j; k++)
                {
                    int cut = v[i-1]*v[k]*v[j+1] + dp[i][k-1] + dp[k+1][j];
                    ans=max(ans, cut);
                }
                dp[i][j] = ans;
            }
        }

        return dp[1][n-2];
    }
};