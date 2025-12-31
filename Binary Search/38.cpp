// Find Minimum in Rotated Sorted Array (With Duplicates)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int minEle = INT_MAX;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Case 1: duplicates at boundaries → shrink range
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                minEle = min(minEle, nums[s]);
                s++;
                e--;
            }
            // Case 2: left half is sorted
            else if (nums[s] <= nums[mid]) {
                minEle = min(minEle, nums[s]);
                s = mid + 1;
            }
            // Case 3: right half is sorted (or pivot lies in left)
            else {
                minEle = min(minEle, nums[mid]);
                e = mid - 1;
            }
        }
        return minEle;
    }
};