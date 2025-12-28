// Koko Eating Bananas 

#include <bits/stdc++.h>
using namespace std;

class SolutionLinear {
public:
    int calculateTotalHours(vector<int>& a, int k) {
        int hours = 0;
        for (int x : a) {
            hours += (x + k - 1) / k;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& a, int h) {
        int mx = *max_element(a.begin(), a.end());
        for (int k = 1; k <= mx; k++) {
            if (calculateTotalHours(a, k) <= h) {
                return k;
            }
        }
        return mx;
    }
};

class SolutionBinary {
public:
    bool check(int k, vector<int>& v, int h) {
        long long cnt = 0;
        for (int x : v) {
            cnt += (x + k - 1) / k;
        }
        return cnt <= h;
    }

    int minEatingSpeed(vector<int>& v, int h) {
        int s = 1;
        int e = *max_element(v.begin(), v.end());
        int ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(mid, v, h)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};