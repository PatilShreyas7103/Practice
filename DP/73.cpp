// Last Stone Weight II

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
private:
    vector<vector<int>> dp;

    int dfs(int i, int total, const vector<int>& stones, int stoneSum, int target) {
        if (total >= target || i == stones.size()) {
            return abs(total - (stoneSum - total));
        }
        if (dp[i][total] != -1) {
            return dp[i][total];
        }

        dp[i][total] = min(
            dfs(i + 1, total, stones, stoneSum, target),
            dfs(i + 1, total + stones[i], stones, stoneSum, target)
        );
        return dp[i][total];
    }
    
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = (stoneSum + 1) / 2;
        dp = vector<vector<int>>(stones.size(), vector<int>(target + 1, -1));
        return dfs(0, 0, stones, stoneSum, target);
    }
};

class Tabulation {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int w : stones) {
            for (int j = target; j >= w; j--) {
                dp[j] = dp[j] || dp[j - w];
            }
        }

        for (int j = target; j >= 0; j--) {
            if (dp[j]) {
                return sum - 2 * j;
            }
        }
        return 0;
    }
};