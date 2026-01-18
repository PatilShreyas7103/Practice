// Merge Strings Alternately
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Two-Pointer (Optimal & Clear)
// Idea:
// - Use two pointers i and j for strings a and b
// - Alternately append characters while both pointers are valid
// - Append remaining characters from the longer string
class Optimal {
public:
    string mergeAlternately(string a, string b) {
        string ans = "";
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            ans += a[i++];
            ans += b[j++];
        }

        while (i < a.size()) {
            ans += a[i++];
        }

        while (j < b.size()) {
            ans += b[j++];
        }

        return ans;
    }
};

/*
Time Complexity: O(m + n)
Space Complexity: O(1) extra (excluding output)
*/

/*------------------------------------------------------*/
// Approach 2: Single Loop (Alternative)
// Idea:
// - Iterate from 0 to max(lengths)
// - If index exists in a, append a[i]
// - If index exists in b, append b[i]
class SingleLoop {
public:
    string mergeAlternately(string a, string b) {
        string ans = "";
        int m = a.size(), n = b.size();

        for (int i = 0; i < max(m, n); i++) {
            if (i < m) ans += a[i];
            if (i < n) ans += b[i];
        }

        return ans;
    }
};

/*
Time Complexity: O(m + n)
Space Complexity: O(1) extra (excluding output)
*/