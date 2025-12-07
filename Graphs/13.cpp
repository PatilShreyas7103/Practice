// Is Graph Bipartite?
// Link: https://leetcode.com/problems/is-graph-bipartite/

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

class SolutionDFS {
public:
    bool dfs(int node, vector<int> &col, vector<int> &vis, vector<vector<int>> &adj, int c) {
        vis[node] = 1;
        col[node] = c;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                bool solve = dfs(it, col, vis, adj, !c);
                if (!solve) return false;
            } else {
                if (col[it] == col[node]) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> col(n, -1);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bool check = dfs(i, col, vis, adj, 0);
                if (!check) return false;
            }
        }

        return true;
    }
};

class SolutionBFS {
public:
    bool bfs(int node, vector<int> &vis, vector<int> &col, vector<vector<int>>& adj) {
        queue<pair<int,int>> q;
        q.push({node, 0});
        vis[node] = 1;
        col[node] = 0;

        while (!q.empty()) {
            int temp = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto it : adj[temp]) {
                if (!vis[it]) {
                    q.push({it, !c});
                    col[it] = !c;
                    vis[it] = 1;
                } else {
                    if (col[it] == c) return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> col(n, -1);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bool f = bfs(i, vis, col, adj);
                if (!f) return false;
            }
        }

        return true;
    }
};