// Flood fill
// Link: https://leetcode.com/problems/flood-fill/

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
    bool isValid(int i,int j, int m, int n)
    {   
        return (i>=0 && j>=0 && i<m && j<n);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int col) {
        int m = v.size();
        int n = v[0].size();
        int g = v[sr][sc];

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        vector<vector<int>> vis(m, vector<int> (n,0));

        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;

        while(!q.empty())
        {
            auto f = q.front();
            q.pop();

            int r = f.first;
            int c = f.second;

            v[r][c] = col;

            for(int i=0; i<4; i++)
            {
                int nr = r+dx[i];
                int nc = c+dy[i];

                if(isValid(nr,nc,m,n))
                {
                    if(v[nr][nc]==g && !vis[nr][nc])
                    {
                        vis[nr][nc] = 1;
                        
                        q.push({nr,nc});
                    }
                }
            }
        }

        return v;
    }
};