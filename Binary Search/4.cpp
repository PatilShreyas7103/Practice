// Search Insert Position

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int insertIndex = 0;

        for (int index = 0; index < size; index++) {
            if (nums[index] == target) {
                return index;
            }
            if (nums[index] > target) {
                break;
            }
            insertIndex = index + 1;
        }

        return insertIndex;
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int insertIndex = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                insertIndex = mid + 1;
                left = mid + 1;
            }
        }

        return insertIndex;
    }
};