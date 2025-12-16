// Largest Divisible Subset
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), parent(n);
        int lastIndex = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;
        int i = lastIndex;
        while (parent[i] != i) {
            ans.push_back(nums[i]);
            i = parent[i];
        }
        ans.push_back(nums[i]);

        return ans;
    }
};