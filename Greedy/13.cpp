// Partition Labels

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Store the last occurrence index of each character.
- Traverse the string and extend the current partition
  to the farthest last occurrence seen so far.
- When current index reaches that farthest point,
  close the partition.
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> last(26, 0);

        // Last occurrence of each character
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0, end = 0;

        for (int i = 0; i < n; i++) {
            end = max(end, last[s[i] - 'a']);

            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/