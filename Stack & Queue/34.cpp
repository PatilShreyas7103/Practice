// Removing Stars From a String

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based Simulation
Time: O(n)
Space: O(n)

Idea:
- Traverse the string character by character.
- If the character is '*', remove (pop) the last added character.
- Otherwise, push the character onto the stack.
- Finally, build the answer from the stack.
*/
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '*') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(ch);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};