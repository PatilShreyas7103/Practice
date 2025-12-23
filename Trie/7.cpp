// Power Set of string -> Print all subsequences

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getSubsequences(string s) {
        int n = s.size();
        int total = 1 << n;
        vector<string> subsequences;

        for (int mask = 0; mask < total; mask++) {
            string current = "";
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    current += s[i];
                }
            }
            subsequences.push_back(current);
        }

        return subsequences;
    }
};

int main() {
    string s = "abc";
    Solution sol;

    vector<string> result = sol.getSubsequences(s);

    for (auto &str : result) {
        cout << "\"" << str << "\"" << endl;
    }

    return 0;
}