// Find Minimum in Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    int findMin(vector<int>& nums) {
        int minimumValue = INT_MAX;
        for (int value : nums) {
            minimumValue = min(minimumValue, value);
        }
        return minimumValue;
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minimumValue = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If the current segment is already sorted
            if (nums[left] <= nums[right]) {
                minimumValue = min(minimumValue, nums[left]);
                break;
            }

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                minimumValue = min(minimumValue, nums[left]);
                left = mid + 1;
            }
            // Right half is sorted
            else {
                minimumValue = min(minimumValue, nums[mid]);
                right = mid - 1;
            }
        }

        return minimumValue;
    }
};