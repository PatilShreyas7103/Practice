#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>

/**
 * Class implementing the Mathematical/Greedy approach.
 * Time Complexity: O(N) where N is the number of tasks, as it only involves counting frequencies.
 */
class TaskSchedulerMath {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        if (tasks.empty()) {
            return 0;
        }

        // 1. Calculate frequency and find the maximum frequency (x)
        std::vector<int> taskFrequency(26, 0);
        int maxFrequency = 0;

        for (char task : tasks) {
            int frequency = ++taskFrequency[task - 'A'];
            maxFrequency = std::max(maxFrequency, frequency);
        }

        // 2. Count how many tasks share the maximum frequency (s)
        int maxFreqCount = 0;
        for (int freq : taskFrequency) {
            if (freq == maxFrequency) {
                maxFreqCount++;
            }
        }

        // 3. Calculate time based on the cooling constraint
        // Formula: (x - 1) * (n + 1) + s
        long long timeBasedOnMaxFreq = (long long)(maxFrequency - 1) * (n + 1) + maxFreqCount;

        // 4. Result is max(total tasks, constraint time)
        return (int)std::max((long long)tasks.size(), timeBasedOnMaxFreq);
    }
};

// ----------------------------------------------------------------------

/**
 * Class implementing the Priority Queue Simulation approach.
 * Time Complexity: O(N log A) where N is the number of tasks and A is the number of unique task types (max 26).
 */
// Question: Task Scheduler (Heap Approach)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> mp(26, 0);

        for (char i : tasks) {
            mp[i - 'A']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (mp[i]) pq.push(mp[i]);
        }

        int time = 0;
        while (!pq.empty()) {
            vector<int> remain;
            int cycle = n + 1;

            while (cycle && !pq.empty()) {
                int max_freq = pq.top();
                pq.pop();
                if (max_freq > 1) remain.push_back(max_freq - 1);
                ++time;
                --cycle;
            }

            for (int count : remain) {
                pq.push(count);
            }

            if (pq.empty()) break;
            time += cycle;
        }
        return time;
    }
};