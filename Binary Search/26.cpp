// Row with Maximum Number of 1s 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n * m)
Space: O(1)
*/
class SolutionBrute {
public:
    int rowWithMax1s(vector<vector<int>>& matrix, int n, int m) {
        int maxOnes = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                cnt += matrix[i][j];
            }
            if (cnt > maxOnes) {
                maxOnes = cnt;
                index = i;
            }
        }
        return index;
    }
};

/*
Approach 2: Binary Search (Optimized)
Each row is sorted (0s followed by 1s)
Time: O(n log m)
Space: O(1)
*/
class SolutionBinary {
public:
    int rowWithMax1s(vector<vector<int>>& matrix, int n, int m) {
        int maxOnes = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int l = 0, r = m - 1;
            int firstOne = m;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (matrix[i][mid] == 1) {
                    firstOne = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            int ones = m - firstOne;
            if (ones > maxOnes) {
                maxOnes = ones;
                index = i;
            }
        }
        return index;
    }
};