// Count Substrings with Exactly K Distinct Characters
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Brute Force Approach
// Idea:
// - Fix starting index i
// - Extend substring to the right
// - Use a set to track distinct characters
// - If distinct count == k → count it
// - If distinct count > k → break
class BruteForce {
public:
    int countSubstr(string &s, int k) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = i; j < n; j++) {
                st.insert(s[j]);
                if (st.size() == k) ans++;
                else if (st.size() > k) break;
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n²)
Space Complexity: O(k)
*/

/*------------------------------------------------------*/
// Optimal Approach (Sliding Window)
// Idea:
// - Count substrings with at most k distinct characters
// - Answer = atMost(k) - atMost(k-1)
class Optimal {
public:
    int countSubstr(string &s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }

private:
    int atMostK(string &s, int k) {
        if (k < 0) return 0;

        vector<int> freq(26, 0);
        int i = 0, ans = 0, distinct = 0;

        for (int j = 0; j < s.length(); j++) {
            if (freq[s[j] - 'a']++ == 0)
                distinct++;

            while (distinct > k) {
                if (--freq[s[i] - 'a'] == 0)
                    distinct--;
                i++;
            }

            ans += (j - i + 1);
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(26) → O(1)
*/