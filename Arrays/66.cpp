// Maximum Unsorted Subarray 
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Idea:
// - Make a sorted copy of the array
// - Compare original and sorted arrays
// - The first and last indices where they differ form the answer
class BruteForce {
public:
    vector<int> subUnsort(vector<int> &v) {
        int n = v.size();
        vector<int> a = v;
        sort(a.begin(), a.end());

        int st = -1, e = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] != v[i]) {
                if (st == -1) st = i;
                e = i;
            }
        }

        if (st == -1) return {-1};
        return {st, e};
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/


// Optimal Approach
// Idea:
// 1. Find first index from left where order breaks (v[i] > v[i+1])
// 2. Find first index from right where order breaks (v[i] < v[i-1])
// 3. Find min and max in this subarray
// 4. Expand boundaries if needed to include misplaced elements
class Optimal {
public:
    vector<int> subUnsort(vector<int> &v) {
        int n = v.size();
        int l = -1, r = -1;

        // Step 1: find left boundary
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                l = i;
                break;
            }
        }

        if (l == -1) return {-1}; // already sorted

        // Step 2: find right boundary
        for (int i = n - 1; i > 0; i--) {
            if (v[i] < v[i - 1]) {
                r = i;
                break;
            }
        }

        // Step 3: find min and max in [l, r]
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = l; i <= r; i++) {
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);
        }

        // Step 4: expand boundaries
        while (l > 0 && v[l - 1] > mn) l--;
        while (r < n - 1 && v[r + 1] < mx) r++;

        return {l, r};
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/