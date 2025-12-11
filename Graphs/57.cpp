// Max Area of Island (BFS+DFS+DSU)
#include <bits/stdc++.h>
 
 
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
using namespace std;

class SolutionDFS {
public:
    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && c >= 0 && r < m && c < n;
    }

    void dfs(int r, int c, int m, int n,
             vector<vector<int>>& vis,
             int &cnt,
             int dx[], int dy[],
             vector<vector<int>>& grid)
    {
        vis[r][c] = 1;
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (isValid(nr, nc, m, n) &&
                !vis[nr][nc] &&
                grid[nr][nc] == 1)
            {
                dfs(nr, nc, m, n, vis, cnt, dx, dy, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int maxArea = 0;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1 && !vis[r][c]) {
                    int cnt = 0;
                    dfs(r, c, m, n, vis, cnt, dx, dy, grid);
                    maxArea = max(maxArea, cnt);
                }
            }
        }
        return maxArea;
    }
};

class SolutionBFS {
public:
    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && c >= 0 && r < m && c < n;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int maxArea = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1 && !vis[r][c]) {
                    queue<pair<int,int>> q;
                    q.push({r, c});
                    vis[r][c] = 1;

                    int area = 1;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];

                            if (isValid(nx, ny, m, n) &&
                                !vis[nx][ny] &&
                                grid[nx][ny] == 1)
                            {
                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                                area++;
                            }
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};

class DisJointSet
{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int FindUpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = FindUpar(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv)
        {
            return;
        }
        if (rank[uu] < rank[uv])
        {
            parent[uu] = uv;
        }
        else if (rank[uu] > rank[uv])
        {
            parent[uv] = uu;
        }
        else
        {
            parent[uv] = uu;
            rank[uu]++;
        }
    }

    void UnionBySize(int u, int v)
    {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv)
        {
            return;
        }

        if (size[uu] < size[uv])
        {
            parent[uu] = uv;
            size[uv] += size[uu];
        }
        else
        {
            parent[uv] = uu;
            size[uu] += size[uv];
        }
    }
};

class DSU_Solution {
public:
    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && c >= 0 && r < m && c < n;
    }
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        DisJointSet ds(m*n);
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        int ans = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int node = i*n + j;
                if(v[i][j]==1)
                {
                    for(int k=0; k<4; k++)
                    {
                        int nr = i+dx[k];
                        int nc = j+dy[k];

                        int adnode = nr*n + nc;

                        if(isValid(nr,nc,m,n) && v[nr][nc]==1)
                        {
                            if(ds.FindUpar(node) != ds.FindUpar(adnode))
                            {
                                ds.UnionBySize(node,adnode);
                            }
                        }
                    }
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==1)
                {
                    int node = i*n+j;
                    ans=max(ans,ds.size[node]);
                }
            }
        }

        return ans;
    }
};