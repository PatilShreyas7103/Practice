// Add Binary
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach: Binary Addition using Carry
// Idea:
// - Traverse both strings from right to left
// - Add corresponding bits with carry
// - Append (sum % 2) to result
// - Update carry = sum / 2
// - Reverse the final string
class Solution {
public:
    string addBinary(string A, string B) {
        int i = A.size() - 1;
        int j = B.size() - 1;
        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += A[i--] - '0';
            if (j >= 0) sum += B[j--] - '0';

            ans += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Time Complexity: O(max(n, m))
Space Complexity: O(1) extra (excluding output)
*/