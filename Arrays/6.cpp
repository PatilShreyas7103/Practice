// MOVE ZEROS TO END

#include <bits/stdc++.h>
using namespace std;

// === TWO POINTERS APPROACH ===
// Time: O(n), Space: O(1)
// Single pass: non-zeros to front, zeros to end

class SolutionTwoPointers {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
        int id = 0;
        
        for (int i = 0; i < n; i++) {
            if (v[i] != 0) {
                v[id++] = v[i];
            }
        }
        for (int i = id; i < n; i++) {
            v[i] = 0;
        }
    }
};
