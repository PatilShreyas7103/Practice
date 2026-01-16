// Maximum Gap 
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class BruteForce {
public:
    int maximumGap(const vector<int> &v) {
        int n = v.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i] <= v[j]) {
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }
};

// Optimal Approach (Prefix Min + Suffix Max)
class Optimal {
public:
    int maximumGap(const vector<int> &v) {
        int n = v.size();
        if (n == 0) return 0;

        vector<int> leftMin(n), rightMax(n);

        leftMin[0] = v[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], v[i]);
        }

        rightMax[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], v[i]);
        }

        int i = 0, j = 0, ans = 0;
        while (i < n && j < n) {
            if (leftMin[i] <= rightMax[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};