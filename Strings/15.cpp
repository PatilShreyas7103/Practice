// Minimum Reversals to Balance Parentheses
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Brute Force Approach (Using Stack)
// Idea:
// - Use stack to remove already balanced pairs
// - Remaining stack contains unbalanced brackets
// - Count minimum reversals needed from remaining length
class BruteForce {
public:
    int minReversalsToBalance(string s) {
        int n = s.length();
        if (n % 2 != 0) return -1;

        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }

        int open = 0, close = 0;
        while (!st.empty()) {
            if (st.top() == '(') open++;
            else close++;
            st.pop();
        }

        return (open + 1) / 2 + (close + 1) / 2;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
// Optimal Approach (Counting Without Stack)
// Idea:
// - Count unmatched '(' and ')'
// - '(' increases open count
// - ')' cancels '(' if possible, else increases close count
// - Use formula to compute minimum reversals
class Optimal {
public:
    int minReversalsToBalance(string s) {
        int openBrackets = 0;
        int closeBrackets = 0;

        for (char ch : s) {
            if (ch == '(') {
                openBrackets++;
            } else {
                if (openBrackets > 0) {
                    openBrackets--;
                } else {
                    closeBrackets++;
                }
            }
        }

        if ((openBrackets + closeBrackets) % 2 != 0)
            return -1;

        return (openBrackets + 1) / 2 + (closeBrackets + 1) / 2;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/