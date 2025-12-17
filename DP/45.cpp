// Matrix Chain Multiplication

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
    int solve(int i, int j, vector<int> &v, vector<vector<int>> &dp)
    {
        if(i==j)
        {
            return dp[i][j] =  0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int mini = 1e9;
        
        for(int k=i; k<j; k++)
        {
            int step = v[i-1]*v[k]*v[j] + solve(i,k,v,dp) + solve(k+1,j,v,dp);
            mini = min(mini, step);
        }
        
        return dp[i][j] =  mini;
    }
    int matrixMultiplication(vector<int> &v) {
        // code here
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(1,n-1,v,dp);
    }
};


class Tabulation {
  public:   

    int matrixMultiplication(vector<int> &v) {
        // code here
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        
        for(int i= n-1; i>=1; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                int ans = 1e9;
                for(int k=i; k<j; k++)
                {
                    int tot = v[k]*v[i-1]*v[j] + dp[i][k] + dp[k+1][j];
                    ans = min(ans, tot);
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[1][n-1];
    }
};