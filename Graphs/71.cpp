// Hamiltonian Path

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
// Check if an undirected graph contains a Hamiltonian Path

class Solution {
public:
    vector<vector<int>> adj;  // adjacency list

    // DFS with backtracking
    bool dfs(int node, vector<int> &visited, int visitedCount, int totalNodes) {
        visited[node] = 1;

        // If we visited all nodes exactly once → Hamiltonian Path found
        if (visitedCount == totalNodes)
            return true;

        // Try all neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, visitedCount + 1, totalNodes))
                    return true;

                visited[neighbor] = 0;  // backtrack
            }
        }

        return false;
    }

    bool check(int n, int m, vector<vector<int>> &edges) {
        // Build adjacency list
        adj = vector<vector<int>>(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n + 1, 0);

        // Try starting DFS from every node
        for (int start = 1; start <= n; start++) {
            fill(visited.begin(), visited.end(), 0);

            if (dfs(start, visited, 1, n))
                return true;
        }

        return false;
    }
};