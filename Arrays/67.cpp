// Perfect Peak 
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Idea:
// - For every element v[i], check:
//   * all elements to the left are smaller
//   * all elements to the right are greater
// - Skip first and last index
class BruteForce {
public:
    int perfectPeak(vector<int> &v) {
        int n = v.size();

        for (int i = 1; i < n - 1; i++) {
            bool ok = true;

            for (int l = 0; l < i; l++) {
                if (v[l] >= v[i]) {
                    ok = false;
                    break;
                }
            }

            for (int r = i + 1; r < n && ok; r++) {
                if (v[r] <= v[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return 1;
        }
        return 0;
    }
};

/*
Time Complexity: O(n²)
Space Complexity: O(1)
*/


// Optimal Approach
// Idea:
// 1. Build rightMin[i] = minimum element on the right of i
// 2. Maintain max element on the left while traversing
// 3. v[i] is a perfect peak if:
//    v[i] > leftMax AND v[i] < rightMin[i]
class Optimal {
public:
    int perfectPeak(vector<int> &v) {
        int n = v.size();
        vector<int> rightMin(n);

        int mn = v[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            rightMin[i] = mn;
            mn = min(mn, v[i]);
        }

        int mx = v[0];
        for (int i = 1; i < n - 1; i++) {
            if (v[i] > mx && v[i] < rightMin[i]) {
                return 1;
            }
            mx = max(mx, v[i]);
        }

        return 0;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/