// Knight On Chess Board (Steps by knight)

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

// Function to find minimum knight steps from (sr, sc) to (dr, dc)
int minKnightMoves(int n, int m, int sr, int sc, int dr, int dc) {
    if (sr == dr && sc == dc) return 0;

    vector<vector<int>> dist(n, vector<int>(m, -1));

    int dx[8] = {-2,-1,1,2, 2, 1,-1,-2};
    int dy[8] = { 1, 2,2,1,-1,-2,-2,-1};

    queue<pair<int,int>> q;
    q.push({sr, sc});
    dist[sr][sc] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front(); 
        q.pop();

        for (int k = 0; k < 8; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;

                if (nr == dr && nc == dc) 
                    return dist[nr][nc];

                q.push({nr, nc});
            }
        }
    }

    return -1; // unreachable
}
