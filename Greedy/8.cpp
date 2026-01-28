// Job Sequencing Problem

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Pair jobs as (profit, deadline).
- Sort jobs by profit in descending order.
- For each job, schedule it at the latest free slot
  before its deadline.
*/

class Solution {
public:
    vector<int> jobSequencing(vector<int> &d, vector<int> &p) {
        int n = d.size();
        vector<pair<int,int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({p[i], d[i]});
        }

        sort(jobs.rbegin(), jobs.rend()); // sort by profit

        vector<int> slot(n, 0);
        int cnt = 0, profit = 0;

        for (auto it : jobs) {
            int jobProfit = it.first;
            int deadline = it.second;

            for (int j = deadline - 1; j >= 0; j--) {
                if (slot[j] == 0) {
                    slot[j] = 1;
                    cnt++;
                    profit += jobProfit;
                    break;
                }
            }
        }

        return {cnt, profit};
    }
};

/*
Time Complexity: O(n log n + n^2)
Space Complexity: O(n)
*/