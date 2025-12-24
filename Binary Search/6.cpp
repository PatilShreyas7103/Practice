// Find Floor of an Element in a Sorted Array

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    int findFloor(vector<int>& nums, int target) {
        int floorIndex = -1;
        int size = nums.size();

        for (int index = 0; index < size; index++) {
            if (nums[index] <= target) {
                floorIndex = index;
            } else {
                break;
            }
        }

        return floorIndex;
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
public:
    int findFloor(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int floorIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                floorIndex = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return floorIndex;
    }
};