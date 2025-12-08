// 778. Swim in Rising Water
 
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
    bool isValid(int i, int j, int m, int n)
    {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    int swimInWater(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> vis(n, vector<int> (n,0));

        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({v[0][0], {0,0}});
        vis[0][0] = 1;
        int ans = -1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();

            int w = t.first;
            int r = t.second.first;
            int c = t.second.second;

            ans=max(ans,w);
            if(r==n-1 && c==n-1)
            {
                break;
            }

            for(int i=0; i<4; i++)
                {
                    int nr = r+dr[i];
                    int nc = c+dc[i];

                    if(isValid(nr,nc,n,n))
                    {
                        if(!vis[nr][nc])
                        {
                            vis[nr][nc] = 1;
                            pq.push({v[nr][nc], {nr,nc}});
                        }
                    }
                }

        }

        return ans;
    }
};