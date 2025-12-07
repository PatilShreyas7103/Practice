// Alien dictionary
// Link: https://leetcode.com/problems/alien-dictionary/

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
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    
    vector<int> topoSort(int v, vector<int> adj[])
    {
        vector<int> topo;
        queue<int> q;
    
        vector<int> inEdges(v, 0);
        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
            {
                inEdges[it]++;
            }
        }
    
        for (int i = 0; i < v; i++)
        {
            if (inEdges[i] == 0)
            {
                q.push(i);
            }
        }
    
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
    
            for (auto it : adj[node])
            {
                inEdges[it]--;
                if (inEdges[it] == 0)
                {
                    q.push(it);
                }
            }
        }
    
        return topo;
    }
  
  
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        
        for(int i=0; i<n-1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.length(), s2.length());
            for(int j=0; j<len; j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort (k, adj);
        string ans = "";
        for(auto it: topo)
        {
            char ch = it+'a';
            ans+= (ch);
        }
        
        return ans;
        
    }
};