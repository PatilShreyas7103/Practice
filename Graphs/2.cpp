// DFS Traversal of Graph

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

struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int x) : val(x) {}
};

class Solution {
public:
    void dfs(int v, vector<int> adj[], vector<int>& visited, vector<int>& result) {
        visited[v] = 1;
        result.push_back(v);
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, adj, visited, result);
            }
        }
    }
};