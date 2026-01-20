// Recursively Remove Adjacent Duplicates
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force (Recursive Simulation)
// Idea:
// - Scan the string and remove adjacent duplicates in one pass
// - If any removal happened, recursively process the new string
// - Continue until no adjacent duplicates remain
// NOTE: Simple to understand but inefficient
class BruteForce {
public:
    string removeDuplicates(string s) {
        bool changed = false;
        string temp = "";

        for (int i = 0; i < s.size(); ) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) j++;

            if (j - i == 1) {
                temp += s[i];
            } else {
                changed = true;
            }
            i = j;
        }

        if (!changed) return temp;
        return removeDuplicates(temp);
    }
};

/*
Time Complexity: O(n^2) (in worst case due to repeated scans)
Space Complexity: O(n) (recursion + temporary strings)
*/

/*------------------------------------------------------*/
// Approach 2: Stack-Based (Optimal)
// Idea:
// - Use stack to keep track of characters
// - If current character equals stack top → pop (remove duplicate)
// - Else push current character
// - Stack naturally handles recursive removal effect
// - Build result from stack at the end
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();   // remove adjacent duplicate
            } else {
                st.push(c);
            }
        }

        // build result from stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/