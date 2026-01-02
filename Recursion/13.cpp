// Subset Sums 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Bitmasking
Time: O(2^n * n)
Space: O(1) (excluding output)
*/
class SolutionBitmask {
public:
    vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();
        vector<int> sums;

        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += arr[i];
                }
            }
            sums.push_back(sum);
        }

        sort(sums.begin(), sums.end());
        return sums;
    }
};

/*
Approach 2: Recursion / Backtracking
Time: O(2^n)
Space: O(n) recursion stack
*/
class SolutionRecursive {
public:
    void solve(int idx, int curSum, vector<int>& arr, vector<int>& sums) {
        if (idx == arr.size()) {
            sums.push_back(curSum);
            return;
        }

        // include element
        solve(idx + 1, curSum + arr[idx], arr, sums);

        // exclude element
        solve(idx + 1, curSum, arr, sums);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sums;
        solve(0, 0, arr, sums);
        sort(sums.begin(), sums.end());
        return sums;
    }
};