// Find Ceil of an Element in a Sorted Array

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    int findCeil(vector<int>& nums, int target) {
        int size = nums.size();

        for (int index = 0; index < size; index++) {
            if (nums[index] >= target) {
                return index;
            }
        }

        return -1;
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
public:
    int findCeil(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ceilIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {
                ceilIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ceilIndex;
    }
};