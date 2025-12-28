// Single Element in a Sorted Array

#include <bits/stdc++.h>
using namespace std;

/* ===================== HASH MAP APPROACH ===================== */
class HashMapApproach {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        for (int value : nums) {
            frequencyMap[value]++;
        }

        for (auto& entry : frequencyMap) {
            if (entry.second == 1) {
                return entry.first;
            }
        }

        return -1;
    }
};

/* ===================== XOR APPROACH ===================== */
class XorApproach {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorResult = 0;
        for (int value : nums) {
            xorResult ^= value;
        }
        return xorResult;
    }
};

/* ===================== LINEAR NEIGHBOR CHECK APPROACH ===================== */
class LinearScanApproach {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();

        if (size == 1) {
            return nums[0];
        }

        for (int index = 0; index < size; index++) {
            if (index == 0 && nums[index] != nums[index + 1]) {
                return nums[index];
            }
            if (index == size - 1 && nums[index] != nums[index - 1]) {
                return nums[index];
            }
            if (index > 0 && index < size - 1 &&
                nums[index] != nums[index - 1] &&
                nums[index] != nums[index + 1]) {
                return nums[index];
            }
        }

        return -1;
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mid % 2 == 1) {
                mid--;
            }

            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};