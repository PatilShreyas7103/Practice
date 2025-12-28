// Aggressive Cows 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int dist, vector<int>& v, int k) {
        int cows = 1;
        int last = v[0];

        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i] - last >= dist) {
                cows++;
                last = v[i];
            }
        }
        return cows >= k;
    }

    int aggressiveCows(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int n = v.size();

        int s = 1;
        int e = v[n - 1] - v[0];
        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(mid, v, k)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};