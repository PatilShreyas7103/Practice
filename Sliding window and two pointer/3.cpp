// Longest Repeating Character Replacement
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force (Conceptual)
// Idea:
// - Try all substrings
// - For each substring, count frequency of characters
// - Find the max frequency in substring
// - If (len - maxFreq) <= k → valid
// - Track maximum length
// NOTE: Too slow for large input
class BruteForce {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);

                if ((j - i + 1) - maxFreq <= k) {
                    ans = max(ans, j - i + 1);
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
// - Use two pointers (left, right)
// - Maintain frequency of characters in window
// - Track max frequency in the current window
// - If replacements needed > k, shrink from left
// - Window size - maxFreq gives required replacements
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // invalid window
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/