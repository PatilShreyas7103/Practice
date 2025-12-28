// Book allocation problem

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int cap, vector<int>& v, int k) {
        int students = 1;
        int pages = 0;

        for (int x : v) {
            if (pages + x <= cap) {
                pages += x;
            } else {
                students++;
                pages = x;
            }
        }
        return students <= k;
    }

    int findPages(vector<int>& v, int k) {
        int n = v.size();
        if (k > n) return -1;

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