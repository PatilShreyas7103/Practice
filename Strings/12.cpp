// Maximum Nesting Depth of Parentheses 
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Stack Based
// Idea:
// - Push '(' onto stack
// - Stack size represents current depth
// - Track maximum stack size
class StackApproach {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
                ans = max(ans, (int)st.size());
            } else if (c == ')') {
                st.pop();
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
// Approach 2: Counter Based (Optimal)
// Idea:
// - Increment counter for '('
// - Decrement for ')'
// - Track maximum counter value
class Optimal {
public:
    int maxDepth(string s) {
        int dep = 0, ans = 0;

        for (char c : s) {
            if (c == '(') {
                dep++;
                ans = max(ans, dep);
            } else if (c == ')') {
                dep--;
            }
        }
        return ans;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/