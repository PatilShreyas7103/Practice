// Candy

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Give each child at least 1 candy.
- Left to right: if rating increases, give more than left neighbor.
- Right to left: if rating decreases, ensure more than right neighbor.
*/

class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();
        vector<int> candies(n, 1);

        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] > v[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int total = 0;
        for (int c : candies) {
            total += c;
        }

        return total;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/