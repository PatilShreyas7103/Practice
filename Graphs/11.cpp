// 126. Word Ladder 2

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


class Solution {
public:
    void dfs(string b, string e, vector<string> path,unordered_map<string,unordered_set<string>> &adj, vector<vector<string>> &ans)
    {
        path.push_back(b);
        if(b==e)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(auto it: adj[b])
        {
            dfs(it,e,path,adj,ans);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string b, string e, vector<string>& w) {
        unordered_set<string> st(w.begin(), w.end()); // dictionary
        unordered_map<string,int> vis; // level depth
        unordered_map<string,unordered_set<string>> adj; // adjacency list

        queue<string> q;
        q.push(b);
        vis[b] = 0;
        int n = b.length();
        while(!q.empty())
        {
            string curr = q.front();
            q.pop();

            string temp = curr;
            for(int i=0; i<n; i++)
            {
                char c = temp[i];
                for(char ch='a'; ch<='z'; ch++)
                {
                    temp[i] = ch;

                    if(st.count(temp)>0)
                    {
                        if(temp==curr)
                        {
                            // same string
                            continue;
                        }

                        if(vis.count(temp)==0)
                        {
                            // not present
                            vis[temp] = vis[curr]+1;
                            q.push(temp);
                            adj[curr].insert(temp);
                        }
                        else if(vis[temp]==1+vis[curr])
                        {
                            adj[curr].insert(temp);
                        }
                    }
                    
                }
                temp[i] = c;
            }
        }
        vector<vector<string>> ans;
        vector<string> path;
        dfs(b,e,path,adj,ans);

        return ans;
    }
};