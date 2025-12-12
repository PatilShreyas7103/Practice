// Bridge edge in a graph

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
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
    bool isBridge(int n, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<int> adj[n];
        
        for(auto it: edges)
        {
            int a = it[0];
            int b = it[1];
            
            if((a==c && b==d ) || (a==d && b==c))
            {
                continue;
            }
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> vis(n,0);
        dfs(c,adj,vis);
        
        if(vis[d]==1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};