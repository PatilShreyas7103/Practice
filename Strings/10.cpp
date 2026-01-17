// Rotate String 
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Idea:
// - Generate all rotations of string s
// - Compare each rotation with goal string g
class BruteForce {
public:
    bool rotateString(string s, string g) {
        int n = s.length();
        if (s.length() != g.length()) return false;

        for (int i = 0; i < n; i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            if (rotated == g) return true;
        }
        return false;
    }
};

/*
Time Complexity: O(n²)
Space Complexity: O(n)
*/


// Optimal Approach
// Idea:
// - A string g is a rotation of s if it is a substring of (s + s)
class Optimal {
public:
    bool rotateString(string s, string g) {
        if (s.length() != g.length()) return false;
        return (s + s).find(g) != string::npos;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/