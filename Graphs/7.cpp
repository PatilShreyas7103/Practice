#// 542. 01 Matrix
// Link: https://leetcode.com/problems/01-matrix/
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


class SolutionBFS {
public:
    bool isValid(int r, int c, int m, int n) {
        return (r>=0 && c>=0 && r<m && c<n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(v[i][j]==0) {
                    dis[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            int r = f.first;
            int c = f.second;
            for(int i=0; i<4; i++) {
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(isValid(nr,nc,m,n)) {
                    if(dis[r][c]+1 < dis[nr][nc]) {
                        dis[nr][nc] = dis[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return dis;
    }
};

class SolutionDP {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX-10000));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(v[i][j]==0) dis[i][j]=0;
                else {
                    if(i>0) dis[i][j] = min(dis[i][j], dis[i-1][j]+1);
                    if(j>0) dis[i][j] = min(dis[i][j], dis[i][j-1]+1);
                }
            }
        }
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i<m-1) dis[i][j] = min(dis[i][j], dis[i+1][j]+1);
                if(j<n-1) dis[i][j] = min(dis[i][j], dis[i][j+1]+1);
            }
        }
        return dis;
    }
};