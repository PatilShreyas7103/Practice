// Circle of strings

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

    // DFS on directed graph (for connectivity check)
    void dfs(int u, vector<int> adj[], vector<bool> &vis) {
        vis[u] = true;
        for (auto v : adj[u]) {
            if (!vis[v])
                dfs(v, adj, vis);
        }
    }

    // Check if graph is connected ignoring direction
    bool isConnected(int start, vector<int> adj[], vector<bool> &mark) {
        vector<bool> vis(26, false);

        dfs(start, adj, vis);

        // All marked nodes must be visited
        for (int i = 0; i < 26; i++) {
            if (mark[i] && !vis[i])
                return false;
        }
        return true;
    }

    int isCircle(vector<string> &A) {
        int n = A.size();

        vector<int> indeg(26, 0), outdeg(26, 0);
        vector<int> adj[26];
        vector<bool> mark(26, false);  // which characters appear

        // Build graph
        for (auto &s : A) {
            int u = s.front() - 'a';     // first character
            int v = s.back() - 'a';      // last character

            adj[u].push_back(v);
            outdeg[u]++;
            indeg[v]++;
            mark[u] = mark[v] = true;
        }

        // Condition 1: in-degree must equal out-degree for all characters
        for (int i = 0; i < 26; i++) {
            if (indeg[i] != outdeg[i])
                return 0;
        }

        // Condition 2: all active nodes must be connected
        int start = A[0].front() - 'a';    // start DFS from first string’s first char

        if (!isConnected(start, adj, mark))
            return 0;

        return 1;  // Eulerian cycle exists → circle possible
    }
};