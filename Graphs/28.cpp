// Number of Ways to Arrive at Destination
// Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

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
typedef pair<long long, long long> pi;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& v) {
        vector<vector<pi>> adj(n);
        long long mod = 1e9 + 7;
        for (auto it : v) {
            long long u = it[0];
            long long v = it[1];
            long long w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<pair<long long, long long>> dis(n, {LLONG_MAX, 0});
        pq.push({0, 0});
        dis[0] = {0, 1};

        while (!pq.empty()) {
            pair<long long, long long> f = pq.top();
            pq.pop();

            long long d = f.first;
            long long node = f.second;

            // if (d > dis[node].first) continue; // Optimization

            for (auto it : adj[node]) {
                long long child = it.first;
                long long w = it.second;

                if (w + d < dis[child].first) {
                    dis[child].first = w + d;
                    dis[child].second = dis[node].second;
                    pq.push({dis[child].first, child});
                } else if (w + d == dis[child].first) {
                    dis[child].second =
                        (dis[child].second + dis[node].second) % mod;
                }
            }
        }

        return dis[n - 1].second % mod;
    }
};