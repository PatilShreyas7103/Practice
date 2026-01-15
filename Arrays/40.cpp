// Jump Game II (Minimum Number of Jumps)

#include <vector>
#include <climits>
using namespace std;

/*
Approach 1: Memoization (Top-Down DP)
- From index i, try all reachable positions
- Store minimum jumps needed from each index
Time: O(N^2)
Space: O(N)
*/
class SolutionMemo {
public:
    int solve(int i, vector<int>& v, vector<int>& dp) {
        int n = v.size();
        if (i >= n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;
        for (int j = i + 1; j <= min(n - 1, i + v[i]); j++) {
            ans = min(ans, 1 + solve(j, v, dp));
        }

        return dp[i] = ans;
    }

    int jump(vector<int>& v) {
        vector<int> dp(v.size(), -1);
        return solve(0, v, dp);
    }
};

/*
Approach 2: Tabulation (Bottom-Up DP)
- dp[i] = minimum jumps needed to reach end from i
- Build solution from back to front
Time: O(N^2)
Space: O(N)
*/
class SolutionTabulation {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j <= min(n - 1, i + v[i]); j++) {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }

        return dp[0];
    }
};

/*
Approach 3: Greedy (Optimal & Most Expected)
- Maintain current reachable range and farthest reach
- Increase jump count when current range ends
Time: O(N)
Space: O(1)
*/
class SolutionGreedy {
public:
    int jump(vector<int>& v) {
        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        for (int i = 0; i < v.size() - 1; i++) {
            farthest = max(farthest, i + v[i]);

            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};