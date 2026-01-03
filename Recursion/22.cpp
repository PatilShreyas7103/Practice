// Word Break II 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int n, string &s,
               unordered_set<string> &st,
               vector<string> &path,
               vector<string> &res) {

        if (i == n) {
            string temp = "";
            for (int k = 0; k < path.size(); k++) {
                temp += path[k];
                if (k + 1 < path.size()) temp += " ";
            }
            res.push_back(temp);
            return;
        }

        for (int j = i; j < n; j++) {
            string word = s.substr(i, j - i + 1);
            if (st.count(word)) {
                path.push_back(word);
                solve(j + 1, n, s, st, path, res);
                path.pop_back();
            }
        }
    }

    vector<string> wordBreakAll(string s, vector<string>& w) {
        int n = s.size();
        unordered_set<string> st(w.begin(), w.end());
        vector<string> path;
        vector<string> res;

        solve(0, n, s, st, path, res);
        return res;
    }
};