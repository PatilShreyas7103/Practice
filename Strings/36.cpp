// Longest Substring Without Repeating Characters
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force (Your Approach)
// Idea:
// - Fix starting index i
// - Use a set to track unique characters
// - Extend j until a duplicate is found
// - Update maximum length
class BruteForce {
public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            set<char> st;
            for (int j = i; j < n; j++) {
                if (st.find(s[j]) == st.end()) {
                    st.insert(s[j]);
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
// Approach 2: Sliding Window (Optimal & Expected)
// Idea:
// - Use two pointers (l, r)
// - Maintain a map of character frequencies
// - Expand right pointer
// - If duplicate appears, shrink window from left
// - Always keep window with unique characters
class Solution {
public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        vector<int> freq(256, 0);

        int l = 0, ans = 0;

        for (int r = 0; r < n; r++) {
            freq[s[r]]++;

            while (freq[s[r]] > 1) {
                freq[s[l]]--;
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