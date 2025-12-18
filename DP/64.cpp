// 221. Maximal Square

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

class Memoization {
public:
    int rows, cols;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<char>>& matrix) {
        if (i >= rows || j >= cols) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, matrix);
        int down = solve(i + 1, j, matrix);
        int diag = solve(i + 1, j + 1, matrix);

        if (matrix[i][j] == '1') {
            dp[i][j] = 1 + min({right, down, diag});
        } else {
            dp[i][j] = 0;
        }

        return dp[i][j];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        rows = matrix.size();
        cols = matrix[0].size();
        dp.assign(rows, vector<int>(cols, -1));

        int max_side = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                max_side = max(max_side, solve(i, j, matrix));
            }
        }

        return max_side * max_side;
    }
};

class Tabulation {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int max_side = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }
        
        return max_side * max_side;
    }
};