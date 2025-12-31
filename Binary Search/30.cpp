// Median of a Row-wise Sorted Matrix 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force (Flatten + Sort)
Time: O((m*n) log (m*n))
Space: O(m*n)
*/
class SolutionBrute {
public:
    int median(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        vector<int> arr;

        for (auto& row : v) {
            for (int x : row) {
                arr.push_back(x);
            }
        }

        sort(arr.begin(), arr.end());
        return arr[(m * n) / 2];
    }
};

/*
Approach 2: Binary Search on Value Range (Optimal)
Matrix property:
- Each row is sorted

Time: O(m * log(maxVal - minVal))
Space: O(1)
*/
class SolutionBinary {
public:
    int countLessEqual(vector<int>& row, int mid) {
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }

    int median(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[0][cols - 1];

        for (int i = 1; i < rows; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][cols - 1]);
        }

        int req = (rows * cols + 1) / 2;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;

            for (int i = 0; i < rows; i++) {
                cnt += countLessEqual(matrix[i], mid);
            }

            if (cnt < req)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};