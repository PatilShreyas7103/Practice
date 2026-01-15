// Can Place Flowers

#include <vector>
using namespace std;

/*
Approach: Greedy Placement
- Traverse the flowerbed
- If current spot and neighbors are empty, place a flower
- Reduce count and stop early if all flowers are placed
Time: O(N)
Space: O(1)
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int sz = v.size();

        if (n == 0)
            return true;

        for (int i = 0; i < sz; i++) {
            if (v[i] == 1)
                continue;

            bool safe = true;

            if (i > 0 && v[i - 1] == 1)
                safe = false;

            if (i < sz - 1 && v[i + 1] == 1)
                safe = false;

            if (safe) {
                v[i] = 1;
                n--;
            }

            if (n == 0)
                return true;
        }

        return false;
    }
};