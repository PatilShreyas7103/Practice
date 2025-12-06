// Shortest Path in Undirected Graph (BFS)

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

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<vector<int>> adj(N);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        const int INF = 1e9;
        vector<int> dist(N, INF);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int node = q.front(); 
            q.pop();
            for (int nei : adj[node]) {
                if (dist[node] + 1 < dist[nei]) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }

        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++)
            if (dist[i] != INF) ans[i] = dist[i];

        return ans;
    }
};