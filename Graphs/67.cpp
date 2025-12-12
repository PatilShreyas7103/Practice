// Find whether path exist

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

    bool isValid(int r, int c, int n) {
        return (r >= 0 && r < n && c >= 0 && c < n);
    }

    bool is_Possible(vector<vector<int>> &grid) {
        int n = grid.size();

        // Find source
        int sr = -1, sc = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                    break;
                }
            }
            if (sr != -1) break;
        }

        // Directions: up, right, down, left
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int,int>> q;

        q.push({sr, sc});
        vis[sr][sc] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // If destination found
            if (grid[r][c] == 2) return true;

            // Traverse neighbors
            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (isValid(nr, nc, n) && !vis[nr][nc] && grid[nr][nc] != 0) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return false;  // No path
    }
};