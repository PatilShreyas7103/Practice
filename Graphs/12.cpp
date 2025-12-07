// Count Islands (DFS Approach)
// Link: https://leetcode.com/problems/number-of-islands/

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

class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        return (r >= 0 && c >= 0 && r < n && c < m);
    }
    
    void dfs(int r, int c, int n, int m, vector<vector<char>> &v,
             vector<vector<int>> &vis, int dx[], int dy[]) 
    {
        vis[r][c] = 1;
        
        for(int i = 0; i < 8; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            
            if(isValid(nr, nc, n, m)) {
                if(v[nr][nc] == 'L' && !vis[nr][nc]) {
                    dfs(nr, nc, n, m, v, vis, dx, dy);
                }
            }
        }
    }

    int countIslands(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int dx[] = {-1,-1, 0, 1, 1, 1, 0, -1};
        int dy[] = { 0, 1, 1, 1, 0,-1,-1, -1};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == 'L' && !vis[i][j]) {
                    ans++;
                    dfs(i, j, n, m, v, vis, dx, dy);
                }
            }
        }
        
        return ans;
    }
};