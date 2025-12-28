// Find Peak Element

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();

        if (size == 1) {
            return 0;
        }

        for (int index = 0; index < size; index++) {
            if (index == 0) {
                if (nums[index] > nums[index + 1]) {
                    return index;
                }
            } 
            else if (index == size - 1) {
                if (nums[index] > nums[index - 1]) {
                    return index;
                }
            } 
            else {
                if (nums[index] > nums[index - 1] &&
                    nums[index] > nums[index + 1]) {
                    return index;
                }
            }
        }

        return 0;
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};