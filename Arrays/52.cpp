// Longest Common Prefix

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Approach: Sorting
- Sort the array of strings
- Compare only the first and last strings
- Their common prefix is the answer
Time: O(N log N)
Space: O(1)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        sort(str.begin(), str.end());

        string first = str[0];
        string last = str[n - 1];
        int len = min(first.length(), last.length());

        string ans = "";

        for (int i = 0; i < len; i++) {
            if (first[i] != last[i])
                return ans;
            ans += first[i];
        }

        return ans;
    }
};