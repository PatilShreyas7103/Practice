// Accounts Merge
 
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        map<string,int> mp;
        int n = a.size();

        DisJointSet ds(n);

        for(int i=0; i<n; i++)
        {
            int sz = a[i].size();
            for(int j=1; j<sz; j++)
            {
                string m = a[i][j];
                if(mp.find(m)!=mp.end())
                {
                    ds.UnionBySize(i,mp[m]);
                }
                else
                {
                    mp[m] = i;
                }
            }
        }

        vector<vector<string>> v(n);
        for(auto it: mp)
        {
            string k = it.first;
            int par = it.second;
            int gpar = ds.FindUpar(par);

            v[gpar].push_back(k);
        }

        vector<vector<string>> ans;
        for(int i=0; i<n; i++)
        {
            if(v[i].size()==0)
            {
                continue;
            }
            string name = a[i][0];
            vector<string> t;
            t.push_back(name);
            for(auto it: v[i])
            {
                t.push_back(it);
            }
            ans.push_back(t);
        }
        
        return ans;
    }
};