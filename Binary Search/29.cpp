// Find a Peak Element in a 2D Grid 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force (Check All 4 Directions)
Time: O(m * n)
Space: O(1)
*/
class SolutionBrute {
public:
    bool isValid(int r, int c, int m, int n) {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    vector<int> findPeakGrid(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool peak = true;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (isValid(ni, nj, m, n) && v[ni][nj] > v[i][j]) {
                        peak = false;
                        break;
                    }
                }
                if (peak) return {i, j};
            }
        }
        return {-1, -1};
    }
};

/*
Approach 2: Global Maximum (Observation-Based)
Time: O(m * n)
Space: O(1)

Note:
Global maximum is always a peak since all neighbors are smaller.
*/
class SolutionMax {
public:
    vector<int> findPeakGrid(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        int mx = INT_MIN, r = -1, c = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] > mx) {
                    mx = v[i][j];
                    r = i;
                    c = j;
                }
            }
        }
        return {r, c};
    }
};

/*
Approach 3: Binary Search on Columns (Optimal)
Time: O(m * log n)
Space: O(1)

Idea:
- Pick middle column
- Find max element in that column
- Compare with left and right neighbors
*/
class SolutionBinary {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int maxRow = 0;
            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            bool leftGreater = (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]);
            bool rightGreater = (mid < n - 1 && mat[maxRow][mid + 1] > mat[maxRow][mid]);

            if (!leftGreater && !rightGreater) {
                return {maxRow, mid};
            } else if (leftGreater) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return {-1, -1};
    }
};