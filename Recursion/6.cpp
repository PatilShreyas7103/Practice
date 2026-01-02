// Generate All Binary Strings of Length N

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, string s, vector<string> &ans) {
        if (n == 0) {
            ans.push_back(s);
            return;
        }

        solve(n - 1, s + '0', ans);
        solve(n - 1, s + '1', ans);
    }

    vector<string> binstr(int n) {
        vector<string> ans;
        solve(n, "", ans);
        return ans;
    }
};