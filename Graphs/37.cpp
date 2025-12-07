// 947. Most Stones Removed with Same Row or Column
 
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
    void dfs(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& s) {
        int n = s.size();
        unordered_map<int, vector<int>> row_map, col_map;
        vector<int> adj[n];

        for (int i = 0; i < n; i++) {
            int row = s[i][0], col = s[i][1];
            row_map[row].push_back(i);
            col_map[col].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            int row = s[i][0], col = s[i][1];

            for (int j : row_map[row]) {
                if (j != i) adj[i].push_back(j);
            }
            for (int j : col_map[col]) {
                if (j != i) adj[i].push_back(j);
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++; 
                dfs(i, adj, vis);
            }
        }

        return n - cnt;  
    }
};