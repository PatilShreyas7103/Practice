// Word Pattern

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Split the string into words.
- Use two maps:
  char -> word and word -> char
- Ensure one-to-one mapping in both directions.
*/

class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> words;
        string curr = "";

        // Split string by spaces
        for (char ch : s) {
            if (ch == ' ') {
                words.push_back(curr);
                curr = "";
            } else {
                curr += ch;
            }
        }
        words.push_back(curr);

        if (words.size() != p.size()) return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < p.size(); i++) {
            char c = p[i];
            string w = words[i];

            if (mp1.count(c) && mp1[c] != w) return false;
            if (mp2.count(w) && mp2[w] != c) return false;

            mp1[c] = w;
            mp2[w] = c;
        }

        return true;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/