// Minimum Number of Days to Make m Bouquets

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int d, vector<int>& v, int m, int k) {
        int cnt = 0;
        int bouquets = 0;

        for (int x : v) {
            if (x <= d) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        bouquets += cnt / k;
        return bouquets >= m;
    }

    int minDays(vector<int>& v, int m, int k) {
        int n = v.size();
        if ((long long)n < (long long)m * k) return -1;

        int s = *min_element(v.begin(), v.end());
        int e = *max_element(v.begin(), v.end());
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(mid, v, m, k)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};