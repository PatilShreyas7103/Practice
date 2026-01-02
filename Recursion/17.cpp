// Palindrome Partitioning

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(int idx, string &s,
               vector<string> &ans,
               vector<vector<string>> &res) {

        if (idx == s.size()) {
            res.push_back(ans);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                ans.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, ans, res);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        solve(0, s, ans, res);
        return res;
    }
};