// First Non-Repeating Character in a Stream

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Queue + Frequency Map
Time: O(n)
Space: O(n)

Idea:
- Use a queue to maintain order of characters.
- Use a frequency map to track counts.
- Remove repeating characters from queue front.
*/
class Solution {
public:
    string solve(string A) {
        unordered_map<char, int> freq;
        queue<char> q;
        string ans = "";

        for (char ch : A) {
            freq[ch]++;
            q.push(ch);

            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }

            if (q.empty()) {
                ans += '#';
            } else {
                ans += q.front();
            }
        }
        return ans;
    }
};