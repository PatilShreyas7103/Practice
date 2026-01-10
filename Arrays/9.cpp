// Max Consecutive Ones

#include <vector>
using namespace std;

/*
Approach: Single Pass Counting
- Traverse the array once
- Maintain a counter for current consecutive 1s
- Reset counter when 0 appears
- Track the maximum length found
Time: O(N)
Space: O(1)
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int len = 0;
        int ans = 0;

        for (int x : v) {
            if (x == 1) {
                len++;
                ans = max(ans, len);
            } else {
                len = 0;
            }
        }

        return ans;
    }
};