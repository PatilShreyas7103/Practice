// Find the Largest Element in an Array

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Linear Scan
Time: O(n)
Space: O(1)

Idea:
- Traverse the array once.
- Keep updating the maximum element.
- Most optimal approach.
*/
class SolutionLinear {
public:
    int largest(vector<int>& arr) {
        int mx = INT_MIN;
        for (auto it : arr) {
            mx = max(mx, it);
        }
        return mx;
    }
};

/*
Approach 2: Sorting
Time: O(n log n)
Space: O(1) (ignoring sorting space)

Idea:
- Sort the array.
- The last element after sorting is the largest.
- Not optimal but sometimes acceptable.
*/
class SolutionSort {
public:
    int largest(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        return arr[arr.size() - 1];
    }
};