// Find K-th Rotation in a Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    int findKRotation(vector<int>& nums) {
        int size = nums.size();
        for (int index = 0; index < size - 1; index++) {
            if (nums[index] > nums[index + 1]) {
                return index + 1;
            }
        }
        return 0;
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
public:
    int findKRotation(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};