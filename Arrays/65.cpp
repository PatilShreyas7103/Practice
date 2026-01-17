// Max Absolute Difference 
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class BruteForce {
public:
    int maxArr(vector<int> &v) {
        int n = v.size();
        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int val = abs(v[i] - v[j]) + abs(i - j);
                mx = max(mx, val);
            }
        }
        return mx;
    }
};

// Optimal Approach
class Optimal {
public:
    int maxArr(vector<int> &v) {
        int n = v.size();
        int max1 = INT_MIN, min1 = INT_MAX;
        int max2 = INT_MIN, min2 = INT_MAX;

        for (int i = 0; i < n; i++) {
            max1 = max(max1, v[i] + i);
            min1 = min(min1, v[i] + i);
            max2 = max(max2, v[i] - i);
            min2 = min(min2, v[i] - i);
        }

        return max(max1 - min1, max2 - min2);
    }
};