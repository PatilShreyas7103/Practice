// 1559. Detect Cycles in 2D Grid

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
    bool isValid(int r, int c, int m, int n)
    {
        return (r>=0 && c>=0 && r<m && c<n);
    }

    bool dfs(int r, int c, int pr, int pc,int m, int n,
    vector<vector<int>> &vis, int dx[], int dy[],vector<vector<char>>& v)
    {
        vis[r][c] = 1;

        for(int i=0; i<4; i++)
        {
            int nr = r+dx[i];
            int nc = c+dy[i];

            if(isValid(nr, nc,m,n))
            {
                if(v[nr][nc]==v[r][c])
                {
                    if(!vis[nr][nc])
                    {
                        bool doit = dfs(nr,nc,r,c,m,n,vis,dx,dy,v);
                        if(doit)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        if(pr==nr && pc==nc)
                        {

                        }
                        else
                        {
                            return true;
                        }
                    }
                }
                
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        vector<vector<int>> vis(m, vector<int> (n,0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(vis[i][j]==0)
                {
                    if(dfs(i,j,-1,-1,m,n,vis,dx,dy,v))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};