// Detect Cycle in Directed Graph — Kahn’s Topological Sort
// Link: https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution-kahns-algorithm/

#include <bits/stdc++.h>
using namespace std;
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

class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            for (int nb : adj[node]) {
                if (--indeg[nb] == 0) q.push(nb);
            }
        }
        return ans;
    }

    bool isCyclic(int n, vector<vector<int>> &edges) {
        vector<int> topo = topoSort(n, edges);
        return topo.size() != (n);
    }
};