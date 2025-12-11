// Redundant Connection
 
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
    void solve(int node, vector<int> adj[], int &count,
    vector<int> &vis)
    {
        vis[node] = 1;

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                count++;
                solve(it,adj,count,vis);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& v) {
        vector<int> ans;
        int n = v.size();
        vector<int> adj[n+1];
        int prev = 1;

        for(auto it: v)
        {
            int r = it[0];
            int c = it[1];

            adj[r].push_back(c);
            adj[c].push_back(r);

            int count = 0;
            vector<int> vis(n+1,0);
            for(int i=1; i<=n; i++)
            {
                if(!vis[i])
                {
                    solve(i,adj,count,vis);
                }
            }

            if(count==prev)
            {
                ans = it;
            }
            
            prev = count;
            
        }

        return ans;
    }
};