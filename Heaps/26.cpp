// Longest Happy String

#include <bits/stdc++.h>
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
    string longestDiverseString(int a, int b, int c) {
        // max-heap of (count, char)
        priority_queue<pair<int,char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans;

        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top(); pq.pop();

            // if last two chars in ans are the same as ch1, we must use the second-best char
            if (ans.size() >= 2 && ans[ans.size()-1] == ch1 && ans[ans.size()-2] == ch1) {
                if (pq.empty()) break; // no alternative -> we are done
                auto [cnt2, ch2] = pq.top(); pq.pop();
                ans.push_back(ch2);
                --cnt2;
                if (cnt2 > 0) pq.push({cnt2, ch2});
                pq.push({cnt1, ch1}); // push ch1 back to try later
            } else {
                // greedy: append up to two of ch1 if available
                if (cnt1 >= 2) {
                    ans.push_back(ch1);
                    ans.push_back(ch1);
                    cnt1 -= 2;
                } else {
                    ans.push_back(ch1);
                    --cnt1;
                }
                if (cnt1 > 0) pq.push({cnt1, ch1});
            }
        }

        return ans;
    }
};