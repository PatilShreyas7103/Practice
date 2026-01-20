// First Unique Character in a String
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - For every character, count its frequency by scanning the whole string
// - First character whose frequency is 1 is the answer
class BruteForce {
public:
    int firstUniqChar(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (s[i] == s[j]) cnt++;
            }
            if (cnt == 1) return i;
        }
        return -1;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 2: Hashing with Map (Your Approach)
// Idea:
// - Count frequency of each character using hashmap
// - Traverse string again to find first char with frequency 1
class HashMapApproach {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;

        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
// Approach 3: Optimal using Fixed-Size Array
// Idea:
// - Since characters are lowercase English letters
// - Use array of size 26 instead of hashmap
class Optimal {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
