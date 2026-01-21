// Maximum Points You Can Obtain from Cards
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach : Sliding Window on Middle Segment (Optimal & Expected)
// Idea:
// - Instead of picking k cards, remove (n - k) consecutive cards
// - The remaining cards give maximum score
// - Find the minimum sum subarray of size (n - k)
// - Answer = totalSum - minSubarraySum
class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int windowSize = n - k;

        // Edge case: take all cards
        if (windowSize == 0) {
            return accumulate(v.begin(), v.end(), 0);
        }

        int sum = 0;
        for (int i = 0; i < windowSize; i++)
            sum += v[i];

        int minWindowSum = sum;

        for (int i = windowSize; i < n; i++) {
            sum += v[i];
            sum -= v[i - windowSize];
            minWindowSum = min(minWindowSum, sum);
        }

        int total = accumulate(v.begin(), v.end(), 0);
        return total - minWindowSum;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/