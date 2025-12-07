// Shortest Path in a Binary Matrix
// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/

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

typedef pair<int,pair<int,int>> pi;
class Solution {
public:
    bool isValid(int r, int c, int m, int n)
    {
        return (r>=0 && c>=0 && r<m && c<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> dis(n, vector<int> (n,1e8));
        if(v[0][0]==1 || v[n-1][n-1]==1)
        {
            return -1;
        }

        queue<pi> pq;
        pq.push({1,{0,0}});
        dis[0][0] = 1;

        while(!pq.empty())
        {
            auto f = pq.front();
            pq.pop();

            int d = f.first;
            int r = f.second.first;
            int c = f.second.second;

            for(int dr=-1; dr<=1; dr++)
            {
                for(int dc=-1; dc<=1; dc++)
                {
                    int nr = r+dr;
                    int nc = c+dc;

                    if(isValid(nr,nc,n,n) && v[nr][nc]==0)
                    {
                        if(d+1<dis[nr][nc])
                        {
                            dis[nr][nc] = d+1;
                            pq.push({dis[nr][nc], {nr,nc}});
                        }
                    }
                }
            }
        }
        if(dis[n-1][n-1]==1e8)
        {
            return -1;
        }

        return dis[n-1][n-1];
    }
};