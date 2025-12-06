// Eventual Safe states

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
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        int n = v.size();

        vector<vector<int>> adj(n);  // reverse graph
        vector<int> in(n, 0);        // indegree

        // build reverse graph
        for (int u = 0; u < n; u++) {
            for (int x : v[u]) {
                adj[x].push_back(u);   // reverse edge: x -> u
                in[u]++;               // indegree of original node u
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) q.push(i);  // terminal nodes
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int prev : adj[node]) {
                if (--in[prev] == 0)
                    q.push(prev);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};