// Combination Sum

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
    void solve(int i, vector<int> &v, int t,
    vector<vector<int>> &ans, vector<int> a)
    {
        if(i<0)
        {
            return;
        }

        if(t==0)
        {
            ans.push_back(a);
            return;
        }

        solve(i-1,v,t,ans,a);
        if(t>=v[i])
        {
            a.push_back(v[i]);
            solve(i,v,t-v[i],ans,a);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        int n = v.size();
        vector<vector<int>> ans;

        vector<int> a;
        solve(n-1,v,t,ans,a);

        return ans;
    }
};