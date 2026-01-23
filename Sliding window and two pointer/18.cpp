// Permutation in String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string a, string b) {
        int m = a.size(), n = b.size();
        if (m > n) return false;

        vector<int> freqA(26, 0), freqB(26, 0);

        // Frequency of string a and first window of b
        for (int i = 0; i < m; i++) {
            freqA[a[i] - 'a']++;
            freqB[b[i] - 'a']++;
        }

        // Check first window
        if (freqA == freqB) return true;

        // Sliding window over string b
        for (int i = m; i < n; i++) {
            freqB[b[i] - 'a']++;          // add new character
            freqB[b[i - m] - 'a']--;      // remove old character

            if (freqA == freqB)
                return true;
        }

        return false;
    }
};

/*
Approach:
- A permutation means both strings have the same character frequency
- Maintain a sliding window of size |a| in string b
- Compare frequency arrays at each step
- If they match, permutation exists

Time Complexity:
- O(n)  (each character processed once)

Space Complexity:
- O(1)  (fixed 26-size frequency arrays)
*/