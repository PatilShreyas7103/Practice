// Single-Threaded CPU

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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        // convert to (enqueueTime, (processingTime, index)) and sort by enqueueTime
        vector<pair<int,pair<int,int>>> p;
        p.reserve(n);
        for (int i = 0; i < n; ++i)
            p.push_back({tasks[i][0], {tasks[i][1], i}});
        sort(p.begin(), p.end());

        // min-heap: (processingTime, (index, enqueueTime)) so tie-breaking follows requirements
        using P = pair<int, pair<int,int>>;
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> ans;
        ans.reserve(n);

        long long time = 0;   // current time (use long long to be safe with sums)
        int id = 0;           // pointer into sorted p

        while ((int)ans.size() < n) {
            // push all tasks that have arrived by 'time'
            while (id < n && p[id].first <= time) {
                pq.push({p[id].second.first, {p[id].second.second, p[id].first}});
                ++id;
            }

            if (pq.empty()) {
                // no available task: advance time to next task's arrival (avoid popping empty pq)
                time = p[id].first;

                continue;
            }

            // safe to pop because we checked pq is not empty
            auto cur = pq.top(); pq.pop();
            int dur = cur.first;
            int index = cur.second.first;

            ans.push_back(index);
            time += dur;
        }

        return ans;
    }
};