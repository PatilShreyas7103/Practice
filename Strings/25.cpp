// Greatest Common Divisor of Strings
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force (Prefix Checking)
// Idea:
// - Try all prefixes of the smaller string
// - A prefix is valid if repeating it forms both strings exactly
// - Keep updating the longest valid prefix
class BruteForce {
public:
    bool isValid(string base, string s) {
        int len = base.size();
        if (s.size() % len != 0) return false;

        string formed = "";
        for (int i = 0; i < s.size() / len; i++) {
            formed += base;
        }
        return formed == s;
    }

    string gcdOfStrings(string s, string t) {
        string res = "";
        int n = min(s.size(), t.size());

        for (int i = 1; i <= n; i++) {
            string candidate = s.substr(0, i);
            if (isValid(candidate, s) && isValid(candidate, t)) {
                res = candidate;
            }
        }
        return res;
    }
};

/*
Time Complexity: O(n³) (substring + repetition)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
// Approach 2: Optimal (GCD Length Property)
// Idea:
// - If s + t != t + s → no common divisor string
// - Otherwise, length of answer = gcd(len(s), len(t))
// - Answer is prefix of that length

// Greatest Common Divisor of Strings
class Solution {
public:
    string gcdOfStrings(string s, string t) {
        if (s + t != t + s) return "";

        // int g = gcd(s.size(), t.size());
        // return s.substr(0, g);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/