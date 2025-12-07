// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
 
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
    int findTheCity(int n, vector<vector<int>>& e, int d) {
        vector<vector<int>> dis(n, vector<int> (n,1e9));
        for(int i=0; i<n; i++)
            {
                dis[i][i] = 0;                
            }

        for(auto it: e)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            dis[u][v] = w;
            dis[v][u] = w;
        }

        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
                }
            }
        }
        int cnt = n;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int c = 0;
            for(int j=0; j<n; j++)
            {
                if(dis[i][j]<=d)
                {
                    c++;
                }
            }
            if(c<=cnt)
            {
                cnt = c;
                ans=i;
            }
        }

        return ans;
    }
};