// Max Non Negative SubArray 
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class BruteForce {
public:
    vector<int> maxNonNegativeSubArray(vector<int> &A) {
        long long bestSum = -1;
        int bestL = 0, bestR = -1;
        int n = A.size();

        for (int i = 0; i < n; i++) {
            if (A[i] < 0) continue;

            long long currSum = 0;
            for (int j = i; j < n && A[j] >= 0; j++) {
                currSum += A[j];

                if (currSum > bestSum ||
                   (currSum == bestSum && (j - i) > (bestR - bestL)) ||
                   (currSum == bestSum && (j - i) == (bestR - bestL) && i < bestL)) {
                    bestSum = currSum;
                    bestL = i;
                    bestR = j;
                }
            }
        }

        if (bestR < bestL) return {};
        return vector<int>(A.begin() + bestL, A.begin() + bestR + 1);
    }
};

// Optimal Approach (Single Scan)
class Optimal {
public:
    vector<int> maxNonNegativeSubArray(vector<int> &A) {
        long long currSum = 0, bestSum = -1;
        int currL = 0, bestL = 0, bestR = -1;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] >= 0) {
                currSum += A[i];

                if (currSum > bestSum ||
                   (currSum == bestSum && (i - currL) > (bestR - bestL)) ||
                   (currSum == bestSum && (i - currL) == (bestR - bestL) && currL < bestL)) {
                    bestSum = currSum;
                    bestL = currL;
                    bestR = i;
                }
            } else {
                currSum = 0;
                currL = i + 1;
            }
        }

        if (bestR < bestL) return {};
        return vector<int>(A.begin() + bestL, A.begin() + bestR + 1);
    }
};