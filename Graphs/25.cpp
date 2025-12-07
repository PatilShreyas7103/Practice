// 1631. Path With Minimum Effort

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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int r, int c, int m, int n) {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    int minimumEffortPath(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        using pi = pair<int, pair<int,int>>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        pq.push({0, {0, 0}});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();

            int eff = f.first;
            int row = f.second.first;
            int col = f.second.second;

            if (vis[row][col]) continue;
            vis[row][col] = 1;

            if (row == m - 1 && col == n - 1) return eff;

            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                if (isValid(nr, nc, m, n)) {
                    int diff = abs(v[nr][nc] - v[row][col]);
                    pq.push({max(diff, eff), {nr, nc}});
                }
            }
        }

        return -1;
    }
};