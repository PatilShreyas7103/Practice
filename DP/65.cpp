// 1137. N-th Tribonacci Number
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
    int solve(int n, vector<int> &dp)
    {
        if(n==0)
        {
            return dp[n] = 0;
        }
        if(n==1 || n==2)
        {
            return dp[n] = 1;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        return dp[n] = solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

class Tabulation {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1,0);
        if(n==0)
        {
            return 0;
        }
        if(n==1 || n==2)
        {
            return 1;
        }
        dp[1] = 1;
        dp[2] = 1;

        for(int i=3; i<=n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }

        return dp[n];

    }
};