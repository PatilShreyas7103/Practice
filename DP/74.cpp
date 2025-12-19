// Stone Game

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
    int solve(int l, int r, vector<int> &v,int sum,
    vector<vector<int>> &dp)
    {
        if(l>r)
        {
            return 0;
        }

        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }

        int even = (r-l)%2==0;
        int left = even ? v[l] : 0;
        int right = even ? v[r] : 0;

        return dp[l][r] = max(left+solve(l+1,r,v,sum,dp), right+solve(l,r-1,v,sum,dp));
    }
    bool stoneGame(vector<int>& v) {
        int n = v.size();
        int sum = accumulate(v.begin(),v.end(),0);
        vector<vector<int>> dp(n, vector<int> (n,-1));
        int alice = solve(0,n-1,v,sum,dp);
        return alice > (sum-alice);
    }
};

class Tabulation {
public:
    bool stoneGame(vector<int>& v) {
        int n = v.size();
        int sum = accumulate(v.begin(), v.end(), 0);

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length = 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = v[i];  // Alice takes the only stone
        }

        // lengths from 2 to n
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                bool even = ((r - l) % 2 == 0);

                int left  = even ? v[l] : 0;
                int right = even ? v[r] : 0;

                dp[l][r] = max(
                    left  + dp[l + 1][r],
                    right + dp[l][r - 1]
                );
            }
        }

        int alice = dp[0][n - 1];
        return alice > (sum - alice);
    }
};