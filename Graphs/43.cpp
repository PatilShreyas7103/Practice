// Articulation Points in a Graph

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
    
private:
    int timer = 1;
    void dfs (int node, int parent, vector<int> adj[],int low[], int tin[], vector<int> &vis, vector<int> &mark)
    {
        vis[node]=1;
        low[node] = timer;
        tin[node] = timer;
        timer++;
        int child = 0;
        
        for(auto it: adj[node])
        {
            if(it==parent)
            {
                continue;
            }
            if(!vis[it])
            {
                dfs(it,node,adj, low, tin, vis, mark);
                low[node] = min(low[node], low[it]);
                if(low[it]>=tin[node] && parent!=-1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        
        if(child>1 && parent==-1)
        {
            mark[node] = 1;
        }
    }
public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n,0);
        int low[n];
        int tin[n];
        vector<int> ans;
        vector<int> mark(n,0);
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,adj, low, tin, vis, mark);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(mark[i]==1)
            {
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0)
        {
            return {-1};
        }
        return ans;
    }
};