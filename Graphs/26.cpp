// 787. Cheapest Flights Within K Stops
// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/

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
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k)  {
        vector<pair<int,int>> adj[n];
        vector<int> dis(n,1e8);
        for(auto it: f)
        {
            int k1 = it[0];
            int k2 = it[1];
            int cs = it[2];

            adj[k1].push_back({k2,cs});
        }

        queue<pair<int,pair<int,int>>> pq;

        dis[src] = 0;
        // stop, {node, price}
        pq.push({0,{src, 0}});
        while(!pq.empty())
        {
            auto temp = pq.front();
            int st = temp.first;
            int node = temp.second.first;
            int pri = temp.second.second;
            pq.pop();

            for(auto it: adj[node])
            {
                int adn = it.first;
                int wt = it.second;

                if(pri + wt < dis[adn] && st<=k)
                {
                    dis[adn] = pri+wt;
                    pq.push({st+1,{adn, pri+wt}});
                }
            }
        }
        if(dis[dst]==1e8)
        {
            return -1;
        }
        return dis[dst];
        
    }
};