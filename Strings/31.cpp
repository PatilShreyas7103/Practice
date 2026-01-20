// Permutations of a String
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Backtracking with Sorting (Optimal)
// Idea:
// - Sort the string to bring duplicates together
// - Use visited array to track used characters
// - Skip duplicate characters during recursion
// - This avoids using a set and reduces extra work
class Solution {
public:
    void solve(string &s, vector<int> &vis, string curr, vector<string> &res) {
        if (curr.size() == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (vis[i]) continue;

            // skip duplicates
            if (i > 0 && s[i] == s[i - 1] && !vis[i - 1])
                continue;

            vis[i] = 1;
            solve(s, vis, curr + s[i], res);
            vis[i] = 0;
        }
    }

    vector<string> findPermutation(string &s) {
        sort(s.begin(), s.end());

        vector<string> res;
        vector<int> vis(s.size(), 0);

        solve(s, vis, "", res);
        return res;
    }
};

/*
Time Complexity: O(n! * n)
Space Complexity: O(n)
*/