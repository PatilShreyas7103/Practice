// Search in Rotated Sorted Array II (Duplicates Allowed)

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        for (int index = 0; index < size; index++) {
            if (nums[index] == target) {
                return true;
            }
        }
        return false;
    }
};

/* ===================== BINARY SEARCH APPROACH (WITH DUPLICATES) ===================== */
class BinarySearchApproach {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return false;

        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Handle duplicates: shrink bounds
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};