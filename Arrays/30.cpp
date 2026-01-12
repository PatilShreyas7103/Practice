// Merge Intervals

#include <vector>
#include <algorithm>
using namespace std;

/*
Approach: Sorting + Single Pass
- Sort intervals by start time
- Merge overlapping intervals in one traversal
Time: O(N log N)
Space: O(N)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;

        sort(v.begin(), v.end());

        int s = v[0][0];
        int e = v[0][1];

        for (int i = 1; i < v.size(); i++) {
            int s1 = v[i][0];
            int e1 = v[i][1];

            if (s1 <= e) {
                e = max(e, e1);
            } else {
                ans.push_back({s, e});
                s = s1;
                e = e1;
            }
        }

        ans.push_back({s, e});
        return ans;
    }
};