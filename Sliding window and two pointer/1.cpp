// Max Consecutive Ones III
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Fix a starting index i
// - Extend j to the right
// - Count how many zeros are in the window
// - If zeros > k, stop expanding
// - Track maximum window length
class BruteForce {
public:
    int longestOnes(vector<int>& v, int k) {
        int n = v.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = i; j < n; j++) {
                if (v[j] == 0) {
                    zeros++;
                    if (zeros > k) break;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
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
// - Expand r and count zeros
// - If zeros > k, shrink from left
// - Always maintain a valid window
// - Track maximum length
class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n = v.size();
        int l = 0, zeros = 0, ans = 0;

        for (int r = 0; r < n; r++) {
            if (v[r] == 0) zeros++;

            while (zeros > k) {
                if (v[l] == 0) zeros--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/