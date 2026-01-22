// Minimum Size Subarray Sum
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Fix starting index i
// - Keep adding elements until sum >= target
// - Track minimum length and break for that i
class BruteForce {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int n = v.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += v[j];
                if (sum >= target) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 2: Sliding Window (Optimal & Expected)
// Idea:
// - Use two pointers (l, r)
// - Expand r to increase sum
// - While sum >= target, shrink from left to minimize length
// - Works because all elements are positive
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int n = v.size();
        int l = 0, sum = 0, ans = INT_MAX;

        for (int r = 0; r < n; r++) {
            sum += v[r];

            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= v[l];
                l++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/