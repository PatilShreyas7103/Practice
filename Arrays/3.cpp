// Check if Array Is Sorted and Rotated

#include <bits/stdc++.h>
using namespace std;

// === CURRENT APPROACH FIX ===
// Time: O(n), Space: O(1)
// Counts violations, allows exactly 1 peak for rotated monotonic

class SolutionCurrent {
public:
    bool check(vector<int>& v) {
        int n = v.size();
        if (n <= 1) return true;
        
        int violations = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                violations++;
            }
        }
        
        if (v[0] < v[n - 1]) {
            violations++;
        }
        
        return violations <= 1;
    }
};
