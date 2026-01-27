// Assign cookies
#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Sort greed factors and cookie sizes.
- Use two pointers to greedily assign the smallest
  sufficient cookie to the least greedy child.
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, cnt = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                cnt++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return cnt;
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/