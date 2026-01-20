// Valid Palindrome
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Two-Pointer (Optimal, O(1) Space)
// Idea:
// - Use two pointers from start and end
// - Skip non-alphanumeric characters
// - Convert uppercase letters to lowercase
// - Compare characters until pointers cross
class Optimal {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            // skip non-alphanumeric from left
            while (i < j && !isalnum(s[i])) i++;
            // skip non-alphanumeric from right
            while (i < j && !isalnum(s[j])) j++;

            // compare after normalizing case
            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }
        return true;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 2: Build Clean String + Check
// Idea:
// - Build a new string containing only lowercase letters and digits
// - Check if the resulting string is a palindrome
class ExtraSpace {
public:
    bool isPalindrome(string s) {
        string temp = "";

        for (char c : s) {
            if (isalnum(c)) {
                temp += tolower(c);
            }
        }

        int i = 0, j = temp.size() - 1;
        while (i < j) {
            if (temp[i] != temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/