// Combination sum IV

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
    int solve(int t, vector<int> &v, vector<int> &dp)
    {
        if(t==0)
        {
            return dp[0] = 1;
        }

        if(dp[t]!=-1)
        {
            return dp[t];
        }

        int k = 0;
        for (int num : v) {
            if (t>=num) {
                k += solve(t-num,v,dp);
            }
        }

        return dp[t] = k;
    }
    int combinationSum4(vector<int>& v, int t) {
        vector<int> dp(t + 1, -1);
        
        return solve(t,v,dp);
    }
};

class Tabulation {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i>=num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};