// Upper Bound in a Sorted Array

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    int upperBound(vector<int>& nums, int target) {
        int size = nums.size();
        for (int index = 0; index < size; index++) {
            if (nums[index] > target) {
                return index;
            }
        }
        return size;
    }
};

/* ===================== STL UPPER_BOUND APPROACH ===================== */
class STLApproach {
public:
    int upperBound(vector<int>& nums, int target) {
        return upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
public:
    int upperBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int answerIndex = nums.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > target) {
                answerIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answerIndex;
    }
};