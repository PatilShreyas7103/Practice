// Combination Sum I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i,vector<int>& v, int t, vector<int> ans, vector<vector<int>> &res)
    {
        if(t==0)
        {
            res.push_back(ans);
            return;
        }
        if(i<0 || t<0)
        {
            return;
        }


        solve(i-1,v,t,ans,res);
        ans.push_back(v[i]);
        solve(i,v,t-v[i],ans,res);
    }

    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        vector<vector<int>> res;
        int n = v.size();
        vector<int> ans;
         solve(n-1,v,t,ans,res);

         return res;
    }
};