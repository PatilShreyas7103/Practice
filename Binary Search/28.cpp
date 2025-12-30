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
Approach 2: Binary Search on Each Row
Condition:
- Each row is sorted
Time: O(m log n)
Space: O(1)
*/
class SolutionRowBinary {
public:
    bool binarySearch(vector<int>& row, int t) {
        int s = 0, e = row.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (row[mid] == t) return true;
            else if (row[mid] < t) s = mid + 1;
            else e = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& v, int t) {
        for (auto& row : v) {
            if (binarySearch(row, t)) return true;
        }
        return false;
    }
};

/*
Approach 3: Staircase Search (Most Common for This Matrix Type)
Condition:
- Rows sorted
- Columns sorted

Start from top-right corner
Time: O(m + n)
Space: O(1)
*/
class SolutionStaircase {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int m = v.size();
        int n = v[0].size();
        int i = 0, j = n - 1;

        while (i < m && j >= 0) {
            if (v[i][j] == t) return true;
            else if (v[i][j] > t) j--;
            else i++;
        }
        return false;
    }
};