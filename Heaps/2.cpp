// Question: Check if the given array is a Min-Heap and Max-Heap (Both in Same Class)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if array is a Min-Heap
    bool isMinHeap(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= (n / 2) - 1; i++) {
            int left = 2 * i + 1;
            if (left < n && nums[i] > nums[left]) return false;

            int right = 2 * i + 2;
            if (right < n && nums[i] > nums[right]) return false;
        }

        return true;
    }

    // Function to check if array is a Max-Heap
    bool isMaxHeap(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= (n / 2) - 1; i++) {
            int left = 2 * i + 1;
            if (left < n && nums[i] < nums[left]) return false;

            int right = 2 * i + 2;
            if (right < n && nums[i] < nums[right]) return false;
        }

        return true;
    }
};