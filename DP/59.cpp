// Maximum Profit in Job Scheduling

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
    int solve(int i, vector<vector<int>>& jobs, vector<int>& dp) {
        if (i >= jobs.size()) return 0;
        if (dp[i] != -1) return dp[i];

        // option 1: skip job
        int dont = solve(i + 1, jobs, dp);

        // option 2: take job
        int take = jobs[i][2];
        int lo = i + 1, hi = jobs.size() - 1, next = jobs.size();

        // binary search next compatible job
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (jobs[mid][0] >= jobs[i][1]) {
                next = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        take += solve(next, jobs, dp);

        return dp[i] = max(take, dont);
    }

    int jobScheduling(vector<int>& a, vector<int>& b, vector<int>& p) {
        int n = a.size();

        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({a[i], b[i], p[i]});
        }

        sort(jobs.begin(), jobs.end()); // sort by start time

        vector<int> dp(n, -1);
        return solve(0, jobs, dp);
    }
};


class Tabulation {
public:
    int jobScheduling(vector<int>& a, vector<int>& b, vector<int>& p) {
        int n = a.size();

        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({a[i], b[i], p[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n + 1, 0); // dp[n] = 0

        for (int i = n - 1; i >= 0; i--) {

            // find next compatible job
            int lo = i + 1, hi = n - 1, next = n;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (jobs[mid][0] >= jobs[i][1]) {
                    next = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            int take = jobs[i][2] + dp[next];
            int dont = dp[i + 1];

            dp[i] = max(take, dont);
        }

        return dp[0];
    }
};