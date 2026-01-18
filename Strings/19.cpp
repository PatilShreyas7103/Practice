// Compare Version Numbers
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Optimal Approach (Two-Pointer, No Overflow)
// Idea:
// - Traverse both strings simultaneously
// - Extract number between dots using pointers
// - Compare immediately
// - Ignore leading zeros automatically
class Optimal {
public:
    int compareVersion(string s, string t) {
        int m = s.length(), n = t.length();
        int i = 0, j = 0;

        while (i < m || j < n) {
            long long num1 = 0, num2 = 0;

            // parse s
            while (i < m && s[i] != '.') {
                num1 = num1 * 10 + (s[i] - '0');
                i++;
            }

            // parse t
            while (j < n && t[j] != '.') {
                num2 = num2 * 10 + (t[j] - '0');
                j++;
            }

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;

            i++;  // skip '.'
            j++;  // skip '.'
        }

        return 0;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/