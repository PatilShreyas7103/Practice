// Minimum Spanning Tree using Prim's Algorithm
 
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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(v,0);
        pq.push({0,0}); //wt,node
        
        int s = 0;
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second;
            
            if(!vis[node])
            {
                s+= wt;
                vis[node]=1;
                for(auto t:adj[node])
                {
                    int adNode = t[0];
                    int w = t[1];
                    
                    if(!vis[adNode])
                    {
                        pq.push({w,adNode});
                    }
                }
            }
            
        }
        
        return s;
    }
};