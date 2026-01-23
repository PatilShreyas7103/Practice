// Boats to Save People
#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Sort the people by weight
- Use two pointers:
    * i -> lightest person
    * j -> heaviest person
- If lightest + heaviest <= limit, pair them
- Else, send heaviest alone
- Each iteration uses exactly one boat

Time Complexity:
- O(n log n) due to sorting

Space Complexity:
- O(1) extra space (ignoring sort space)
*/

class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        sort(v.begin(), v.end());

        int i = 0, j = v.size() - 1;
        int boats = 0;

        while (i <= j) {
            // If the lightest and heaviest can share a boat
            if (v[i] + v[j] <= limit) {
                i++;
                j--;
            }
            // Otherwise, heaviest goes alone
            else {
                j--;
            }
            boats++;
        }

        return boats;
    }
};

