// Matchsticks to Square

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int n,
               vector<int> &v,
               vector<int> &side,
               int t) {

        if (i == n) {
            return side[0] == t &&
                   side[1] == t &&
                   side[2] == t &&
                   side[3] == t;
        }

        int val = v[i];

        for (int j = 0; j < 4; j++) {
            if (side[j] + val > t) continue;

            side[j] += val;
            if (solve(i + 1, n, v, side, t)) return true;
            side[j] -= val;

            // symmetry breaking
            if (side[j] == 0) break;
        }
        return false;
    }

    bool makesquare(vector<int>& v) {
        int n = v.size();
        if (n < 4) return false;

        int sum = 0;
        for (int x : v) sum += x;

        if (sum % 4 != 0) return false;

        int t = sum / 4;

        sort(v.rbegin(), v.rend()); // important

        if (v[0] > t) return false;

        vector<int> side(4, 0);
        return solve(0, n, v, side, t);
    }
};