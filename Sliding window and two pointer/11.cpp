// Find All Anagrams in a String
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - For each index i, take substring of length p
// - Check if it is an anagram using frequency array
// - Push index if anagram
class BruteForce {
public:
    bool isAnagram(string &s, string &t) {
        vector<int> freq(26, 0);

        for (char c : s) freq[c - 'a']++;
        for (char c : t) freq[c - 'a']--;

        for (int x : freq)
            if (x != 0) return false;

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> ans;

        for (int i = 0; i + n <= m; i++) {
            string sub = s.substr(i, n);
            if (isAnagram(sub, p))
                ans.push_back(i);
        }
        return ans;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 2: Sliding Window with Frequency Count (Optimal)
// Idea:
// - Maintain frequency array for p
// - Use sliding window of size p.length()
// - Add right char and remove left char from window
// - If frequency array matches, record index
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> ans;

        if (n > m) return ans;

        vector<int> freq(26, 0);
        for (char c : p)
            freq[c - 'a']++;

        int l = 0;

        for (int r = 0; r < m; r++) {
            freq[s[r] - 'a']--;

            if (r - l + 1 > n) {
                freq[s[l] - 'a']++;
                l++;
            }

            if (r - l + 1 == n) {
                bool ok = true;
                for (int x : freq) {
                    if (x != 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ans.push_back(l);
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/