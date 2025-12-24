// Find First and Last Position of Element in Sorted Array

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int firstIndex = -1;
        int lastIndex = -1;

        for (int index = 0; index < size; index++) {
            if (nums[index] == target) {
                if (firstIndex == -1) {
                    firstIndex = index;
                }
                lastIndex = index;
            } else if (nums[index] > target) {
                break;
            }
        }

        return {firstIndex, lastIndex};
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
public:
    int findFirstOccurrence(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int firstIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                firstIndex = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return firstIndex;
    }

    int findLastOccurrence(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int lastIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                lastIndex = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return lastIndex;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIndex = findFirstOccurrence(nums, target);
        int lastIndex = findLastOccurrence(nums, target);
        return {firstIndex, lastIndex};
    }
};