// Longest Subarray of 1's After Deleting One Element
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - For every starting index i
// - Extend j while allowing at most one zero
// - Once more than one zero is encountered, break
// - Length is (j - i) because one element must be deleted
class BruteForce {
public:
    int longestSubarray(vector<int>& v) {
        int n = v.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int zeros = 1;   // allowed to delete one zero
            for (int j = i; j < n; j++) {
                if (v[j] == 0) {
                    zeros--;
                    if (zeros < 0)
                        break;
                }
                ans = max(ans, j - i);
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
// - Maintain a window with at most one zero
// - Use two pointers (l, r)
// - If zeros exceed one, shrink window from left
// - Length is (r - l) since one element must be deleted
class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int n = v.size();
        int l = 0, zeros = 1, ans = 0;

        for (int r = 0; r < n; r++) {
            if (v[r] == 0)
                zeros--;

            while (zeros < 0) {
                if (v[l] == 0)
                    zeros++;
                l++;
            }

            ans = max(ans, r - l);
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/