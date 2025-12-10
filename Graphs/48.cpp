// 399. Evaluate Division
 
 
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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dfs(string curr, string target, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        if (graph.find(curr) == graph.end() || graph.find(target) == graph.end()) return -1.0;
        if (curr == target) return 1.0;
        
        visited.insert(curr);
        
        for (auto& neighbor : graph[curr]) {
            string next = neighbor.first;
            double weight = neighbor.second;
            if (!visited.count(next)) {
                double result = dfs(next, target, graph, visited);
                if (result != -1.0) return weight * result;
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        // Step 1: Build the graph
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            double val = values[i];
            graph[u][v] = val;
            graph[v][u] = 1.0 / val;
        }
        
        // Step 2: Process queries
        vector<double> results;
        for (auto& q : queries) {
            string start = q[0], end = q[1];
            unordered_set<string> visited;
            results.push_back(dfs(start, end, graph, visited));
        }
        return results;
    }
};