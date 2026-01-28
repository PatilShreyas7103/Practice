// Valid Parenthesis String

#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
/*
Approach 1: Brute Force (Recursion)
- Try all possibilities for '*': '(' , ')' , empty
- Track open brackets count
- Exponential time → TLE for large input
*/
class BruteForce {
public:
    bool dfs(string &s, int i, int open) {
        if (open < 0) return false;
        if (i == s.size()) return open == 0;

        if (s[i] == '(')
            return dfs(s, i + 1, open + 1);
        else if (s[i] == ')')
            return dfs(s, i + 1, open - 1);
        else
            return dfs(s, i + 1, open) ||
                   dfs(s, i + 1, open + 1) ||
                   dfs(s, i + 1, open - 1);
    }

    bool checkValidString(string s) {
        return dfs(s, 0, 0);
    }
};
/*
Time Complexity: O(3^n)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
/*
Approach 2: DP (Memoization)
- Same recursion but store states (index, open)
- Avoid recomputation
- Still heavy but better than brute force
*/
class DPApproach {
public:
    map<pair<int,int>, bool> dp;

    bool dfs(string &s, int i, int open) {
        if (open < 0) return false;
        if (i == s.size()) return open == 0;

        if (dp.count({i, open}))
            return dp[{i, open}];

        bool res;
        if (s[i] == '(')
            res = dfs(s, i + 1, open + 1);
        else if (s[i] == ')')
            res = dfs(s, i + 1, open - 1);
        else
            res = dfs(s, i + 1, open) ||
                  dfs(s, i + 1, open + 1) ||
                  dfs(s, i + 1, open - 1);

        return dp[{i, open}] = res;
    }

    bool checkValidString(string s) {
        return dfs(s, 0, 0);
    }
};
/*
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

/*------------------------------------------------------*/
/*
Approach 3: Greedy (Optimal)
- Track minimum and maximum possible open brackets
- '*' expands the range
- No recursion or stack
*/
class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            }
            else if (c == ')') {
                minOpen--;
                maxOpen--;
            }
            else { // '*'
                minOpen--;
                maxOpen++;
            }

            if (maxOpen < 0) return false;
            minOpen = max(minOpen, 0);
        }

        return minOpen == 0;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/