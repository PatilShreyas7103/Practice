// Graph Coloring (M-Coloring) 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int node, int col,
                vector<int> &color,
                vector<int> adj[]) {

        for (auto it : adj[node]) {
            if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int n, int m,
               vector<int> &color,
               vector<int> adj[]) {

        if (node == n) {
            return true;
        }

        for (int col = 1; col <= m; col++) {
            if (isSafe(node, col, color, adj)) {
                color[node] = col;

                if (solve(node + 1, n, m, color, adj)) {
                    return true;
                }

                color[node] = 0; // backtrack
            }
        }
        return false;
    }

    bool graphColoring(int n, vector<int> adj[], int m) {
        vector<int> color(n, 0);
        return solve(0, n, m, color, adj);
    }
};