// Fruit Into Baskets
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Fix starting index i
// - Extend j to the right
// - Use a set to track distinct fruit types
// - Stop when more than 2 types are encountered
// - Track maximum length
class BruteForce {
public:
    int totalFruit(vector<int>& v) {
        int n = v.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(v[j]);
                if (st.size() > 2)
                    break;
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(1) (set holds at most 3 elements)
*/

/*------------------------------------------------------*/
// Approach 2: Sliding Window (Optimal & Expected)
// Idea:
// - Use two pointers l and r
// - Maintain frequency map of fruit types
// - Expand r to include fruits
// - If types exceed 2, shrink window from left
// - Track maximum valid window length
class Solution {
public:
    int totalFruit(vector<int>& v) {
        int n = v.size();
        int l = 0, ans = 0;
        unordered_map<int, int> mp;

        for (int r = 0; r < n; r++) {
            mp[v[r]]++;

            while (mp.size() > 2) {
                mp[v[l]]--;
                if (mp[v[l]] == 0)
                    mp.erase(v[l]);
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1) (at most 2 fruit types stored)
*/