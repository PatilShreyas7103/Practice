// Maximum Number of Vowels in a Substring of Given Length
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Helper function
bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u');
}

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - For every substring of length k
// - Count number of vowels
// - Track maximum count
class BruteForce {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i + k <= n; i++) {
            int cnt = 0;
            for (int j = i; j < i + k; j++) {
                if (isVowel(s[j]))
                    cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

/*
Time Complexity: O(n * k)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 2: Sliding Window (Optimal & Expected)
// Idea:
// - Count vowels in the first window of size k
// - Slide the window:
//   * add right character
//   * remove left character
// - Update maximum vowels count
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;

        // first window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                cnt++;
        }

        int ans = cnt;

        // slide the window
        for (int i = k; i < n; i++) {
            if (isVowel(s[i]))
                cnt++;
            if (isVowel(s[i - k]))
                cnt--;
            ans = max(ans, cnt);
        }

        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/