// Longest Substring Without Repeating Characters

#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
Approach 1: Brute Force + Hash Set
- Start substring from every index
- Extend until a duplicate character is found
- Track maximum length
Time: O(N^2)
Space: O(N)
*/
class SolutionBruteForce {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            int len = 0;

            for (int j = i; j < n; j++) {
                if (st.count(s[j]) == 0) {
                    st.insert(s[j]);
                    len++;
                    ans = max(ans, len);
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};

/*
Approach 2: Sliding Window + Hash Map (Optimal)
- Maintain last seen index of characters
- Use sliding window with a moving left boundary
- Ensure no repeating characters in window
Time: O(N)
Space: O(N)
*/
class SolutionOptimal {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int last = -1;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                last = max(last, mp[s[i]]);
            }
            ans = max(ans, i - last);
            mp[s[i]] = i;
        }

        return ans;
    }
};