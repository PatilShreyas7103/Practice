// Remove Element

#include <vector>
using namespace std;

/*
Approach: Two Pointers (Overwrite Method)
- Use one pointer to track position of valid elements
- Traverse array and copy elements not equal to val
- Return length of updated array
Time: O(N)
Space: O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int idx = 0;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] != val) {
                v[idx++] = v[i];
            }
        }

        return idx;
    }
};