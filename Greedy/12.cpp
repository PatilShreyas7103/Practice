// Maximum Sum Circular Subarray

#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
/*
Approach 1 (Optimal – Kadane’s Algorithm):
- Normal max subarray using Kadane.
- Circular max = totalSum − minimum subarray sum.
- Answer is max of both (handle all-negative case).
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curMax = 0, curMin = 0;
        int globMax = nums[0], globMin = nums[0];

        for (int x : nums) {
            curMax = max(curMax + x, x);
            curMin = min(curMin + x, x);

            globMax = max(globMax, curMax);
            globMin = min(globMin, curMin);

            total += x;
        }

        // If all numbers are negative, circular sum is invalid
        return globMax > 0 ? max(globMax, total - globMin) : globMax;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
/*
Approach 2 (Prefix + Suffix):
- Precompute maximum suffix sums.
- Use Kadane for prefix max.
- Combine prefix + suffix to handle circular case.
*/

class PrefixSuffix {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);

        int suffixSum = nums[n - 1];
        rightMax[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixSum += nums[i];
            rightMax[i] = max(rightMax[i + 1], suffixSum);
        }

        int curMax = 0, prefixSum = 0;
        int ans = nums[0];

        for (int i = 0; i < n; i++) {
            curMax = max(curMax, 0) + nums[i];
            ans = max(ans, curMax);

            prefixSum += nums[i];
            if (i + 1 < n) {
                ans = max(ans, prefixSum + rightMax[i + 1]);
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/