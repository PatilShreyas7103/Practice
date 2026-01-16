// Group Anagrams

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Approach: Sorting as Key
- Sort each word to create a canonical form
- Use it as key in hash map
Time: O(N * K log K)
Space: O(N * K)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto &x : strs) {
            string key = x;
            sort(key.begin(), key.end());
            mp[key].push_back(x);
        }

        vector<vector<string>> ans;
        for (auto &it : mp)
            ans.push_back(it.second);

        return ans;
    }
};