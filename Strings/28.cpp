// Restore IP Addresses
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach: Backtracking (DFS)
// Idea:
// - We need to split the string into exactly 4 parts (A.B.C.D)
// - Each part:
//   * Length between 1 and 3
//   * Value between 0 and 255
//   * No leading zero unless the part is exactly "0"
// - Use DFS to try all segment lengths (1 to 3)
// - Keep track of how many parts (dots) we have used
// - When 4 parts are formed and the string is fully consumed,
//   add the IP to the answer
class Solution {
public:
    void dfs(int idx, int dots, string &s, string curr, vector<string> &ans) {
        int n = s.size();

        // Valid IP: exactly 4 parts and all characters used
        if (dots == 4 && idx == n) {
            curr.pop_back();               // remove trailing '.'
            ans.push_back(curr);
            return;
        }

        // Invalid cases
        if (dots == 4 || idx == n) return;

        // Try segment lengths 1 to 3
        for (int len = 1; len <= 3 && idx + len <= n; len++) {
            string part = s.substr(idx, len);
            int val = stoi(part);

            // Check range and leading zero rule
            if (val <= 255 && (part.size() == 1 || part[0] != '0')) {
                dfs(idx + len, dots + 1, s, curr + part + ".", ans);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.size();

        // Length pruning: valid IP needs 4 to 12 digits
        if (n < 4 || n > 12) return ans;

        dfs(0, 0, s, "", ans);
        return ans;
    }
};

/*
Time Complexity: O(3^4) ≈ O(1)
Reason: At most 3 choices for each of the 4 segments
Space Complexity: O(1) extra (excluding output)
*/