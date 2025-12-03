// Maximum Number of Events That Can Be Attended

#include <bits/stdc++.h>
using namespace std;
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

class SolutionPriorityQueue {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> endTimes;
        int eventIndex = 0;
        int currentDay = 0;
        int attendedEvents = 0;
        int totalEvents = events.size();
        
        while (!endTimes.empty() || eventIndex < totalEvents) {
            if (endTimes.empty()) {
                currentDay = events[eventIndex][0];
            }
            
            while (eventIndex < totalEvents && events[eventIndex][0] <= currentDay) {
                endTimes.push(events[eventIndex][1]);
                eventIndex++;
            }
            
            endTimes.pop();
            attendedEvents++;
            currentDay++;
            
            while (!endTimes.empty() && endTimes.top() < currentDay) {
                endTimes.pop();
            }
        }
        
        return attendedEvents;
    }
};

