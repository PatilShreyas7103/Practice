// 1547. Minimum Cost to Cut a Stick

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
        if(i>j)
        {
            return dp[i][j] = 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=i; k<=j; k++)
        {
            int g = v[j+1] - v[i-1] + solve(i,k-1,v,dp) + solve(k+1,j,v,dp);
            ans=min(ans,g);
        }

        return dp[i][j] =  ans;
    }
    int minCost(int n, vector<int>& v) {
        v.push_back(n);
        v.insert(v.begin(), 0);
        sort(v.begin(), v.end());
        int sz = v.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return solve(1,sz-2,v,dp);
    }
};

class Tabulation {
public:
    int minCost(int n, vector<int>& v) {
        v.push_back(n);
        v.insert(v.begin(), 0);
        sort(v.begin(), v.end());
        int m = v.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = m - 2; i >= 1; i--) {
            for (int j = i; j <= m - 2; j++) {
                int ans = INT_MAX;
                for (int k = i; k <= j; k++) {
                    int cost = v[j + 1] - v[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    ans = min(ans, cost);
                }
                dp[i][j] = ans;
            }
        }

        return dp[1][m - 2];
    }
};
