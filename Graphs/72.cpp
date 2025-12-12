// Number of Closed Islands

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

class Solution {
public:
    int rows, cols;
    
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        // If out of bounds → touches border → NOT a closed island
        if (r < 0 || c < 0 || r >= rows || c >= cols)
            return false;

        // 1 = visited or water, no problem
        if (grid[r][c] == 1)
            return true;

        // Mark visited (convert land to water)
        grid[r][c] = 1;

        // Explore all 4 directions
        bool left  = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        bool up    = dfs(r - 1, c, grid);
        bool down  = dfs(r + 1, c, grid);

        // Island is closed only if all four directions return true
        return left && right && up && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int closedIslands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // Start DFS on each land (0)
                if (grid[r][c] == 0) {
                    if (dfs(r, c, grid))
                        closedIslands++;
                }
            }
        }

        return closedIslands;
    }
};