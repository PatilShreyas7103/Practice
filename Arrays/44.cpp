// Candy

#include <vector>
#include <algorithm>
using namespace std;

/*
Approach: Two Pass Greedy
- Give each child at least 1 candy
- Left to right: if rating increases, give more candies than left neighbor
- Right to left: if rating decreases, fix candies using max()
- Sum all candies
Time: O(N)
Space: O(N)
*/
class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        int total = candies[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (v[i] > v[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            total += candies[i];
        }

        return total;
    }
};