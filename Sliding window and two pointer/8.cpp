// Longest Substring with At Most K Distinct Characters
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Fix starting index i
// - Use a set to track distinct characters
// - Extend j until distinct characters exceed k
// - Track maximum valid length
int bruteForce(int k, string &s) {
    int n = s.size();
    int ans = -1;

    for (int i = 0; i < n; i++) {
        unordered_set<char> st;
        for (int j = i; j < n; j++) {
            st.insert(s[j]);
            if (st.size() > k)
                break;
            ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(k)
*/

/*------------------------------------------------------*/
// Approach 2: Sliding Window (Optimal & Expected)
// Idea:
// - Use two pointers (l, r)
// - Maintain frequency map of characters
// - Expand r to include characters
// - Shrink window from left if distinct count > k
// - Track maximum window size
int kDistinctChars(int k, string &s) {
    int n = s.length();
    unordered_map<char, int> mp;
    int l = 0, ans = 0;

    for (int r = 0; r < n; r++) {
        mp[s[r]]++;

        while (mp.size() > k) {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans > 0 ? ans : -1;
}

/*
Time Complexity: O(n)
Space Complexity: O(k)
*/