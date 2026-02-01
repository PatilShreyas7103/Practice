// 3Sum Closest

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Sort the array.
- Fix one element and use two pointers for the rest.
- Track the sum closest to the target.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int bestSum = 0;
        int minDiff = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                int diff = abs(sum - target);

                if (diff < minDiff) {
                    minDiff = diff;
                    bestSum = sum;
                }

                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    return target;  // exact match
                }
            }
        }

        return bestSum;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/