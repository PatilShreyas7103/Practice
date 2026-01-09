// ROTATE ARRAY

#include <bits/stdc++.h>
using namespace std;


// === EXTRA SPACE APPROACH ===
// Time: O(n), Space: O(n)
// Creates new array with rotated elements

class SolutionExtraSpace {
public:
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        if (k == 0 || n == 0) return;
        k %= n;
        
        vector<int> ans;
        for (int i = n - k; i < n; i++) {
            ans.push_back(v[i]);
        }
        for (int i = 0; i < n - k; i++) {
            ans.push_back(v[i]);
        }
        v = ans;
    }
};

// === REVERSE APPROACH ===
// Time: O(n), Space: O(1)
// Three reverses: prefix, suffix, whole array

class SolutionReverse {
public:
    void rev(vector<int>& v, int i, int j) {
        while (i < j) {
            swap(v[i++], v[j--]);
        }
    }
    
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        if (k == 0 || n <= 1) return;
        k %= n;
        
        rev(v, 0, n - k - 1);
        rev(v, n - k, n - 1);
        rev(v, 0, n - 1);
    }
};
