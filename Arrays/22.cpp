// Spiral Order Traversal of Matrix

#include <vector>
using namespace std;

/*
Approach: Boundary Traversal
- Maintain four boundaries: top, bottom, left, right
- Traverse:
  1. Top row (left → right)
  2. Right column (top → bottom)
  3. Bottom row (right → left)
  4. Left column (bottom → top)
- Shrink boundaries after each traversal
- Stop when boundaries cross
Time: O(M * N)
Space: O(1) (excluding output array)
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<int> ans;

        int top = 0, bot = m - 1;
        int left = 0, right = n - 1;

        while (top <= bot && left <= right) {
            for (int i = left; i <= right; i++)
                ans.push_back(v[top][i]);
            top++;

            for (int i = top; i <= bot; i++)
                ans.push_back(v[i][right]);
            right--;

            if (top > bot || left > right)
                break;

            for (int i = right; i >= left; i--)
                ans.push_back(v[bot][i]);
            bot--;

            for (int i = bot; i >= top; i--)
                ans.push_back(v[i][left]);
            left++;
        }

        return ans;
    }
};