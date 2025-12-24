// Binary Search (Search in a Sorted Array)

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        for (int index = 0; index < size; index++) {
            if (nums[index] == target) {
                return index;
            }
        }
        return -1;
    }
};

/* ===================== ITERATIVE BINARY SEARCH ===================== */
class IterativeBinarySearch {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

/* ===================== RECURSIVE BINARY SEARCH ===================== */
class RecursiveBinarySearch {
private:
    int binarySearch(int left, int right, vector<int>& nums, int target) {
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return binarySearch(mid + 1, right, nums, target);
        } else {
            return binarySearch(left, mid - 1, nums, target);
        }
    }

public:
    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size() - 1, nums, target);
    }
};