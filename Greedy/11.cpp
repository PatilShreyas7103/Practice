// Meeting Rooms II (Minimum Meeting Rooms)

#include <bits/stdc++.h>
using namespace std;


class Interval {
public:
    int start, end;
    Interval(int s, int e) {
        start = s;
        end = e;
    }
};
/*------------------------------------------------------*/
/*
Approach  (Optimal – Two Pointers):
- Separate start times and end times.
- Sort both arrays.
- If a meeting starts before the previous one ends,
  we need a new room.
*/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& v) {
        int n = v.size();
        vector<int> start, end;

        for (auto it : v) {
            start.push_back(it.start);
            end.push_back(it.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int rooms = 0, maxRooms = 0;
        int i = 0, j = 0;

        while (i < n) {
            if (start[i] < end[j]) {
                rooms++;
                maxRooms = max(maxRooms, rooms);
                i++;
            } else {
                rooms--;
                j++;
            }
        }

        return maxRooms;
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/