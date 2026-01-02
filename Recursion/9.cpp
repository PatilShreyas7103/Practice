// Count Subsequences with Target Sum 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(int ind, int sum, vector<int> &nums) {
        // Base case when we reach index 0
        if (ind == 0) {
            if (sum == 0 && nums[0] == 0) return 2; // pick or not pick zero
            if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }

        if (sum < 0) return 0;

        // Exclude current element
        int notPick = func(ind - 1, sum, nums);

        // Include current element
        int pick = func(ind - 1, sum - nums[ind], nums);

        return pick + notPick;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int target) {
        int n = nums.size();
        return func(n - 1, target, nums);
    }
};