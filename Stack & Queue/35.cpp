// Number of Recent Calls

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Vector + Backward Scan
Time: O(n) per ping
Space: O(n)

Idea:
- Store all ping times in a vector.
- For each new ping, scan backwards until time < t - 3000.
*/
class RecentCounterVector {
public:
    vector<int> v;

    RecentCounterVector() {}

    int ping(int t) {
        v.push_back(t);
        int cnt = 0;

        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] >= t - 3000) {
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    }
};

/*
Approach 2: Queue / Sliding Window (Optimal)
Time: O(1) amortized per ping
Space: O(n)

Idea:
- Push current time into queue.
- Remove outdated times (< t - 3000).
- Queue size gives the count.
*/
class RecentCounterQueue {
public:
    queue<int> q;

    RecentCounterQueue() {}

    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};