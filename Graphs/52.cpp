// Reorder Routes to Make All Paths Lead to the City Zero
 
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
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,-1});

        }

        vector<bool>visit(n,false);
        int res=0;
        queue<int>q;
        q.push(0);
        visit[0]=true;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(auto it:adj[node])
            {
                if(visit[it.first]==false)
                {
                    q.push(it.first);
                    visit[it.first]=true;
                    if(it.second==1)
                    res++;
                }

            }
        }
        return res;

        
    }
};