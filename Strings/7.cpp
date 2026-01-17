// Reverse Words in a String 
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Idea:
// - Extract words ignoring extra spaces
// - Store them in a vector
// - Reverse the vector
// - Join words with single space
class BruteForce {
public:
    string reverseWords(string s) {
        vector<string> v;
        int n = s.length();
        int i = 0;

        // skip leading spaces
        while (i < n && s[i] == ' ') i++;

        string curr = "";
        while (i < n) {
            if (s[i] != ' ') {
                curr += s[i];
            } else {
                if (!curr.empty()) {
                    v.push_back(curr);
                    curr = "";
                }
            }
            i++;
        }
        if (!curr.empty()) v.push_back(curr);

        reverse(v.begin(), v.end());

        string ans = "";
        for (auto &w : v) {
            ans += w + " ";
        }
        ans.pop_back(); // remove last space

        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/


// Optimal Approach (In-place)
// Idea:
// 1. Reverse entire string
// 2. Reverse each word individually
// 3. Remove extra spaces while rebuilding string
class Optimal {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();

        int left = 0, right = 0, i = 0;

        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') i++;
            if (i == n) break;

            // copy word
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // reverse current word
            reverse(s.begin() + left, s.begin() + right);

            // add space
            s[right++] = ' ';
            left = right;
            i++;
        }

        s.resize(right - 1); // remove trailing space
        return s;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/