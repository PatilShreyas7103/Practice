// Subset XOR Sum 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int n,
               vector<int> &v,
               int &ans,
               int curr) {

        if (i == n) {
            ans += curr;
            return;
        }

        // dont take
        solve(i + 1, n, v, ans, curr);

        // take
        curr ^= v[i];
        solve(i + 1, n, v, ans, curr);
    }

    int subsetXORSum(vector<int>& v) {
        int ans = 0;
        int curr = 0;
        int n = v.size();

        solve(0, n, v, ans, curr);
        return ans;
    }
};