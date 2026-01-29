// Meeting Rooms (Can Attend All Meetings)

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Sort meetings by end time.
- If any meeting starts before the previous one ends,
  overlapping exists → return false.
*/

// Definition of Interval
class Interval {
public:
    int start, end;
    Interval(int s, int e) {
        start = s;
        end = e;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& v) {
        vector<pair<int,int>> meetings;

        for (auto it : v) {
            meetings.push_back({it.end, it.start});
        }

        sort(meetings.begin(), meetings.end());

        int lastEnd = -1;

        for (auto it : meetings) {
            int start = it.second;
            int end = it.first;

            if (start < lastEnd) {
                return false;
            }
            lastEnd = end;
        }

        return true;
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/