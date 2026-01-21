// Count Number of Nice Subarrays
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Fix starting index i
// - Count odd numbers while extending j
// - If odd count == k, increment answer
// - Break when odd count > k
class BruteForce {
public:
    int numberOfSubarrays(vector<int>& v, int k) {
        int n = v.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (v[j] & 1) cnt++;
                if (cnt == k) ans++;
                else if (cnt > k) break;
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
// Approach 2: Sliding Window using AtMost Trick
// Idea:
// - Count subarrays with at most k odd numbers
// - Count subarrays with at most (k-1) odd numbers
// - Exactly k odds = atMost(k) - atMost(k-1)
// Works because odd count is non-decreasing in window
class SlidingWindow {
public:
    int atMost(vector<int>& v, int k) {
        if (k < 0) return 0;

        int l = 0, cnt = 0, ans = 0;

        for (int r = 0; r < v.size(); r++) {
            if (v[r] & 1) cnt++;

            while (cnt > k) {
                if (v[l] & 1) cnt--;
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& v, int k) {
        return atMost(v, k) - atMost(v, k - 1);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 3: Prefix Sum + Hash Map (Most General & Safe)
// Idea:
// - Convert array into odd-count prefix sum
// - For each prefix sum `odds`
// - Count how many times (odds - k) appeared before
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int odds = 0, ans = 0;

        for (int x : nums) {
            if (x & 1) odds++;

            if (mp.count(odds - k))
                ans += mp[odds - k];

            mp[odds]++;
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
