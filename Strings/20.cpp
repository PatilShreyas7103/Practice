// Minimum Window Substring (Brute Force + Optimal)
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Brute Force Approach (Conceptual)
// Idea:
// - Generate all substrings of s
// - For each substring, check if it contains all chars of t with frequency
// - Track minimum length substring
// NOTE: This will TLE for large inputs, used only for understanding
class BruteForce { 
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int minLen = INT_MAX;
        string ans = "";

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                if (isValid(freq, need)) {
                    if (j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                    break; // no smaller window starting at i
                }
            }
        }
        return ans;
    }

private:
    bool isValid(unordered_map<char, int> &freq,
                 unordered_map<char, int> &need) {
        for (auto &it : need) {
            if (freq[it.first] < it.second)
                return false;
        }
        return true;
    }
};

/*
Time Complexity: O(n³)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Optimal Approach (Sliding Window)
// Idea:
// - Use two pointers (left, right)
// - Expand right to include required characters
// - When window is valid, try to shrink from left
// - Track minimum window length

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/