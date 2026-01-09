// FIND SECOND LARGEST ELEMENT IN ARRAY

#include <bits/stdc++.h>
using namespace std;

// === SORTING APPROACH ===
// Time: O(n log n), Space: O(1)

class SolutionSort {
public:
    int getSecondLargest(vector<int>& v) {
        int n = v.size();
        if (n < 2) return -1;
        
        sort(v.begin(), v.end());
        int mx = v[n-1];
        
        for (int i = n-2; i >= 0; i--) {
            if (v[i] != mx) return v[i];
        }
        return -1;
    }
};

// === OPTIMAL O(n) APPROACH ===
// Time: O(n), Space: O(1)

class SolutionOptimal {
public:
    int getSecondLargest(vector<int>& v) {
        int n = v.size();
        if (n < 2) return -1;
        
        int mx = INT_MIN, sec = INT_MIN;
        
        for (int num : v) {
            if (num > mx) {
                sec = mx;
                mx = num;
            } else if (num > sec && num < mx) {
                sec = num;
            }
        }
        return sec;
    }
};
