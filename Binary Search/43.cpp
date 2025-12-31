// K-diff Pairs in an Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& v, int x) {
        int n = v.size();
        sort(v.begin(), v.end());
        int ans = 0;

        int i = 0, j = 1;
        while (i < n && j < n) {
            if (i == j) {
                j++;
                continue;
            }

            // skip duplicate i values
            if (i > 0 && v[i] == v[i - 1]) {
                i++;
                continue;
            }

            int diff = v[j] - v[i];

            if (diff == x) {
                ans++;
                i++;          // move i to ensure uniqueness
            }
            else if (diff < x) {
                j++;
            }
            else {
                i++;
            }
        }
        return ans;
    }
};