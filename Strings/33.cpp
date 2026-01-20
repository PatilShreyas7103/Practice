// Longest Substring with Exactly K Distinct Characters
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Generate all substrings
// - Count distinct characters using a set
// - Update answer when distinct count == k
class BruteForce {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = i; j < n; j++) {
                st.insert(s[j]);
                if (st.size() == k) {
                    ans = max(ans, j - i + 1);
                } else if (st.size() > k) {
                    break;
                }
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n²)
Space Complexity: O(k)
*/

/*------------------------------------------------------*/
// Approach 2: Optimal Sliding Window (Two Pointers)
// Idea:
// - Use two pointers l and r
// - Expand right pointer and include characters
// - Shrink from left when distinct characters > k
// - Track maximum window size when distinct == k
class Optimal {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int l = 0, ans = -1;

        for (int r = 0; r < n; r++) {
            mp[s[r]]++;

            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }

            if (mp.size() == k) {
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(k)
*/