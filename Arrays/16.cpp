// Rearrange Array by Sign (Positive at Even, Negative at Odd Indices)

#include <vector>
using namespace std;

/*
Approach: Index Placement
- Create a new array of same size
- Place positive numbers at even indices (0, 2, 4, ...)
- Place negative numbers at odd indices (1, 3, 5, ...)
- Guaranteed equal number of positives and negatives
Time: O(N)
Space: O(N)
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n);

        int pos = 0, neg = 1;

        for (int x : v) {
            if (x > 0) {
                ans[pos] = x;
                pos += 2;
            } else {
                ans[neg] = x;
                neg += 2;
            }
        }

        return ans;
    }
};