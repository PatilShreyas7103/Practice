#// 130. Surrounded Regions
// Link: https://leetcode.com/problems/surrounded-regions/
#include <bits/stdc++.h>
using namespace std;
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

class SolutionDFS {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    void dfs(int r, int c, int m, int n, vector<vector<char>>& v, vector<vector<int>>& vis, int dr[], int dc[]) {
        vis[r][c] = 1;
        for(int k=0; k<4; k++) {
            int nr = r+dr[k];
            int nc = c+dc[k];
            if(isValid(nr,nc,m,n)) {
                if(!vis[nr][nc] && v[nr][nc]=='O') {
                    dfs(nr,nc,m,n,v,vis,dr,dc);
                }
            }
        }
    }
    void solve(vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 || i==m-1 || j==0 || j==n-1) {
                    if(v[i][j]=='O') {
                        dfs(i,j,m,n,v,vis,dr,dc);
                    }
                }
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(vis[i][j]==0) {
                    v[i][j] = 'X';
                }
            }
        }
    }
};

class SolutionBFS {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    void solve(vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            if(v[i][0]=='O') { q.push({i,0}); vis[i][0]=1; }
            if(v[i][n-1]=='O') { q.push({i,n-1}); vis[i][n-1]=1; }
        }
        for(int j=0; j<n; j++) {
            if(v[0][j]=='O') { q.push({0,j}); vis[0][j]=1; }
            if(v[m-1][j]=='O') { q.push({m-1,j}); vis[m-1][j]=1; }
        }
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int r = cur.first, c = cur.second;
            for(int k=0; k<4; k++) {
                int nr = r+dr[k];
                int nc = c+dc[k];
                if(isValid(nr,nc,m,n) && !vis[nr][nc] && v[nr][nc]=='O') {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(vis[i][j]==0) {
                    v[i][j] = 'X';
                }
            }
        }
    }
};