// Celebrity Problem

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force Verification
Time: O(n^2)
Space: O(1)

Idea:
For each person k:
1. Check everyone knows k.
2. Check k knows no one (except self).
If both satisfied, k is the celebrity.
*/
class SolutionBruteForce {
public:
    int celebrity(vector<vector<int>>& v) {
        int n = v.size();

        for (int k = 0; k < n; k++) {
            bool isCelebrity = true;

            // Everyone should know k
            for (int i = 0; i < n; i++) {
                if (i != k && v[i][k] == 0) {
                    isCelebrity = false;
                    break;
                }
            }
            if (!isCelebrity) continue;

            // k should know nobody
            for (int i = 0; i < n; i++) {
                if (i != k && v[k][i] == 1) {
                    isCelebrity = false;
                    break;
                }
            }

            if (isCelebrity) return k;
        }
        return -1;
    }
};

/*
Approach 2: Candidate Elimination (Two Pointer / Stack Logic)
Time: O(n)
Space: O(1)

Idea:
If A knows B, A cannot be a celebrity.
Use this rule to find a single candidate, then verify.
*/
class SolutionOptimal {
public:
    int celebrity(vector<vector<int>>& v) {
        int n = v.size();
        int candidate = 0;

        // Step 1: Find potential celebrity
        for (int i = 1; i < n; i++) {
            if (v[candidate][i] == 1) {
                candidate = i;
            }
        }

        // Step 2: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;

            if (v[candidate][i] == 1 || v[i][candidate] == 0) {
                return -1;
            }
        }
        return candidate;
    }
};