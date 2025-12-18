// Interleaving String

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


class MemoizationSolution {
public:
    bool solve(int i, int j, int k, string &p, string &q, string &r, int a, int b,int c, vector<vector<vector<int>>> &dp)
    {
        if(i==a && j==b && k==c)
        {
            return true;
        }

        if(dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }
        
        if(r[k]==p[i] && r[k]==q[j])
        {
            bool f = solve(i+1,j,k+1,p,q,r,a,b,c,dp) || solve(i,j+1,k+1,p,q,r,a,b,c,dp);
            if(!f)
            {
                return dp[i][j][k] = 0;
            }
        }
        else if(r[k]==p[i])
        {
            bool f = solve(i+1,j,k+1,p,q,r,a,b,c,dp);
            if(!f)
            {
                return dp[i][j][k] = 0;
            }
        }
        else if(r[k]==q[j])
        {
            bool f = solve(i,j+1,k+1,p,q,r,a,b,c,dp);
            if(!f)
            {
                return dp[i][j][k] = 0;
            }
        }
        else
        {
            return dp[i][j][k] = 0;
        }

        return dp[i][j][k] = 1;
    }
    bool isInterleave(string p, string q, string r) {
        int a = p.length();
        int b = q.length();
        int c = r.length();

        vector<vector<vector<int>>> dp(a+1, vector<vector<int>> (b+1, vector<int> (c+1,-1)));

        if(c!=(a+b))
        {
            return false;
        }

        return solve(0,0,0,p,q,r,a,b,c,dp);
    }
};


class TabulationSolution {
public:
    bool isInterleave(string p, string q, string r) {
        int a = p.size(), b = q.size(), c = r.size();
        if (a + b != c) return false;

        vector<vector<vector<int>>> dp(
            a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, 0))
        );

        dp[a][b][c] = 1;  // base case

        for (int i = a; i >= 0; i--) {
            for (int j = b; j >= 0; j--) {
                for (int k = c; k >= 0; k--) {

                    if (i == a && j == b && k == c) continue;

                    bool ok = false;

                    if (i < a && k < c && p[i] == r[k])
                        ok = ok || dp[i + 1][j][k + 1];

                    if (j < b && k < c && q[j] == r[k])
                        ok = ok || dp[i][j + 1][k + 1];

                    dp[i][j][k] = ok;
                }
            }
        }

        return dp[0][0][0];
    }
};