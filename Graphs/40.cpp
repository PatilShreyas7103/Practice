// 827. Making A Large Island
 
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

class DisJointSet {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisJointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int FindUpar(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = FindUpar(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv) {
            return;
        }
        if (rank[uu] < rank[uv]) {
            parent[uu] = uv;
        } else if (rank[uu] > rank[uv]) {
            parent[uv] = uu;
        } else {
            parent[uv] = uu;
            rank[uu]++;
        }
    }

    void UnionBySize(int u, int v) {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv) {
            return;
        }

        if (size[uu] < size[uv]) {
            parent[uu] = uv;
            size[uv] += size[uu];
        } else {
            parent[uv] = uu;
            size[uu] += size[uv];
        }
    }
};

class Solution {
public:
    bool isValid(int r, int c, int n) {
        return (r >= 0 && c >= 0 && r < n && c < n);
    }

    int largestIsland(vector<vector<int>>& g) {
        int n = g.size();
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        int maxi = 0;
        DisJointSet ds(n*n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(g[i][j]==0)
                {
                    continue;
                }

                for(int ind=0; ind<4; ind++)
                {
                    int newR = i+dr[ind];
                    int newC = j+dc[ind];

                    if(isValid (newR, newC, n) && g[newR][newC]==1)
                    {
                        int node = i*n + j;
                        int adNode = newR*n + newC;

                        ds.UnionBySize (node, adNode);
                    }
                }
            }
        }

        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(g[row][col]==1)
                {
                    continue;
                }
                set<int> compo;
                for(int ind=0; ind<4; ind++)
                {
                    int newR = row+dr[ind];
                    int newC = col+dc[ind];

                    if(isValid (newR, newC, n) && g[newR][newC]==1)
                    {
                        compo.insert(ds.FindUpar(newR*n+newC));
                    }
                }

                int tot = 0;
                for(auto it: compo)
                {
                    tot+= ds.size[it];
                }

                maxi = max(maxi, tot+1);
            }
        }

        if(maxi==0) 
        { 
            // all 1s present
            return n*n;
        }
        return maxi;

    }
};