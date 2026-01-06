// Decode String

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Stack-based Decoding
Time: O(n)
Space: O(n)

Idea:
- Push every character as a string onto the stack.
- When ']' is encountered:
  - Pop till '[' to form the substring.
  - Pop digits to form the repeat count.
  - Repeat the substring and push back.
- Final stack content is reversed to form the answer.
*/
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans = "";
        stack<string> st;
        int i = 0;

        while (i < n) {
            if (s[i] == ']') {
                string temp = "";
                while (!st.empty() && st.top() != "[") {
                    temp += st.top();
                    st.pop();
                }
                st.pop(); // pop "["

                string num = "";
                while (!st.empty() && st.top() >= "0" && st.top() <= "9") {
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());

                int val = 0;
                int id = 0;
                while (id < num.length()) {
                    val = val * 10 + (num[id] - '0');
                    id++;
                }

                string p = "";
                for (int k = 1; k <= val; k++) {
                    p += temp;
                }
                st.push(p);
            } 
            else {
                string temp = "";
                temp += s[i];
                st.push(temp);
            }
            i++;
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};