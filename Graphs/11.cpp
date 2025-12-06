// Word ladder 2

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

    void dfs(string s, string e, vector<string> &path, 
    vector<vector<string>> &ans, unordered_map<string, unordered_set<string>> &adj )
    {
        path.push_back(s);

        if(s==e)
        {
            // reached end
            ans.push_back(path);
        }
        else
        {
            for(auto it: adj[s])
            {
                dfs(it,e,path,ans,adj);
            }
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string s, string e, vector<string>& w) {

        int n = s.length();

        queue<string> q; // traverse
        unordered_map<string,int> vis; // mark level
        unordered_map<string, unordered_set<string>> adj; // adj list
        unordered_set<string> st(w.begin(), w.end());

        q.push(s);
        vis[s] = 0;

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
                        // present in word list
                        if(temp==curr)
                        {
                            // same word skip
                            continue;
                        }

                        if(vis.count(temp)==0)
                        {
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

        dfs(s,e,path,ans,adj);

        return ans;
    }
};