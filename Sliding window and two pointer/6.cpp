// Number of Substrings Containing All Three Characters
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Fix a starting index i
// - Expand j until we see at least one 'a', 'b', and 'c'
// - Once found, all substrings ending from j to n-1 are valid
// - Add (n - j) to answer and break
class BruteForce {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            bool hasA = false, hasB = false, hasC = false;

            for (int j = i; j < n; j++) {
                if (s[j] == 'a') hasA = true;
                else if (s[j] == 'b') hasB = true;
                else if (s[j] == 'c') hasC = true;

                if (hasA && hasB && hasC) {
                    ans += n - j;
                    break;
                }
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 2: Sliding Window (Optimal & Expected)
// Idea:
// - Maintain a sliding window [l..r]
// - Track frequencies of 'a', 'b', 'c'
// - When window contains all three characters:
//   * Any extension to the right is also valid
//   * So add (n - r) to answer
// - Shrink window from the left to find smaller valid windows
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0, ans = 0;
        unordered_map<char, int> mp;

        for (int r = 0; r < n; r++) {
            mp[s[r]]++;

            while (mp.size() == 3) {
                ans += n - r;

                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1) (only 3 characters)
*/