// Largest Odd Number in String 
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Idea:
// - Check every prefix of the string
// - Convert last character of prefix to digit
// - If it is odd, update answer
class BruteForce {
public:
    string largestOddNumber(string s) {
        int n = s.length();
        string ans = "";

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            if (digit % 2 == 1) {
                ans = s.substr(0, i + 1);
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n²)  (substring creation)
Space Complexity: O(1)
*/


// Optimal Approach
// Idea:
// - Traverse from the end
// - Find the rightmost odd digit
// - Return substring from 0 to that index
class Optimal {
public:
    string largestOddNumber(string s) {
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            if ((s[i] - '0') & 1) {
                return s.substr(0, i + 1);
            }
        }
        return "";
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/