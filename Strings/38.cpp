// Add Strings
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach: Digit-by-Digit Addition (Optimal & Expected)
// Idea:
// - Start from the end of both strings
// - Add digits along with carry
// - Append (sum % 10) to result
// - Update carry = sum / 10
// - Reverse result at the end
class Solution {
public:
    string addStrings(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += s[i--] - '0';
            if (j >= 0) sum += t[j--] - '0';

            ans += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Time Complexity: O(max(m, n))
Space Complexity: O(1) extra (excluding output)
*/