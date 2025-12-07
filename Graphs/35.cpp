// Kruskal's Algorithm to find Minimum Spanning Tree
 
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

class DisjointSet {
    /* To store the ranks, parents and 
    sizes of different set of vertices */
    vector<int> rank, parent, size;
    
public:

    // Constructor
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // Function to find ultimate parent
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    // Function to implement union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    // Function to implement union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Solution class
class Solution{
public:

    // Function to get the sum of weights of edges in MST
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // To store the edges
        vector<pair<int, pair<int, int>>> edges;
        
        // Getting all edges from adjacency list
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int v = it[0]; // Node v
                int wt = it[1]; // edge weight
                int u = i; // Node u
                edges.push_back({wt, {u, v}});
            }
        }
        
        // Creating a disjoint set of V vertices
        DisjointSet ds(V);
        
        // Sorting the edges based on their weights
        sort(edges.begin(), edges.end());
        
        // To store the sum of edges in MST
        int sum = 0;
        
        // Iterate on the edges
        for (auto it : edges) {
            int wt = it.first; // edge weight
            int u = it.second.first; // First node
            int v = it.second.second; // Second node
            
            // Join the nodes if not in the same set 
            if (ds.findUPar(u) != ds.findUPar(v)) {
                
                // Update the sum of edges in MST
                sum += wt;
                
                // Unite the nodes 
                ds.unionBySize(u, v);
            }
        }
        
        // Return the computed sum
        return sum;
    }
};

