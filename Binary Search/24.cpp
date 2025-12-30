// Split Array Largest Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int lim, vector<int>& v, int k) {
        int parts = 1;
        int sum = 0;

        for (int x : v) {
            if (sum + x <= lim) {
                sum += x;
            } else {
                parts++;
                sum = x;
            }
        }
        return parts <= k;
    }

    int splitArray(vector<int>& v, int k) {
        int s = *max_element(v.begin(), v.end());
        int e = accumulate(v.begin(), v.end(), 0);
        int ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(mid, v, k)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};