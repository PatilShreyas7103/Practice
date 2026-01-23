// Valid Palindrome II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check palindrome in substring [l, r]
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    // Main function
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                // We are allowed to delete at most ONE character
                // Try skipping either left or right character
                return isPalindrome(s, l + 1, r) ||
                       isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
    }
};

/*
Approach:
- Use two pointers from both ends
- If characters match → move inward
- On first mismatch:
    - Try deleting left character
    - OR try deleting right character
- If either remaining substring is palindrome → true

Time Complexity:
- O(n)
  (At most one extra palindrome check)

Space Complexity:
- O(1)
*/