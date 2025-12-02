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
class TaskSchedulerPQ {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        if (tasks.empty()) {
            return 0;
        }

        // 1. Calculate frequency
        std::map<char, int> taskCounts;
        for (char task : tasks) {
            taskCounts[task]++;
        }

        // 2. Build a Max Heap (Priority Queue) of task frequencies
        std::priority_queue<int> maxHeap;
        for (auto const& [task, count] : taskCounts) {
            maxHeap.push(count);
        }

        int time = 0;

        // 3. Simulate the CPU scheduling cycle
        while (!maxHeap.empty()) {
            
            std::vector<int> executedTasks;
            
            // Execute tasks for one cycle of length (n + 1)
            for (int i = 0; i <= n; ++i) {
                if (maxHeap.empty()) {
                    break;
                }

                int count = maxHeap.top();
                maxHeap.pop();

                // Store reduced frequency for re-insertion
                if (count > 1) {
                    executedTasks.push_back(count - 1);
                }
                
                time++;
            }

            // 4. Re-add tasks after cooldown
            for (int count : executedTasks) {
                maxHeap.push(count);
            }
        }

        return time;
    }
};