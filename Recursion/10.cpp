// Check if Any Subsequence Sum Equals Target

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, vector<int> &v, int t) {
        if (t < 0) {
            return false;
        }
        if (i < 0) {
            return t == 0;
        }

        bool dont = solve(i - 1, v, t);
        bool take = solve(i - 1, v, t - v[i]);

        return take || dont;
    }

    bool checkSubsequenceSum(int n, vector<int>& v, int t) {
        return solve(n - 1, v, t);
    }
};