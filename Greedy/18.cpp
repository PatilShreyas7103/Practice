// Reverse Bits

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Iterate exactly 32 times.
- Extract the last bit of n.
- Place it in the correct reversed position.
*/

class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        int pos = 31;   // position in reversed number

        for (int i = 0; i < 32; i++) {
            int bit = n & 1;            // get last bit
            result |= (bit << pos);     // place it at correct position
            pos--;
            n >>= 1;                    // move to next bit
        }

        return result;
    }
};

/*
Time Complexity: O(32)
Space Complexity: O(1)
*/