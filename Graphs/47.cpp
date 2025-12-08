//  417. Pacific Atlantic Water Flow
 
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

    void dfs(int r, int c, vector<vector<int>> &vis, int m, int n,
    int dx[], int dy[], vector<vector<int>>& v)
    {
        vis[r][c] = 1;

        for(int i=0; i<4; i++)
        {
            int nr = r+dx[i];
            int nc = c+dy[i];

            if(isValid(nr,nc,m,n))
            {
                if(!vis[nr][nc] && v[nr][nc] >= v[r][c])
                {
                    dfs(nr,nc,vis,m,n,dx,dy,v);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> pac(m, vector<int> (n,0));
        vector<vector<int>> atl(m, vector<int> (n,0));

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0; i<m; i++)
        {
            dfs(i,0,pac,m,n,dx,dy,v);
        }
        for(int i=0; i<m; i++)
        {
            dfs(i,n-1,atl,m,n,dx,dy,v);
        }
        for(int i=0; i<n; i++)
        {
            dfs(0,i,pac,m,n,dx,dy,v);
        }
        for(int i=0; i<n; i++)
        {
            dfs(m-1,i,atl,m,n,dx,dy,v);
        }

        vector<vector<int>> ans;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(pac[i][j] && atl[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

    }
};