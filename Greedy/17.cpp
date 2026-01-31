// Minimum Number of Arrows to Burst Balloons

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Sort balloons by end coordinate.
- Shoot an arrow at the end of the first balloon.
- If next balloon starts after the arrow point,
  shoot a new arrow.
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;

        vector<pair<int,int>> balloons;
        for (auto &p : points) {
            balloons.push_back({p[1], p[0]}); // {end, start}
        }

        sort(balloons.begin(), balloons.end());

        int arrows = 1;
        int prevEnd = balloons[0].first;

        for (int i = 1; i < n; i++) {
            if (balloons[i].second > prevEnd) {
                arrows++;
                prevEnd = balloons[i].first;
            }
        }

        return arrows;
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/