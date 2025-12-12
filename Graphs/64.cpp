// Word Search Board

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

bool isValid(int r, int c, int m, int n)
{
    return (r>=0 && c>=0 && r<m && c<n);
}

int solve(int r, int c,int m, int n,int id, 
vector<vector<char>>  &v, vector<vector<int>> &vis, string t,
int dx[], int dy[])
{
    vis[r][c] = 1;
    if(id==t.length()-1)
    {
        return true;
    }
    
    for(int i=0; i<4; i++)
    {
        int nr = r+dx[i];
        int nc = c+dy[i];
        
        if(isValid(nr,nc,m,n))
        {
            if(!vis[nr][nc])
            {
                if(v[nr][nc]==t[id+1])
                {
                    bool done = solve(nr,nc,m,n,id+1,v,vis,t,dx,dy);
                    if(done)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    
    return false;
}

int exist(vector<string> &s, string t) {
    int m = s.size();
    int n = s[0].size();
    
    vector<vector<char>> v(m, vector<char> (n));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            string p = s[i];
            v[i][j] = p[j];
        }
    }
    
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(v[i][j]==t[0])
            {
                vector<vector<int>> vis(m, vector<int> (n,0));
                bool done = solve(i,j,m,n,0,v,vis,t,dx,dy);
                if(done)
                {
                    return 1;
                }
            }
        }
    }
    
    return 0;
    
}
