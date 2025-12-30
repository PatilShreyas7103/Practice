// Search a 2D Matrix 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(m * n)
Space: O(1)
*/
class SolutionBrute {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int m = v.size(), n = v[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == t) return true;
            }
        }
        return false;
    }
};

/*
Approach 2: Binary Search on Rows + Binary Search in Row
Time: O(log m + log n)
Space: O(1)
*/
class SolutionRowBinary {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int m = v.size(), n = v[0].size();
        int low = 0, high = m - 1;
        int row = -1;

        // Step 1: Find the possible row
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (t >= v[mid][0] && t <= v[mid][n - 1]) {
                row = mid;
                break;
            } else if (t < v[mid][0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (row == -1) return false;

        // Step 2: Binary search in that row
        int s = 0, e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (v[row][mid] == t) return true;
            else if (v[row][mid] < t) s = mid + 1;
            else e = mid - 1;
        }
        return false;
    }
};

/*
Approach 3: Binary Search on Virtual 1D Array (Optimal)
Time: O(log (m * n))
Space: O(1)
*/
class SolutionBinary {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int m = v.size(), n = v[0].size();
        int s = 0, e = m * n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int row = mid / n;
            int col = mid % n;
            int val = v[row][col];

            if (val == t) return true;
            else if (val < t) s = mid + 1;
            else e = mid - 1;
        }
        return false;
    }
};


/*
Approach 4: Staircase Search
Matrix properties:
- Rows are sorted
- Columns are sorted

Start from top-right corner:
- If current > target → move left
- If current < target → move down

Time: O(m + n)
Space: O(1)
*/
class SolutionStaircase {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int m = v.size();
        int n = v[0].size();

        int i = 0;
        int j = n - 1;

        while (i < m && j >= 0) {
            if (v[i][j] == t) {
                return true;
            } else if (v[i][j] > t) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};