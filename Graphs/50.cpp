// Minimum Genetic Mutation - BFS (LeetCode)
 
 
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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> valid(bank.begin(), bank.end());
        if (!valid.count(end)) return -1;       // can't reach end if it's not in the bank

        const string genes = "ACGT";
        queue<string> q;
        q.push(start);
        int steps = 0;

        // visited via removing from set when enqueued
        if (valid.count(start)) valid.erase(start);

        while (!q.empty()) {
            int sz = q.size();
            for (int curLevel = 0; curLevel < sz; ++curLevel) {
                string cur = q.front(); q.pop();
                if (cur == end) return steps;

                for (int i = 0; i < (int)cur.size(); ++i) {
                    char orig = cur[i];
                    for (char g : genes) {
                        if (g == orig) continue;
                        cur[i] = g;
                        if (valid.count(cur)) {
                            q.push(cur);
                            valid.erase(cur); // mark visited
                        }
                    }
                    cur[i] = orig;
                }
            }
            ++steps;
        }

        return -1;
    }
};