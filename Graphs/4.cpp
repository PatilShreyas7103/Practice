// Rotting oranges
// Link: https://leetcode.com/problems/rotting-oranges/

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
    bool isValid(int i, int j, int m, int n)
    {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    int orangesRotting(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        int ans = 0;
        bool f = false;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int> (n,0));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==1)
                {
                    f = true;
                }
                else if(v[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
                else
                {
                    vis[i][j] = 1;
                }
            }
        }
        if(!f)
        {
            return 0;
        }

        while(!q.empty())
        {
            int sz = q.size();
            ans++;
            for(int i=0; i<sz; i++)
            {
                auto f = q.front();
                q.pop();

                int r = f.first;
                int c = f.second;

                for(int i=0; i<4; i++)
                {
                    int nr = r+dr[i];
                    int nc = c+dc[i];

                    if(isValid(nr,nc,m,n))
                    {
                        if(v[nr][nc]==1 && !vis[nr][nc])
                        {
                            vis[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
                
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(vis[i][j]==0)
                {
                    return -1;
                }
            }
        }

        return ans-1;
    }
};