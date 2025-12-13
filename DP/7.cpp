// Ninja Training 
#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class NinjaTrainingMemoization {
public:
    int solve(int day, int lastTask,
              vector<vector<int>> &points,
              vector<vector<int>> &dp) {
        if (day == 0) {
            int best = 0;
            for (int task = 0; task < 3; task++) {
                if (task != lastTask)
                    best = max(best, points[0][task]);
            }
            return dp[0][lastTask] = best;
        }

        if (dp[day][lastTask] != -1)
            return dp[day][lastTask];

        int best = 0;
        for (int task = 0; task < 3; task++) {
            if (task != lastTask) {
                int curr = points[day][task]
                           + solve(day - 1, task, points, dp);
                best = max(best, curr);
            }
        }

        return dp[day][lastTask] = best;
    }

    int maximumPoints(vector<vector<int>> &points) {
        int n = points.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(n - 1, 3, points, dp);
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class NinjaTrainingTabulation {
public:
    int maximumPoints(vector<vector<int>>& v) {
        // Code here
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (4,0));
  
        dp[0][0] = max(v[0][1], v[0][2]);
        dp[0][1] = max(v[0][0], v[0][2]);
        dp[0][2] = max(v[0][1], v[0][0]);
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=2; j++)
            {
                int ans = 0;
                for(int k=0; k<=2; k++)
                {
                    if(k!=j)
                    {
                        int res = v[i][k] + dp[i-1][k];
                        ans=max(ans, res);
                    }
                }
                dp[i][j] = ans;
            }
        }
        
        int ans = 0;
        for(int i=0; i<=2; i++)
        {
            ans=max(ans, dp[n-1][i]);
        }
        
        return ans;
    }
};

/* -------------------- Space Optimized DP -------------------- */
class NinjaTrainingSpaceOptimized {
public:
    int maximumPoints(vector<vector<int>> &points) {
        int n = points.size();
        vector<int> prev(4, 0), curr(4, 0);

        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max({points[0][0], points[0][1], points[0][2]});

        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                curr[last] = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        int currPoints = points[day][task] + prev[task];
                        curr[last] = max(curr[last], currPoints);
                    }
                }
            }
            prev = curr;
        }

        return prev[3];
    }
};