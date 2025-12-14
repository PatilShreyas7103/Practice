// Partitions with Given Difference

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
    int solve(int index, int target,
              vector<int> &nums,
              vector<vector<int>> &dp) {

        if (index == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;   // {} and {0}
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        if (dp[index][target] != -1)
            return dp[index][target];

        int notTake = solve(index - 1, target, nums, dp);
        int take = 0;

        if (nums[index] <= target)
            take = solve(index - 1, target - nums[index], nums, dp);

        return dp[index][target] = take + notTake;
    }
    int countPartitions(vector<int>& v, int d) {
        // Code v
        int n = v.size();
        int sum = 0;
        
        for(auto it: v)
        {
            sum+=it;
        }
        
        if((sum+d)%2)
        {
            return 0;
        }
        
        int t = (sum+d)/2;
        vector<vector<int>> dp(n, vector<int>(t + 1, -1));
        return solve(n - 1, t, v, dp);
    }
};

class Tabulation {
  public:
    int countPartitions(vector<int>& v, int d) {
        // Code v
        int n = v.size();
        int sum = 0;
        
        for(auto it: v)
        {
            sum+=it;
        }
        
        if((sum+d)%2)
        {
            return 0;
        }
        
        int t = (sum+d)/2;
        vector<vector<int>> dp(n, vector<int> (t+1,0));
        
        for(int i=0; i<n; i++)
        {
            dp[i][0] = 1;
        }
        if(v[0]<=t)
        {
            dp[0][v[0]] += 1;
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=t; j++)
            {
                int dont = dp[i-1][j];
                int take = 0;
                if(j-v[i]>=0)
                {
                    take = dp[i-1][j-v[i]];
                }
                dp[i][j] = take + dont;
            }
        }
        
        return dp[n-1][t];
    }
};