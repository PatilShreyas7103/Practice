// Capacity To Ship Packages Within D Days

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int cap, vector<int>& v, int d) {
        int days = 1;
        int load = 0;

        for (int x : v) {
            if (load + x <= cap) {
                load += x;
            } else {
                days++;
                load = x;
            }
        }
        return days <= d;
    }

    int shipWithinDays(vector<int>& v, int d) {
        int s = *max_element(v.begin(), v.end());
        int e = accumulate(v.begin(), v.end(), 0);
        int ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(mid, v, d)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};