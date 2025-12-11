// Nearest Exit from Entrance in Maze
 
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
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool inBounds(int r, int c, int m, int n) {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    bool isExitCell(int r, int c, int m, int n, int sr, int sc) {
        return (!(r == sr && c == sc)) && (r == 0 || r == m - 1 || c == 0 || c == n - 1);
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        if (m == 0) return -1;
        int n = maze[0].size();

        using P = pair<int, pair<int,int>>;
        queue<P> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int sr = entrance[0], sc = entrance[1];
        q.push({0, {sr, sc}});
        vis[sr][sc] = 1;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int steps = cur.first;
            int r = cur.second.first;
            int c = cur.second.second;

            if (isExitCell(r, c, m, n, sr, sc)) return steps;

            for (int k = 0; k < 4; ++k) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (inBounds(nr, nc, m, n) && !vis[nr][nc] && maze[nr][nc] == '.') {
                    vis[nr][nc] = 1;
                    q.push({steps + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};