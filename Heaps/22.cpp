// Reorganize string
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

class Solution1 {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto &[ch, freq] : mp) {
            pq.push({freq, ch});
        }

        string res;
        while (pq.size() >= 2) {
            auto [freq1, char1] = pq.top(); pq.pop();
            auto [freq2, char2] = pq.top(); pq.pop();

            res += char1;
            res += char2;

            if (--freq1 > 0) pq.push({freq1, char1});
            if (--freq2 > 0) pq.push({freq2, char2});
        }

        if (!pq.empty()) {
            auto [freq, ch] = pq.top();
            if (freq > 1) return "";
            res += ch;
        }

        return res;
    }
};

class Solution2 {
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