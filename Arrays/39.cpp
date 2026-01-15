// Remove Duplicates from Sorted Array II

#include <vector>
using namespace std;

/*
Approach: Two Pointers (Allow At Most Two Occurrences)
- Maintain a pointer `id` for the position to place valid elements
- Allow element if:
  1) It is different from the previous element
  2) Or it is equal but previous two elements are different
Time: O(N)
Space: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size();
        if (n <= 2)
            return n;

        int id = 1;

        for (int i = 2; i < n; i++) {
            if (v[i] != v[id] || v[i] != v[id - 1]) {
                id++;
                v[id] = v[i];
            }
        }

        return id + 1;
    }
};