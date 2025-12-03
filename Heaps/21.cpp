// Minimum Cost Path in a Grid using Dijkstra's Algorithm

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

// Function to check if cell is valid.
bool isValidCell(int i, int j, int n) {
    return i>=0 && i<n && j>=0 && j<n;
}

int minimumCostPath(vector<vector<int>> &grid) {
    int n = grid.size();
    
    // Min heap to implement dijkstra
    priority_queue<vector<int>, 
    vector<vector<int>>, greater<vector<int>>> pq;
    
    // 2d grid to store minimum cost
    // to reach every cell.
    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
    cost[0][0] = grid[0][0];
    
    // Direction vector to move in 4 directions
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    pq.push({grid[0][0], 0, 0});
    
    while (!pq.empty()) {
        vector<int> top = pq.top();
        pq.pop();
        
        int c = top[0], i = top[1], j = top[2];
        
        // Check for all 4 neighbouring cells.
        for (auto d: dir) {
            int x = i + d[0];
            int y = j + d[1];
            
            // If cell is valid and cost to reach this cell 
            // from current cell is less
            if (isValidCell(x, y, n) && 
            cost[i][j]+grid[x][y]<cost[x][y]) {
                
                // Update cost to reach this cell.
                cost[x][y] = cost[i][j]+grid[x][y];
                
                // Push the cell into heap.
                pq.push({cost[x][y], x, y});
            }
        }
    }
    
    // Return minimum cost to 
    // reach bottom right cell.
    return cost[n-1][n-1];
}
