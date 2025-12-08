// Number of Islands II (Online Queries)
 
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
class DisJointSet
{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int FindUpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = FindUpar(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv)
        {
            return;
        }
        if (rank[uu] < rank[uv])
        {
            parent[uu] = uv;
        }
        else if (rank[uu] > rank[uv])
        {
            parent[uv] = uu;
        }
        else
        {
            parent[uv] = uu;
            rank[uu]++;
        }
    }

    void UnionBySize(int u, int v)
    {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv)
        {
            return;
        }

        if (size[uu] < size[uv])
        {
            parent[uu] = uv;
            size[uv] += size[uu];
        }
        else
        {
            parent[uv] = uu;
            size[uu] += size[uv];
        }
    }
};

class Solution {
  public:
    bool isValid(int r, int c, int n, int m)
    {
        return (r>=0 && c>=0 && r<n && c<m);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &v) {
        // code here
        DisJointSet ds(n*m);
        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<int> ans;
        int cnt = 0;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(auto it: v)
        {
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col]==1)
            {
                ans.push_back(cnt);
                continue;
            } 
            vis[row][col] = 1;
            cnt++;
            
            for(int i=0; i<4; i++)
            {
                int adjrow = row+dx[i];
                int adjcol = col+dy[i];
                
                if(isValid(adjrow,adjcol,n,m))
                {
                    if(vis[adjrow][adjcol]==1)
                    {
                        int nodeno = row*m + col;
                        int adjno = adjrow*m + adjcol;
                        
                        if(ds.FindUpar(nodeno)!=ds.FindUpar(adjno))
                        {
                            ds.UnionBySize(nodeno, adjno);
                            cnt--;
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
