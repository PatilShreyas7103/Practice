// Rearrange characters in a string such that no two adjacent characters are the same. 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

class Solution {
public:
    string rearrangeString(string s) {
        using P = pair<int,char>;
        priority_queue<P> pq;

        unordered_map<char,int> mp;
        for(char ch : s) mp[ch]++;

        for(auto &it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        P prev = {0, '#'};   // previously used character

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            ans += curr.second;
            curr.first--;

            // If previous character still has remaining count, push it back now
            if(prev.first > 0) {
                pq.push(prev);
            }

            // update previous to current
            prev = curr;
        }

        // If rearrangement is not possible
        if(ans.length() != s.length()) return "";

        return ans;
    }
};