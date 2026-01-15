// Increasing Triplet Subsequence

#include <vector>
#include <climits>
using namespace std;

/*
Approach 1: Brute Force
- Try all possible triplets (i < j < k)
- Check if v[i] < v[j] < v[k]
Time: O(N^3)
Space: O(1)
*/
class SolutionBruteForce {
public:
    bool increasingTriplet(vector<int>& v) {
        int n = v.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (v[i] < v[j] && v[j] < v[k])
                        return true;
                }
            }
        }

        return false;
    }
};

/*
Approach 2: Greedy (Optimal)
- Track smallest (first) and second smallest (second)
- If we find a number greater than both → triplet exists
Time: O(N)
Space: O(1)
*/
class SolutionOptimal {
public:
    bool increasingTriplet(vector<int>& v) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int x : v) {
            if (x <= first)
                first = x;
            else if (x <= second)
                second = x;
            else
                return true;
        }

        return false;
    }
};