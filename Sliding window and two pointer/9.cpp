// Subarrays with K Different Integers
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Generate all subarrays
// - Use a set to count distinct elements
// - If distinct count == k, increment answer
class BruteForce {
public:
    int subarraysWithKDistinct(vector<int>& v, int k) {
        int n = v.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(v[j]);
                if (st.size() == k) ans++;
                else if (st.size() > k) break;
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(k)
*/

/*------------------------------------------------------*/
// Approach 2: Sliding Window using AtMost Trick (Optimal)
// Idea:
// - Count subarrays with at most k distinct elements
// - Count subarrays with at most (k-1) distinct elements
// - Exactly k distinct = atMost(k) - atMost(k-1)
//
// Why it works:
// - Window with ≤ k distinct is monotonic
// - Sliding window ensures linear time
class Solution {
public:
    int atMost(vector<int>& v, int k) {
        if (k < 0) return 0;

        int l = 0, ans = 0;
        unordered_map<int, int> mp;

        for (int r = 0; r < v.size(); r++) {
            mp[v[r]]++;

            while (mp.size() > k) {
                mp[v[l]]--;
                if (mp[v[l]] == 0)
                    mp.erase(v[l]);
                l++;
            }

            // all subarrays ending at r with start in [l..r] are valid
            ans += r - l + 1;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& v, int k) {
        return atMost(v, k) - atMost(v, k - 1);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(k)
*/