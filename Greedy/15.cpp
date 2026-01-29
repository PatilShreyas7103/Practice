// Transpose Matrix

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Create a new matrix of size (columns × rows).
- Swap indices: element at (i, j) goes to (j, i).
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][i] = v[i][j];
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(m × n)
Space Complexity: O(m × n)
*/