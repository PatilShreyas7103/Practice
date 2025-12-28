// Find the Smallest Divisor Given a Threshold

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int d, vector<int>& v, int t) {
        long long sum = 0;
        for (int x : v) {
            sum += (x + d - 1) / d; // ceil(x / d)
        }
        return sum <= t;
    }

    int smallestDivisor(vector<int>& v, int t) {
        int s = 1;
        int e = *max_element(v.begin(), v.end());
        int ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(mid, v, t)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};