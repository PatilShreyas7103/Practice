// Diagonal Traversal
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// (Explicit diagonal generation starting from every valid start)
class BruteForce {
public:
    vector<vector<int>> diagonal(vector<vector<int>> &v) {
        vector<vector<int>> ans;
        int m = v.size();
        int n = v[0].size();

        // Diagonals starting from top row
        for (int col = 0; col < n; col++) {
            int i = 0, j = col;
            vector<int> temp;
            while (i < m && j >= 0) {
                temp.push_back(v[i][j]);
                i++;
                j--;
            }
            ans.push_back(temp);
        }

        // Diagonals starting from last column (excluding first row)
        for (int row = 1; row < m; row++) {
            int i = row, j = n - 1;
            vector<int> temp;
            while (i < m && j >= 0) {
                temp.push_back(v[i][j]);
                i++;
                j--;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

// Optimal Approach
// (Same traversal, already optimal: O(m*n))
class Optimal {
public:
    vector<vector<int>> diagonal(vector<vector<int>> &v) {
        vector<vector<int>> ans;
        int m = v.size();
        int n = v[0].size();

        for (int col = 0; col < n; col++) {
            int i = 0, j = col;
            vector<int> temp;
            while (i < m && j >= 0) {
                temp.push_back(v[i][j]);
                i++;
                j--;
            }
            ans.push_back(temp);
        }

        for (int row = 1; row < m; row++) {
            int i = row, j = n - 1;
            vector<int> temp;
            while (i < m && j >= 0) {
                temp.push_back(v[i][j]);
                i++;
                j--;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};