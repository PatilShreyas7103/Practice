// Word Boggle

// Optimal : Using trie (not attempted here)

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
    bool isValid(int r, int c, int m, int n)
    {
        return (r>=0 && c>=0 && r<m && c<n);
    }
    bool dfs(int r, int c, int id,string &s, 
    vector<vector<char>> &v, int m, int n, vector<vector<int>> &vis)
    {
        if(id==s.length()-1)
        {
            return true;
        }
        vis[r][c] = 1;
        
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1;j++)
            {
                int nr = r+i;
                int nc = c+j;
                
                if(isValid(nr,nc,m,n) && !vis[nr][nc])
                {
                    if(s[id+1]==v[nr][nc])
                    {
                        bool k = dfs(nr,nc,id+1,s,v,m,n,vis);
                        if(k)
                        {
                            vis[r][c] = 0;
                            return true;
                        }
                    }
                }
            }
        }
        vis[r][c] = 0;
        return false;
    }
    
    vector<string> wordBoggle(vector<vector<char> >& v,
                              vector<string>& dict) {
        // Code here
        vector<string> ans;
        int m = v.size();
        int n = v[0].size();

        for(auto s: dict)
        {
            bool f = false;
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(v[i][j]==s[0])
                    {
                        vector<vector<int>> vis(m, vector<int> (n,0));
                        bool done = dfs(i,j,0,s,v,m,n,vis);
                        if(done)
                        {
                            ans.push_back(s);
                            f = true;
                            break;
                        }
                    }
                }
                if(f)
                {
                    break;
                }
            }
            
        }
        
        return ans;
    }
};