// Implement strStr() 
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force (Substring Comparison)
// Idea:
// - For each index i in haystack
// - Compare substring of length needle with needle
class BruteForce {
public:
    int strStr(string h, string s) {
        int m = h.length();
        int n = s.length();

        if (n == 0) return 0;

        for (int i = 0; i + n <= m; i++) {
            if (h.substr(i, n) == s) {
                return i;
            }
        }
        return -1;
    }
};
/*
Time Complexity: O(n²)
Space Complexity: O(n) (due to substr)
*/

/*------------------------------------------------------*/
// Approach 2: Character-by-Character Matching (Optimized Brute)
// Idea:
// - Compare characters one by one without using substr
// - Break early on mismatch
class CharCompare {
public:
    int strStr(string h, string s) {
        int m = h.length();
        int n = s.length();

        if (n == 0) return 0;

        for (int i = 0; i + n <= m; i++) {
            int j = 0;
            while (j < n && h[i + j] == s[j]) {
                j++;
            }
            if (j == n) return i;
        }
        return -1;
    }
};
/*
Time Complexity: O(n²)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 3: Rabin–Karp (Rolling Hash)
// Idea:
// - Use rolling hash to compare substrings in O(1)
// - Verify on hash match to avoid collision
class RabinKarp {
public:
    int strStr(string h, string s) {
        int m = h.length();
        int n = s.length();
        if (n == 0) return 0;
        if (n > m) return -1;

        const long long base = 31;
        const long long mod = 1000000007;

        long long hashS = 0, hashH = 0, power = 1;

        for (int i = 0; i < n - 1; i++)
            power = (power * base) % mod;

        for (int i = 0; i < n; i++) {
            hashS = (hashS * base + s[i]) % mod;
            hashH = (hashH * base + h[i]) % mod;
        }

        for (int i = 0; i <= m - n; i++) {
            if (hashS == hashH) {
                if (h.substr(i, n) == s)
                    return i;
            }

            if (i < m - n) {
                hashH = (hashH - h[i] * power) % mod;
                if (hashH < 0) hashH += mod;
                hashH = (hashH * base + h[i + n]) % mod;
            }
        }
        return -1;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 4: KMP Algorithm (Best & Guaranteed Linear Time)
// Idea:
// - Precompute LPS array for needle
// - Avoid redundant comparisons
class KMP {
public:
    int strStr(string h, string s) {
        int m = h.length();
        int n = s.length();
        if (n == 0) return 0;

        vector<int> lps = buildLPS(s);

        for (int i = 0, j = 0; i < m; ) {
            if (h[i] == s[j]) {
                i++; j++;
                if (j == n) return i - j;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return -1;
    }

private:
    vector<int> buildLPS(string &s) {
        int n = s.length();
        vector<int> lps(n, 0);

        for (int i = 1, len = 0; i < n; ) {
            if (s[i] == s[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/