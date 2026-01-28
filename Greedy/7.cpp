// Average Waiting Time for SJF algo

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Sort the array to minimize waiting time.
- Accumulate sum of previous elements.
- Divide total waiting time by number of jobs.
*/

class Solution {
public:
    long long solve(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());

        long long sum = 0;
        long long totalWait = 0;

        for (int it : v) {
            totalWait += sum;
            sum += it;
        }

        return totalWait / n;   // average waiting time
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/