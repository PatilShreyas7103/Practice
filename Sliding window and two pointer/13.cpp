// Maximum Average Subarray I
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - For every subarray of size k
// - Compute sum and average
// - Track maximum average
class BruteForce {
public:
    double findMaxAverage(vector<int>& v, int k) {
        int n = v.size();
        double ans = -1e18;

        for (int i = 0; i + k <= n; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += v[j];
            }
            ans = max(ans, (double)sum / k);
        }
        return ans;
    }
};

/*
Time Complexity: O(n * k)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 2: Sliding Window (Optimal & Expected)
// Idea:
// - Maintain sum of window of size k
// - Slide window by removing left element and adding right
// - Update maximum average
class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        int n = v.size();

        double sum = 0;
        for (int i = 0; i < k; i++)
            sum += v[i];

        double ans = sum / k;

        for (int i = k; i < n; i++) {
            sum += v[i];
            sum -= v[i - k];
            ans = max(ans, sum / k);
        }

        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/