// Roman to Integer

#include <string>
#include <map>
using namespace std;

/*
Approach: Compare current and next symbol
- If current value < next value → subtract
- Else → add
- Add last character at the end
Time: O(N)
Space: O(1)
*/
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n - 1; i++) {
            if (mp[s[i]] < mp[s[i + 1]])
                ans -= mp[s[i]];
            else
                ans += mp[s[i]];
        }

        return ans + mp[s[n - 1]];
    }
};