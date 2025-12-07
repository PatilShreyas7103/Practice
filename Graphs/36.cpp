// 1319. Number of Operations to Make Network Connected
 
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
class DisJointSet {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisJointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int FindUpar(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = FindUpar(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv) {
            return;
        }
        if (rank[uu] < rank[uv]) {
            parent[uu] = uv;
        } else if (rank[uu] > rank[uv]) {
            parent[uv] = uu;
        } else {
            parent[uv] = uu;
            rank[uu]++;
        }
    }

    void UnionBySize(int u, int v) {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv) {
            return;
        }

        if (size[uu] < size[uv]) {
            parent[uu] = uv;
            size[uv] += size[uu];
        } else {
            parent[uv] = uu;
            size[uu] += size[uv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& v) {
        int e = v.size();
        if(n-1>e)
        {
            return -1;
        }

        DisJointSet ds(n);
        for(auto it: v)
        {
            int a = it[0];
            int b = it[1];

            ds.UnionBySize(a,b);
        }

        int c = 0;
        for(int i=0; i<n; i++)
        {
            if(ds.FindUpar(i)==i)
            {
                c++;
            }
        }

        return c-1;
    }
};