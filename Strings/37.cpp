// Remove Duplicates from a String
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - For each character, check if it already appeared before
// - If not, include it in result
class BruteForce {
public:
    string removeDups(string &s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            bool found = false;
            for (int j = 0; j < i; j++) {
                if (s[i] == s[j]) {
                    found = true;
                    break;
                }
            }
            if (!found)
                ans += s[i];
        }
        return ans;
    }
};

/*
Time Complexity: O(n²)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 2: HashSet (Your Approach – Correct)
// Idea:
// - Insert all characters into a set
// - Traverse string again
// - Append character if it's still in set
// - Erase after first occurrence to maintain order
class HashSetApproach {
public:
    string removeDups(string &s) {
        unordered_set<char> st;
        for (char c : s)
            st.insert(c);

        string ans = "";
        for (char c : s) {
            if (st.find(c) != st.end()) {
                ans += c;
                st.erase(c);   // ensures only first occurrence is kept
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
// Approach 3: Optimal Array-Based (Best for lowercase chars)
// Idea:
// - Use boolean array of size 26
// - Track if character has already appeared
// - Preserves order and uses constant space
class Solution {
public:
    string removeDups(string &s) {
        vector<bool> seen(26, false);
        string ans = "";

        for (char c : s) {
            if (!seen[c - 'a']) {
                ans += c;
                seen[c - 'a'] = true;
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/