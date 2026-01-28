// Maximum Number of Meetings in One Room

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Pair meetings as (end time, start time).
- Sort meetings by end time.
- Greedily select a meeting if its start time
  is strictly greater than the last selected end time.
*/

class Solution {
public:
    int maxMeetings(vector<int>& st, vector<int>& e) {
        int n = st.size();
        vector<pair<int,int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.push_back({e[i], st[i]});
        }

        sort(meetings.begin(), meetings.end());

        int ans = 0;
        int lastEnd = -1;

        for (auto it : meetings) {
            int endTime = it.first;
            int startTime = it.second;

            if (startTime > lastEnd) {
                ans++;
                lastEnd = endTime;
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/