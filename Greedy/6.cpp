// Non-overlapping Intervals

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Sort intervals by end time.
- Greedily keep the interval with the smallest end.
- If current interval overlaps, remove it (count++).
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n = v.size();
        vector<pair<int,int>> intervals;

        for (auto it : v) {
            intervals.push_back({it[1], it[0]}); // {end, start}
        }

        sort(intervals.begin(), intervals.end());

        int lastEnd = INT_MIN;
        int removed = 0;

        for (auto it : intervals) {
            int start = it.second;
            int end = it.first;

            if (start >= lastEnd) {
                lastEnd = end;
            } else {
                removed++;
            }
        }

        return removed;
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/