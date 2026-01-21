// Binary Subarrays With Sum
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Fix starting index i
// - Keep adding elements till sum exceeds goal
// - Count whenever sum == goal
// Works because array contains only 0s and 1s
class BruteForce {
public:
    int numSubarraysWithSum(vector<int>& v, int goal) {
        int n = v.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += v[j];
                if (sum == goal) ans++;
                else if (sum > goal) break;
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
// Approach 2: Sliding Window using AtMost Trick (Optimal for Binary Arrays)
// Idea:
// - Number of subarrays with sum == goal
//   = subarrays with sum ≤ goal
//   - subarrays with sum ≤ goal-1
// - Sliding window works because all values are non-negative (0 or 1)
class SlidingWindow {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int left = 0, sum = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left++];
            }

            count += right - left + 1;
        }
        return count;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 3: Prefix Sum + Hash Map (Most General & Safest)
// Idea:
// - Maintain running prefix sum
// - If (prefixSum - goal) appeared before,
//   then a valid subarray exists
// - Works for ANY integers (not just binary)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& v, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, ans = 0;

        for (int x : v) {
            sum += x;
            if (mp.count(sum - goal)) {
                ans += mp[sum - goal];
            }
            mp[sum]++;
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/