// Excel Sheet Column Title

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Treat the number as base-26 but without zero.
- Use (n-1)%26 to get the current character.
- Reduce n using (n-1)/26 and repeat.
*/

class Solution {
public:
    string convertToTitle(int c) {
        string ans = "";

        while (c > 0) {
            int d = (c - 1) % 26;
            ans += char('A' + d);
            c = (c - 1) / 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Time Complexity: O(log₍26₎ n)
Space Complexity: O(1)
*/