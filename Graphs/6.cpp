// Cycle Detection in Undirected Graph using BFS and DFS

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

class CycleDetectorDFS {
private:
    bool isCyclicUtil(int node, int parent, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, node, adj, visited)) {
                    return true;
                }
            }
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, -1, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class CycleDetectorBFS {
private:
    bool isCyclicUtil(int src, vector<int> adj[], vector<int>& visited) {
        visited[src] = 1; 
        queue<pair<int, int>> q; 
        q.push({src, -1}); 
        
        while (!q.empty()) {
            int node = q.front().first; 
            int parent = q.front().second; 
            q.pop(); 
            
            for (auto adjacentNode : adj[node]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = 1; 
                    q.push({adjacentNode, node}); 
                }
                else if (parent != adjacentNode) {
                    return true; 
                }
            }
        }
        return false; 
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, adj, visited)) {
                    return true; 
                }
            }
        }
        return false; 
    }
};
