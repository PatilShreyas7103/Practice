// Print all LCS of two strings

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;
class Solution {
public:
    void backtrack(int i, int j, string &s1, string &s2,
                   vector<vector<int>> &dp,
                   string curr,
                   set<string> &ans) {

        if (i == 0 || j == 0) {
            reverse(curr.begin(), curr.end());
            ans.insert(curr);
            return;
        }

        if (s1[i - 1] == s2[j - 1]) {
            backtrack(i - 1, j - 1, s1, s2, dp,
                      curr + s1[i - 1], ans);
        } else {
            if (dp[i - 1][j] == dp[i][j]) {
                backtrack(i - 1, j, s1, s2, dp, curr, ans);
            }
            if (dp[i][j - 1] == dp[i][j]) {
                backtrack(i, j - 1, s1, s2, dp, curr, ans);
            }
        }
    }

    vector<string> allLCS(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        set<string> ans;
        vector<string> res;
        backtrack(n, m, s1, s2, dp, "", ans);
        for(auto it: ans)
        {
            res.push_back(it);
        }
        
        return res;
    }
};
