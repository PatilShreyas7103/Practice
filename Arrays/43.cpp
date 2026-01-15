// Gas Station (Circular Tour)

#include <vector>
using namespace std;

/*
Approach 1: Brute Force
- Compute net gain at each station (gas - cost)
- Try starting from every index and simulate a full circle
- If fuel ever becomes negative, that start is invalid
Time: O(N^2)
Space: O(N)
*/
class SolutionBruteForce {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff;

        for (int i = 0; i < n; i++)
            diff.push_back(gas[i] - cost[i]);

        for (int i = 0; i < n; i++)
            diff.push_back(diff[i]);

        for (int i = 0; i < n; i++) {
            int fuel = 0;
            bool ok = true;

            for (int j = i; j < i + n; j++) {
                fuel += diff[j];
                if (fuel < 0) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return i;
        }

        return -1;
    }
};

/*
Approach 2: Greedy (Optimal)
- If total gas < total cost, answer is -1
- Otherwise, reset starting point whenever current fuel < 0
- Greedy guarantee ensures final start index works
Time: O(N)
Space: O(1)
*/
class SolutionOptimal {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if (totalGas < totalCost)
            return -1;

        int curr = 0, start = 0;

        for (int i = 0; i < gas.size(); i++) {
            curr += gas[i] - cost[i];
            if (curr < 0) {
                curr = 0;
                start = i + 1;
            }
        }

        return start;
    }
};