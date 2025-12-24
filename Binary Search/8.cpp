// Count Frequency of an Element in a Sorted Array

#include <bits/stdc++.h>
using namespace std;

/* ===================== HASH MAP APPROACH ===================== */
class HashMapApproach {
public:
    int countFreq(vector<int>& nums, int target) {
        unordered_map<int, int> frequencyMap;
        for (int value : nums) {
            frequencyMap[value]++;
        }
        return frequencyMap[target];
    }
};

/* ===================== LINEAR SCAN APPROACH ===================== */
class LinearScanApproach {
public:
    int countFreq(vector<int>& nums, int target) {
        int count = 0;
        for (int value : nums) {
            if (value == target) {
                count++;
            }
        }
        return count;
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
private:
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

public:
    int countFreq(vector<int>& nums, int target) {
        int firstIndex = findFirstOccurrence(nums, target);
        if (firstIndex == -1) {
            return 0;
        }

        int lastIndex = findLastOccurrence(nums, target);
        return lastIndex - firstIndex + 1;
    }
};