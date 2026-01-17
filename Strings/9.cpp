// Isomorphic Strings
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Idea:
// - For each character in s, ensure it always maps to the same character in t
// - Do the reverse check as well (t -> s)
// - Two hash maps ensure one-to-one mapping
class BruteForce {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (mp1.count(s[i])) {
                if (mp1[s[i]] != t[i]) return false;
            } else {
                mp1[s[i]] = t[i];
            }

            if (mp2.count(t[i])) {
                if (mp2[t[i]] != s[i]) return false;
            } else {
                mp2[t[i]] = s[i];
            }
        }
        return true;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/


// Optimal Approach
// Idea:
// - Use fixed-size arrays instead of hash maps
// - Map characters by last seen positions
// - If last seen positions don’t match → not isomorphic
class Optimal {
public:
    bool isIsomorphic(string s, string t) {
        int lastS[256] = {0};
        int lastT[256] = {0};
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (lastS[s[i]] != lastT[t[i]]) {
                return false;
            }
            lastS[s[i]] = i + 1;
            lastT[t[i]] = i + 1;
        }
        return true;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/