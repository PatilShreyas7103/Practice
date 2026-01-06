// Simplify Path

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based Path Simulation
Time: O(n)
Space: O(n)

Idea:
- Split the path by '/'.
- Ignore "." (current directory).
- ".." means pop the last directory from stack (if exists).
- Valid directory names are pushed onto stack.
- Finally, rebuild the path from stack.
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "";

        for (char ch : path) {
            if (ch == '/') {
                if (curr == "..") {
                    if (!st.empty()) st.pop();
                } 
                else if (!curr.empty() && curr != ".") {
                    st.push(curr);
                }
                curr.clear();
            } else {
                curr.push_back(ch);
            }
        }

        // Handle last token
        if (curr == "..") {
            if (!st.empty()) st.pop();
        } 
        else if (!curr.empty() && curr != ".") {
            st.push(curr);
        }

        // Build result
        vector<string> dirs;
        while (!st.empty()) {
            dirs.push_back(st.top());
            st.pop();
        }
        reverse(dirs.begin(), dirs.end());

        string res;
        for (auto &dir : dirs) {
            res += "/" + dir;
        }

        return res.empty() ? "/" : res;
    }
};