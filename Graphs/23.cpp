#// Dijkstra's algorithm
// Link: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

#include <bits/stdc++.h>
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

// ---------------------- Dijkstra using priority_queue ----------------------
class DijkstraPQ {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
        const int INF = 1e9;
        vector<int> dist(V, INF);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top(); 
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &e : adj[node]) {
                int nxt = e.first;
                int wt  = e.second;

                if (dist[node] + wt < dist[nxt]) {
                    dist[nxt] = dist[node] + wt;
                    pq.push({dist[nxt], nxt});
                }
            }
        }
        return dist;
    }
};

// ---------------------- Dijkstra using set ----------------------
class DijkstraSet {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
        const int INF = 1e9;
        vector<int> dist(V, INF);

        set<pair<int,int>> st;

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(st.begin());

            int d = it.first, node = it.second;

            for (auto &e : adj[node]) {
                int nxt = e.first;
                int wt  = e.second;

                if (d + wt < dist[nxt]) {

                    if (dist[nxt] != INF) 
                        st.erase({dist[nxt], nxt});

                    dist[nxt] = d + wt;
                    st.insert({dist[nxt], nxt});
                }
            }
        }
        return dist;
    }
};
