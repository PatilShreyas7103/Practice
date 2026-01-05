// Trapping Rain Water
#include <bits/stdc++.h>
using namespace std;

/* Approach 1: Prefix & Suffix Maximums */
class SolutionPrefixSuffix {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        vector<int> pre(n, 0), suf(n, 0);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            pre[i] = mx;
            mx = max(mx, v[i]);
        }

        mx = 0;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = mx;
            mx = max(mx, v[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int water = min(pre[i], suf[i]);
            if (water > v[i]) {
                ans += water - v[i];
            }
        }

        return ans;
    }
};

/* Approach 2: Two Pointers (Space Optimized) */
class SolutionTwoPointers {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        int i = 0, j = n - 1;
        int lm = 0, rm = 0;
        int ans = 0;

        while (i <= j) {
            if (v[i] <= v[j]) {
                if (v[i] >= lm) {
                    lm = v[i];
                } else {
                    ans += lm - v[i];
                }
                i++;
            } else {
                if (v[j] >= rm) {
                    rm = v[j];
                } else {
                    ans += rm - v[j];
                }
                j--;
            }
        }

        return ans;
    }
};