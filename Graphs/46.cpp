// Graph valid tree
 
 
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

// ------------------------------------
// Approach 1: DFS to detect cycle
// ------------------------------------
class SolutionDFS {
public:
    bool dfs(int node, int parent, vector<int>& visited, vector<int> adj[]) {
        visited[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(it, node, visited, adj)) return true;
            } else {
                if (it != parent) return true;  // cycle found
            }
        }
        return false;
    }

    int isTree(int n, int m, vector<vector<int>> &edges) {
        vector<int> adj[n];
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited, adj)) return 0;  // cycle exists
            }
        }

        // ensure graph is connected (all visited)
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return 0;
        }
        return 1;
    }
};

// ------------------------------------
// Approach 2: BFS to check connectivity & edges count
// ------------------------------------
class SolutionBFS {
public:
    int isTree(int n, int m, vector<vector<int>> &edges) {

        // Tree must have exactly n-1 edges
        if (m != n - 1) return 0;

        vector<int> adj[n];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        queue<int> q;

        int start = 0;
        q.push(start);
        vis[start] = true;
        int countVisited = 1;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = true;
                    countVisited++;
                    q.push(it);
                }
            }
        }

        return (countVisited == n);  // all nodes reachable → tree
    }
};