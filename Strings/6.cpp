// Remove Outermost Parentheses 
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach (Using Stack)
// Idea:
// - Use a stack to track parentheses depth
// - Skip adding '(' when stack is empty (outermost)
// - Skip adding ')' when stack size is 1 (closing outermost)
class BruteForce {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;

        for (char it : s) {
            if (it == '(') {
                if (!st.empty()) ans += '(';
                st.push('(');
            } else {
                st.pop();
                if (!st.empty()) ans += ')';
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/


// Optimal Approach (Counter instead of Stack)
// Idea:
// - Maintain depth counter
// - When depth > 0, '(' is not outer → include
// - When depth > 1, ')' is not outer → include
class Optimal {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char it : s) {
            if (it == '(') {
                if (depth > 0) ans += '(';
                depth++;
            } else {
                depth--;
                if (depth > 0) ans += ')';
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/