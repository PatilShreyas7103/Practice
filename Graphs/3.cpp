// Number of Provinces (DFS + BFS)
// Link: https://leetcode.com/problems/number-of-provinces/

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

struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int x) : val(x) {}
};

class SolutionDFS {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> adj[n + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 1) {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }

        vector<int> vis(n + 1, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i, adj, vis);
            }
        }
        return ans;
    }
};

class SolutionBFS {
public:
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> adj[n + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 1) {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }

        vector<int> vis(n + 1, 0);
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                ans++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : adj[node]) {
                        if (!vis[it]) {
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return ans;
    }
};