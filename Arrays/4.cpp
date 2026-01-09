// REMOVE DUPLICATES FROM SORTED ARRAY

#include <bits/stdc++.h>
using namespace std;

// === UNORDERED_SET APPROACH ===
// Time: O(n), Space: O(n)
// Works for unsorted arrays, stores seen elements

class SolutionUnorderedSet {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        int index = 0;
        
        for (int num : nums) {
            if (seen.find(num) == seen.end()) {
                seen.insert(num);
                nums[index++] = num;
            }
        }
        return index;
    }
};

// === TWO POINTERS APPROACH ===
// Time: O(n), Space: O(1)
// Assumes sorted input, optimal for LeetCode #26

class SolutionTwoPointers {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int uniqueIndex = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[uniqueIndex++] = nums[i];
            }
        }
        return uniqueIndex;
    }
};
