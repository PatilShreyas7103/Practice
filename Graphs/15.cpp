// Topological Sort — DFS and Kahn's Algorithm
// Link: https://www.geeksforgeeks.org/topological-sorting/

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

class Solution_DFS {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
        vis[node] = 1;
        for (int it : adj[node]) {
            if (!vis[it]) dfs(it, vis, adj, st);
        }
        st.push(node);
    }

    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        stack<int> st;

        for (auto &e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
        }

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) dfs(i, vis, adj, st);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

class Solution_Kahn {
public:
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            indeg[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            for (int it : adj[node]) {
                if (--indeg[it] == 0) q.push(it);
            }
        }
        return ans;
    }
};