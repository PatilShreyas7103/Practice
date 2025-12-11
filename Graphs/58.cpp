// Walls and gates
 
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

    bool isValid(int r, int c, int m,  int n)
    {
        return (r>=0 && c>=0 && r<m && c<n);
    }
    void islandsAndTreasure(vector<vector<int>>& v) {
        int m  = v.size();
        int n = v[0].size();

        queue<pair<int,int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(!q.empty())
        {
            auto f = q.front();
            q.pop();

            int r = f.first;
            int c = f.second;

            for(int i=0; i<4; i++)
            {
                int nr = r+dx[i];
                int nc = c+dy[i];

                if(isValid(nr,nc,m,n))
                {
                    if(v[nr][nc]!=0 && v[nr][nc]!=-1)
                    {
                        if(v[r][c]+1<v[nr][nc])
                        {
                            v[nr][nc] = 1+v[r][c];
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
    }
};
