// Longest Substring with At Least K Repeating Characters
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force (Conceptual / TLE)
// Idea:
// - Generate all substrings
// - For each substring, count frequency of characters
// - Check if every character has frequency >= k
// - Track maximum length
// NOTE: This approach is too slow and not used in practice
class BruteForce {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                bool valid = true;
                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0 && freq[c] < k) {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n^3)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 2: Divide & Conquer (Optimal & Expected)
// Idea:
// - Count frequency of characters in the string
// - Any character with frequency < k cannot be part of valid substring
// - Split the string at such characters
// - Recursively solve for left and right substrings
// - Take the maximum result
class Solution {
public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }

private:
    int solve(string &s, int start, int end, int k) {
        if (end - start < k) return 0;

        vector<int> freq(26, 0);
        for (int i = start; i < end; i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = start; i < end; i++) {
            if (freq[s[i] - 'a'] < k) {
                int left = solve(s, start, i, k);
                int right = solve(s, i + 1, end, k);
                return max(left, right);
            }
        }

        // All characters have frequency >= k
        return end - start;
    }
};

/*
Time Complexity: O(n log n) (average)
Space Complexity: O(log n) (recursion stack)
*/