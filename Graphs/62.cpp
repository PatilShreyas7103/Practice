// Minimum Height Trees - optimized (topological leaf removal)

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

class BruteForceSolution {
public:

    void dfs(int node,int &h, vector<int> &vis,
    vector<int> adj[], int curr)
    {
        vis[node] = 1;  
        h = max(h,curr);
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it,h,vis,adj, curr+1);
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> adj[n];

        for(auto it: edges)
        {
            int a = it[0];
            int b = it[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int mini = n;

        for(int i=0; i<n; i++)
        {
            vector<int> vis(n,0);
            int h = 0;
            dfs(i,h,vis,adj,0);

            if(mini==h)
            {
                ans.push_back(i);
            }
            else if(h<mini)
            {
                mini = h;
                ans.clear();
                ans.push_back(i);
            }
        }

        return ans;
    }
};

class OptiimizedSolution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++; degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) q.push(i); // leaf
        }

        int remaining = n;
        while (remaining > 2) {
            int leafCount = q.size();
            remaining -= leafCount;
            for (int i = 0; i < leafCount; ++i) {
                int leaf = q.front(); q.pop();
                for (int nei : adj[leaf]) {
                    degree[nei]--;
                    if (degree[nei] == 1) q.push(nei);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};