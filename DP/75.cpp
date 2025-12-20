// 329. Longest Increasing Path in a Matrix

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
    bool isValid(int r, int c, int m, int n)
    {
        return (r>=0 && c>=0 && r<m && c<n);
    }
    int solve(int r, int c, vector<vector<int>> &v,
    int m, int n, int dx[], int dy[], int prev, vector<vector<int>> &dp)
    {
        if(!isValid(r,c,m,n) || v[r][c]<=prev)
        {
            return 0;
        }

        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }

        int len = 0;
        for(int i=0; i<4; i++)
        {
            int nr = r+dx[i];
            int nc = c+dy[i];

            len=max(len, solve(nr,nc,v,m,n,dx,dy,v[r][c],dp));
        }

        return dp[r][c] = len+1;
    }


    int longestIncreasingPath(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        int ans =0; 
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        vector<vector<int>> dp(m, vector<int> (n,-1));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans=max(ans, solve(i,j,v,m,n,dx,dy,INT_MIN,dp));
            }
        }

        return ans;
    }
};